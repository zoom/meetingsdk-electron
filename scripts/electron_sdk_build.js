const { execSync } = require('child_process')

const prodEnv = { ...process.env, NODE_ENV: 'production' }

execSync('node scripts/utils/check_node_modules_installed.js', {stdio: [0, 1, 2]})
execSync('node scripts/utils/check_node_builded.js', {stdio: [0, 1, 2]})

// Build main process
const buildArgs = process.argv.slice(2)
execSync(`webpack --config webpack.main.config.js ${buildArgs.join(' ')}`, {stdio: [0, 1, 2], env: prodEnv})

// Build renderer process
execSync(`webpack --config webpack.renderer.config.js ${buildArgs.join(' ')}`, {stdio: [0, 1, 2], env: prodEnv})

// Build with electron-builder
execSync('electron-builder --config electron-builder.config.js', {stdio: [0, 1, 2], env: prodEnv})
