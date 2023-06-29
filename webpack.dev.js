const {merge} = require('webpack-merge');
const config = require('./webpack.config.js');
const CopyPlugin = require("copy-webpack-plugin");

const webpack = require('webpack');
module.exports = merge(config, {
    mode: 'development',
    devtool: 'inline-source-map',
    plugins: [
        new webpack.DefinePlugin({
            'BASE_URL': JSON.stringify('./templates/')
        }),
        new CopyPlugin({
            patterns: [
              { from: "public", },
            ],
          }),
    ]

});