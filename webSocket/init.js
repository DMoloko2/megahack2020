var MySql = require('./db');
class PorogValue {
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

MySql.connection();
exports.getPorogValue = function (cb) {
  MySql.get().query("SELECT * FROM progdb.temp", function (err, result) {
  let data = new  PorogValue()
  let k = 0;
  for (j in data) {

    for (let  i = 0; i < data[j].length; i++) {
        data[j][i] = result[i + k * data[j].length]
    }
  k++;
  }
  cb(data)
  })
}
