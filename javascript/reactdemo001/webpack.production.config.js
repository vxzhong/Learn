var path = require('path');
var webpack = require('webpack');
// var node_modules_dir = path.resolve(__dirname, 'node_modules');

module.exports = {
  entry: [
    path.resolve(__dirname, 'app')
  ],
  output: {
    path: path.resolve(__dirname, 'dist'),
    filename: 'app.js'
  },
  module: {
    loaders: [{
      test: /\.css$/,
      loader: 'style!css'
    }, {
      test: /\.jsx?$/,
      loaders: ['babel'],
      include: path.resolve(__dirname, 'app')
    }, {
      test: /\.(png|jpg)$/,
      loader: 'url?limit=25000'
    }]
  },
  plugins: [
    // new webpack.optimize.CommonsChunkPlugin('vendors', 'vendors.js'),
    new webpack.optimize.UglifyJsPlugin()
  ]
};
