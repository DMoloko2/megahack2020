const WebSocket = require('ws');

const ws = new WebSocket('ws://172.20.10.2:1796');

ws.on('open', function open() {
  ws.send('something');
});

ws.on('message', function incoming(data) {
  console.log(data);
});
