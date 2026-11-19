const path = require('path')

// Shared configuration for webpack configs
const { platform, arch } = process

const sdkPathMap = {
  'darwin:x64': './sdk/mac',
  'darwin:arm64': './sdk/mac',
  'win32:ia32': './sdk/win32',
  'win32:x64': './sdk/win64'
}
const sdkKey = `${platform}:${arch}`
const sdkPath = sdkPathMap[sdkKey]
if (!sdkPath) {
  throw new Error(`[webpack.shared] Unsupported platform/arch: ${sdkKey}`)
}

function resolve(dir) {
  return path.join(__dirname, dir)
}

const isProduction = process.env.NODE_ENV === 'production'
const enableProductionSourceMap = process.argv.includes('sourceMap')
const needRewritePath = process.argv.includes('rewritePath')
const nodeEnv = process.env.NODE_ENV || (isProduction ? 'production' : 'development')

function makeNativeNodeLoaderOptions (productionBasePath) {
  // Packaged apps: native .node are copied by electron-builder into Contents/Resources/app/*.node
  // This path is resolved relative to __dirname of the bundled JS at runtime.
  return isProduction && !needRewritePath
    ? { emit: false, basePath: [productionBasePath] }
    : { emit: false, rewritePath: resolve(sdkPath) }
}

module.exports = {
  platform,
  arch,
  sdkPath,
  resolve,
  isProduction,
  enableProductionSourceMap,
  nodeEnv,
  makeNativeNodeLoaderOptions
}
