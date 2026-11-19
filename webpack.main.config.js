const path = require('path')
const webpack = require('webpack')
const { resolve, isProduction, enableProductionSourceMap, nodeEnv, makeNativeNodeLoaderOptions } = require('./webpack.shared')

module.exports = {
  mode: isProduction ? 'production' : 'development',
  entry: './src/background.ts',
  target: 'electron-main',
  output: {
    path: path.resolve(__dirname, 'dist_electron/main'),
    filename: 'index.js',
    // Avoid OpenSSL legacy md4/hash issues by using sha256 explicitly.
    hashFunction: 'sha256'
  },
  resolve: {
    extensions: ['.ts', '.js', '.json'],
    alias: {
      '@': resolve('src')
    }
  },
  module: {
    rules: [
      {
        test: /\.ts$/,
        loader: 'ts-loader',
        options: {
          transpileOnly: true,
          ignoreDiagnostics: [7016] // Ignore "Could not find a declaration file" errors
        },
        exclude: /node_modules/
      },
      {
        test: /\.node$/,
        loader: 'native-ext-loader',
        options: makeNativeNodeLoaderOptions('../../../app/')
      }
    ]
  },
  plugins: [
    new webpack.DefinePlugin({
      // Inject build-time NODE_ENV into the bundle for runtime checks / dead-code elimination.
      'process.env.NODE_ENV': JSON.stringify(nodeEnv)
    })
  ],
  node: {
    __dirname: false,
    __filename: false
  },
  devtool: isProduction ? (enableProductionSourceMap ? 'inline-source-map' : undefined) : 'source-map',
  externals: ['@electron/remote']
}
