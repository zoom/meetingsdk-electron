const { execSync, spawn, spawnSync } = require('child_process')
const path = require('path')

const { resolvePort, waitForHttpOk } = require('./utils/dev_server_port')

function safeKill(child) {
  if (!child || child.killed) return
  try {
    child.kill()
  } catch (_) {
    // ignore
  }
}

async function main() {
  const port = await resolvePort(process.env.PORT)

  const devEnv = {
    ...process.env,
    PORT: String(port),
    NODE_ENV: 'development'
  }

  // Run checks
  execSync('node scripts/utils/check_node_modules_installed.js', {stdio: 'inherit', env: devEnv})
  execSync('node scripts/utils/check_node_builded.js', {stdio: 'inherit', env: devEnv})

  // Build main process once
  execSync('webpack --config webpack.main.config.js', {stdio: 'inherit', env: devEnv})

  const rendererProcess = spawn('webpack', ['serve', '--config', 'webpack.renderer.config.js'], {
    stdio: 'inherit',
    env: devEnv,
    shell: true
  })

  let electronProcess = null

  function cleanup() {
    safeKill(rendererProcess)
    safeKill(electronProcess)
  }

  function exit(code = 0) {
    cleanup()
    process.exit(code)
  }

  process.once('SIGTERM', () => exit(0))
  process.once('SIGINT', () => exit(0))

  // If renderer dies before Electron starts, fail fast.
  rendererProcess.once('exit', (code, signal) => {
    if (electronProcess) return
    console.error(`[electron] Dev server process exited (${signal || code})`)
    exit(typeof code === 'number' ? code : 1)
  })

  function startElectron() {
    if (electronProcess) return
    execSync('node node_modules/electron/install.js', {stdio: 'inherit'})
    if (process.platform === 'darwin') {
      const plugins = path.resolve(__dirname, '../sdk/mac/Plugins')
      const sdk = path.resolve(__dirname, '../sdk/mac/ZoomSDK')
      const contents = path.resolve(__dirname, '../node_modules/electron/dist/Electron.app/Contents')
      const fw = path.join(contents, 'Frameworks')
      spawnSync('xattr', ['-dr', 'com.apple.quarantine', plugins], { stdio: 'ignore' })
      spawnSync('xattr', ['-dr', 'com.apple.quarantine', sdk], { stdio: 'ignore' })
      execSync(`cp -Rf ${plugins}/* ${contents}`, {stdio: 'inherit'})
      execSync(`cp -Rf ${sdk}/* ${fw}`, {stdio: 'inherit'})
    }
    console.log('[electron] Starting Electron...')
    electronProcess = spawn('electron', [path.join(__dirname, '../dist_electron/main/index.js')], {
      stdio: 'inherit',
      env: devEnv,
      shell: true
    })

    electronProcess.once('exit', (code) => {
      exit(typeof code === 'number' ? code : 0)
    })
  }

  waitForHttpOk(`http://localhost:${port}`).then(startElectron, (err) => {
    console.error('[electron] Dev server failed to start:', err)
    exit(1)
  })
}

main().catch((error) => {
  console.error('[electron] Failed to start dev server:', error)
  process.exit(1)
})
