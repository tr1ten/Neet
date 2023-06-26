const {merge} = require('webpack-merge');
const config = require('./webpack.config.js');
const webpack = require('webpack');
module.exports = merge(config, {
    mode: 'development',
    devtool: 'inline-source-map',
    plugins: [
        new webpack.DefinePlugin({
            'BASE_URL': JSON.stringify('./templates/')
        })
    ]

});