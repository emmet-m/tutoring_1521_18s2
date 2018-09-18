const express = require('express');
const app = express();

var port = 8080;

app.get('/', (req, res) => {
    res.status(200).send("Good meme\n");
});

app.listen(port, () => console.log('listening on http://localhost:' + port + '/ ...'));
