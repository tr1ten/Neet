const {merge} = require('webpack-merge');
const config = require('./webpack.config.js');
const webpack = require('webpack');
module.exports = merge(config, {
    mode: 'production',
    plugins: [
        new webpack.DefinePlugin({
            'BASE_URL': JSON.stringify('https://raw.githubusercontent.com/tr1ten/Neet/master/public/templates/')
        })
    ]
});