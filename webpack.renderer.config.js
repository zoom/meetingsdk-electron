const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const MiniCssExtractPlugin = require('mini-css-extract-plugin')
const { VueLoaderPlugin } = require('vue-loader')
const TerserPlugin = require('terser-webpack-plugin')
const webpack = require('webpack')
const { resolve, isProduction, enableProductionSourceMap, nodeEnv, makeNativeNodeLoaderOptions } = require('./webpack.shared')

module.exports = {
  mode: isProduction ? 'production' : 'development',
  entry: './src/main.ts',
  target: 'electron-renderer',
  output: {
    path: path.resolve(__dirname, 'dist_electron/renderer'),
    filename: isProduction ? 'js/[name].[contenthash].js' : 'js/[name].js',
    publicPath: isProduction ? './' : '/',
    // Avoid OpenSSL legacy md4/hash issues by using sha256 explicitly.
    hashFunction: 'sha256',
    clean: true
  },
  resolve: {
    extensions: ['.ts', '.js', '.vue', '.json'],
    alias: {
      '@': resolve('src'),
      '@scss': resolve('src/assets/style'),
      'path': require.resolve('path-browserify')
    }
  },
  module: {
    rules: [
      {
        test: /\.vue$/,
        loader: 'vue-loader'
      },
      {
        test: /\.ts$/,
        loader: 'ts-loader',
        options: {
          appendTsSuffixTo: [/\.vue$/],
          transpileOnly: true,
          ignoreDiagnostics: [7016] // Ignore "Could not find a declaration file" errors
        },
        exclude: /node_modules/
      },
      {
        test: /\.css$/,
        use: [
          isProduction ? MiniCssExtractPlugin.loader : 'style-loader',
          'css-loader'
        ]
      },
      {
        test: /\.scss$/,
        use: [
          isProduction ? MiniCssExtractPlugin.loader : 'style-loader',
          'css-loader',
          {
            loader: 'sass-loader',
            options: {
              sassOptions: {
                silenceDeprecations: ['import']
              },
              additionalData: (content, loaderContext) => {
                // Keep global styles available for every scss module (e.g. CSS vars / base rules),
                // and avoid self-import recursion for index.scss itself.
                if (loaderContext.resourcePath.includes('index.scss')) {
                  return content
                }
                return `@import "@/assets/style/index.scss";\n${content}`
              }
            }
          }
        ]
      },
      {
        test: /\.(png|jpe?g|gif|svg|ico)(\?.*)?$/,
        type: 'asset/resource',
        generator: {
          filename: 'img/[name].[hash:8][ext]'
        }
      },
      {
        test: /\.(woff2?|eot|ttf|otf)(\?.*)?$/,
        type: 'asset/resource',
        generator: {
          filename: 'fonts/[name].[hash:8][ext]'
        }
      },
      {
        test: /\.node$/,
        loader: 'native-ext-loader',
        options: makeNativeNodeLoaderOptions('../../app/')
      }
    ]
  },
  plugins: [
    new VueLoaderPlugin(),
    new HtmlWebpackPlugin({
      template: './public/index.html',
      filename: 'index.html',
      title: 'zoom-meeting-sdk'
    }),
    new webpack.DefinePlugin({
      'process.env.NODE_ENV': JSON.stringify(nodeEnv),
      __VUE_OPTIONS_API__: 'true',
      __VUE_PROD_DEVTOOLS__: 'false'
    }),
    ...(isProduction ? [
      new MiniCssExtractPlugin({
        filename: 'css/[name].[contenthash].css',
        ignoreOrder: true
      })
    ] : [])
  ],
  optimization: {
    minimize: isProduction,
    minimizer: isProduction ? [
      new TerserPlugin({
        terserOptions: {
          compress: {
            drop_debugger: true
          },
          format: {
            comments: false
          }
        }
      })
    ] : [],
    splitChunks: isProduction ? {
      chunks: 'all',
      cacheGroups: {
        vendor: {
          test: /[\\/]node_modules[\\/]/,
          name: 'vendors',
          chunks: 'all'
        }
      }
    } : false
  },
  devtool: isProduction ? (enableProductionSourceMap ? 'inline-source-map' : undefined) : 'source-map',
  infrastructureLogging: {
    level: 'info'
  },
  stats: {
    colors: true,
    modules: false,
    children: false,
    chunks: false,
    chunkModules: false,
    entrypoints: false,
    warnings: true,
    errors: true,
    errorDetails: true,
    logging: 'info',
    loggingTrace: false
  },
  devServer: {
    compress: false,
    host: '0.0.0.0',
    port: process.env.PORT || 5173,
    open: false,
    hot: true,
    historyApiFallback: true,
    client: {
      logging: 'info',
      overlay: {
        errors: true,
        warnings: false
      },
      progress: true
    },
    devMiddleware: {
      stats: {
        colors: true,
        modules: false,
        chunks: false,
        chunkModules: false,
        entrypoints: false,
        warnings: true,
        errors: true,
        errorDetails: true,
        logging: 'info'
      }
    }
  }
}
