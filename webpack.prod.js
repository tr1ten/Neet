const { merge } = require("webpack-merge");
const config = require("./webpack.config.js");
const CopyPlugin = require("copy-webpack-plugin");
const webpack = require("webpack");
module.exports = merge(config, {
  mode: "production",
  plugins: [
    new webpack.DefinePlugin({
      BASE_URL: JSON.stringify(
        "https://gitlab.com/neet3/Neet/-/raw/master/public/templates/"
      ),
    }),
    new CopyPlugin({
      patterns: [
          // everything in public folder except /templates
        {
            from: "public",
            globOptions: {
                ignore: [
                    "**/templates/**"
                ]
            }
        },
      ],
    }),
  ],
});
