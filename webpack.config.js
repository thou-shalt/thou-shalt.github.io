const CompressionPlugin = require('compression-webpack-plugin');
module.exports = {
    entry: './src/main.js',
    output: {
        filename: 'bundle.js',
        path: __dirname,
    },
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /(node_modules)/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ['env']
                    }
                }
            }
        ]
    },
    devServer: {
        contentBase: __dirname,
        compress: true,
        port: 9000
    },
    externals: {
        Test: 'Test_Module',
        osc: 'osc',
    },
    node: {
        dgram: 'empty'
    },
    plugins: [
        new CompressionPlugin({
            // filename: '[path].br[query]',
            // algorithm: 'brotliCompress',
            test: /\.(js|css|html|svg)$/,
            compressionOptions: { level: 9 },
            threshold: 10240,
            minRatio: 0.8,
            deleteOriginalAssets: false,
        }),
    ],
};
