const express = require('express');
const fs = require('fs');

const app = express();
const PORT = 3000;

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

app.get('/lastrow', (req, res) => {
  fs.readFile('incendio.txt', 'utf8', (err, data) => {
    if (err) {
      console.error(err);
      return res.status(500).send('Error reading file');
    }
    const lines = data.trim().split('\n');
    const lastRow = lines[lines.length - 1];
    res.send(lastRow);
});
});
