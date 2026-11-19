const fs = require('fs')
const { execSync } = require('child_process')
const { platform, arch } = process

const { sdkPath } = require('../../webpack.shared')
if (!sdkPath) {
  throw new Error(`[check_node_builded] Unsupported platform/arch: ${platform}:${arch}`)
}
const existsNodeFiles = fs.existsSync(`${sdkPath}/zoomsdk.node`) && fs.existsSync(`${sdkPath}/zoomsdk_render.node`) && fs.existsSync(`${sdkPath}/zoomsdk_napi_util.node`)
console.log('node files exist', existsNodeFiles)
if (!existsNodeFiles) {
  console.log('rebuilding .node files...')
  execSync('node scripts/electron_sdk_buildNode.js', {stdio: [0, 1, 2]})
}