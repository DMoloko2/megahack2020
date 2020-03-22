const WebSocket = require('ws');
clickhouse = require('./clickhouseReq')
const ws = new WebSocket('ws://172.20.10.2:1796');

ws.on('open', function open() {
clickhouseReq.getDateRealTime()
  ws.send('something');
});

ws.on('message', function incoming(data) {
  console.log(data);
});
