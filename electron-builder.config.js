const { platform, arch, sdkPath } = require('./webpack.shared')

const date = new Date()
const month = date.getMonth() < 9 ? '0' + (date.getMonth() + 1) : date.getMonth() + 1
const day = date.getDate() < 10 ? '0' + date.getDate() : date.getDate()

module.exports = {
  appId: 'meeting.sdk.zoom',
  productName: 'zoom-meeting-sdk',
  compression: 'maximum',
  artifactName: "${productName}_Setup_${version}.${copyright}.${ext}",
  copyright: `${month}${day}`,
  icon: `./src/assets/images/${platform}.${platform === 'win32' ? 'ico' : 'png'}`,
  asar: true,
  // Native addons are shipped via extraResources (outside app.asar).
  directories: {
    output: 'dist_electron/dist'
  },
  files: [
    'dist_electron/**/*',
    '!dist_electron/dist/**',
    'lib/**/*',
    // SDK payload is shipped via extraResources (see below).
    'package.json',
  ],
  extraMetadata: {
    main: 'dist_electron/main/index.js'
  },
  extraResources: [
    ...(platform === 'darwin' ? [
      {
        from: './sdk/mac/ZoomSDK/',
        to: '../Frameworks/'
      },
      {
        from: './sdk/mac/',
        to: './app/',
        filter: ["*.node"]
      }
    ] : [
      {
        from: sdkPath,
        to: './app/'
      }
    ])
  ],
  mac: {
    target: [
      {
        target: 'zip',
        arch: [arch]
      }
    ],
    extendInfo: {
      NSMicrophoneUsageDescription: "Please allow this program to access your microphone",
      NSCameraUsageDescription: "Please allow this program to access your camera"
    }
  },
  win: {
    signExts: ['!zcscpthost.exe'],
    target: [
      {
        target: 'nsis',
        arch: [arch]
      }
    ]
  },
  nsis: {
    oneClick: false,
    allowElevation: true,
    allowToChangeInstallationDirectory: true,
    installerIcon: `./src/assets/images/${platform}.ico`,
    uninstallerIcon: `./src/assets/images/${platform}.ico`,
    installerHeaderIcon: `./src/assets/images/${platform}.ico`,
    createDesktopShortcut: true,
    createStartMenuShortcut: true,
    deleteAppDataOnUninstall: true,
    include: 'scripts/installer.nsh'
  }
}