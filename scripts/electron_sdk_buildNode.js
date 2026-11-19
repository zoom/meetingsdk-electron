const { execSync } = require('child_process')
const { platform, arch } = process
let electronPackage
let electronVersion

execSync('node scripts/utils/check_node_modules_installed.js', {stdio: [0, 1, 2]})

try {
  execSync(`${platform === 'win32' ? 'python' : 'python3'} --version`, {stdio: [0, 1, 2]})
} catch (error) {
  console.log('you have not installed python')
}

try {
  console.log('checking electron version...')
  electronPackage = execSync('npm ls electron').toString()
} catch (error) {
  console.log('you have not installed electron')
}

if (electronPackage) {
  var packageList = electronPackage.split('@')
  electronVersion = packageList[packageList.length - 1].trim()
  console.log('electron version is', electronVersion)
  try {
    const nodeGypExtra = platform === 'win32' ? ' --release --msvs_version=2019' : ''
    execSync(`node-gyp rebuild --target=${electronVersion} --arch=${arch} --dist-url=https://electronjs.org/headers${nodeGypExtra}`, {stdio: [0, 1, 2]})
    // binding.gyp copy_binary / product_dir places .node under sdk/mac, sdk/win32, or sdk/win64.
  } catch (error) {
    console.error('rebuild .node files failed, please refer to README.md')
    console.error(error)
    process.exit(1)
  }
}