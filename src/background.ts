import { app, protocol, BrowserWindow, ipcMain } from 'electron'
import * as path from 'path'
const { platform, arch } = process
const { ZoomSDK } = require('../lib/zoom_sdk.js');
const isDevelopment = process.env.NODE_ENV !== 'production'
const remote = require('@electron/remote/main')
remote.initialize()

const zoomSdk = ZoomSDK.getInstance();
(app as any).zoomSdk = zoomSdk;
(app as any).platform = platform;
(app as any).arch = arch;
let win: BrowserWindow

function createProtocol () {
  protocol.registerFileProtocol('app', (request, callback) => {
    try {
      const rendererRoot = path.join(__dirname, '../renderer')

      // Strip scheme + query/hash.
      let rel = request.url.startsWith('app://') ? request.url.slice('app://'.length) : request.url
      rel = rel.split(/[?#]/, 1)[0]

      // Normalize possible leading slashes like "./", "/" (support app://./index.html).
      rel = rel.replace(/^(\.\/)+/, '')
      rel = rel.replace(/^\/+/, '')

      // Default document.
      if (!rel) rel = 'index.html'

      const decoded = decodeURIComponent(rel)
      const normalized = path.normalize(decoded)

      // Prevent traversal / absolute paths.
      if (normalized.startsWith('..') || path.isAbsolute(normalized)) {
        callback({ error: -6 }) // FILE_NOT_FOUND
        return
      }

      const rootResolved = path.resolve(rendererRoot)
      const fullPath = path.resolve(rendererRoot, normalized)
      if (fullPath !== rootResolved && !fullPath.startsWith(rootResolved + path.sep)) {
        callback({ error: -6 }) // FILE_NOT_FOUND
        return
      }

      callback({ path: fullPath })
    } catch (error) {
      console.error('Protocol error:', error, 'URL:', request.url)
      callback({ error: -6 }) // FILE_NOT_FOUND
    }
  })
}

let protocolRegistered = false
function ensureProtocol () {
  if (protocolRegistered) return
  createProtocol()
  protocolRegistered = true
}

// Scheme must be registered before the app is ready
try {
  protocol.registerSchemesAsPrivileged([{ scheme: 'app', privileges: { secure: true, standard: true } }]) 
} catch (error) {
  console.error('Failed to register app protocol:', error)
  // Consider throwing or handling the error more appropriately
}

if (platform === 'win32') {
  app.disableHardwareAcceleration()
  let gotTheLock = app.requestSingleInstanceLock()
  if (!gotTheLock) {
    app.quit()
  } else {
    app.on('second-instance', (event, commandLine, workingDirectory) => {
      // Someone tried to run a second instance, we should focus our window.
      if (win) {
        if (win.isMinimized()) win.restore()
        win.focus()
      }
    })
  }
}

async function createWindow() {
  win = new BrowserWindow({
    width: 800,
    height: 700,
    minWidth: 600,
    minHeight: 750,
    center: true,
    hasShadow: true,
    webPreferences: {
      nodeIntegration: true,
      contextIsolation: false
    }
  })
  
  if (isDevelopment) {
    // Load the url of the dev server if in development mode (PORT is set by serve script)
    const port = process.env.PORT || 5173
    await win.loadURL(`http://localhost:${port}`)
    if (!process.env.IS_TEST) win.webContents.openDevTools()
  } else {
    ensureProtocol()
    // Load the index.html when not in development
    win.loadURL('app://./index.html')
  }

  win.on('ready-to-show', () => {
    console.log('ready-to-show')
    win.show()
  })

  win.on('close', () => { 
    let zoomSdkModule = (app as any).zoomSdkModule
    if (zoomSdkModule) {
      zoomSdkModule.Meeting.LeaveMeeting()
    }
  })
}

(global as any).platform = platform

ipcMain.on('auth-success', (event, arg) => {
  (app as any).zoomSdkModule = { Auth: zoomSdk.GetAuth(), Meeting: zoomSdk.GetMeeting(), Setting: zoomSdk.GetSetting() }
})

app.on('will-quit', () => {
  zoomSdk.CleanUPSDK();
  app.quit()
})

app.on('activate', () => {
  if (BrowserWindow.getAllWindows().length === 0) createWindow()
})

app.on('ready', async () => {
  if (!isDevelopment) {
    ensureProtocol()
  }
  createWindow()
})

app.on("browser-window-created", (e, win) => {
  win.center()
});

app.on("web-contents-created", (e, webContents) => {
  remote.enable(webContents);
});

if (isDevelopment) {
  if (process.platform === 'win32') {
    process.on('message', (data) => {
      if (data === 'graceful-exit') {
        app.quit()
      }
    })
  } else {
    process.on('SIGTERM', () => {
      app.quit()
    })
  }
}
