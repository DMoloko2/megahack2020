const { ClickHouse } = require('clickhouse');
class DataSender {
constructor(){
  this.pressure = new Array (12);
  this.humidity =  new Array (12);
  this.room_temperature =  new Array (12);
  this.temperature_working_area = new Array (12);
  this.ph = new Array (12);
  this.weight =  new Array (12);
  this.flow_rate = new Array (12);
  this.CO2 =  new Array (12);
}

}
let typee = ["pressure","humidity","room_temperature","temperature_working_area","ph","weight","flow_rate","CO2"]
const clickhouse = new ClickHouse({
    url: 'http://localhost',
    port: 8123,
    debug: false,
    basicAuth: {
      username: 'default',
      password: '0000',
      },
    isUseGzip: false,
    format: "json", // "json" || "csv" || "tsv"
    config: {
        session_id                              : 'session_id if neeed',
        session_timeout                         : 60,
        output_format_json_quote_64bit_integers : 0,
        enable_http_compression                 : 0,
        database                                : 'my_database_name',
    },
});
exports.getDateRealTime = function () {
  var  i = 0
  let dataSender = new DataSender()
  clickhouse.query(`SELECT toUnixTimestamp(timestamp) AS unix_timestamp, typee, param, value, prev FROM test.opc`).stream()
  .on('data', function(data) {
      const stream = this;
      // console.log(data);
      dataSender[typee[data.typee]][data.param] = {y: data.value, t: data.unix_timestamp}
      let val = validation(dataSender)
        if(data.typee  ==  0){
          if (val) {
            global.wss.clients.forEach(function each(client) {
              if (client.readyState === global.WebSocket.OPEN) {
                console.log(dataSender);
                let mes = JSON.stringify(dataSender)
                client.send(mes);
                            dataSender = new DataSender()
              }
            });
            stream.pause();
            setTimeout(() => {
                stream.resume();
            }, 1000);
          }
}

  })
      .on('error', err => {
          console.log(err);
      })
      .on('end', () => {

      });
}
exports.getPreviousValue = function (dateLow,dateHigh,cb) {
  clickhouse.query(query).exec(function (err, rows) {
        cb(rows)
});
}
function validation(data) {
  let d = 0;
  // for (j in data) {
    for (var i = 0; i < data.pressure.length; i++) {
      if(data.pressure[i] === undefined){
        return false
      }
      else {
        d++
      }
    }
  // }
console.log(d);
if (d == 12){
console.log('true');
return true
}
}
