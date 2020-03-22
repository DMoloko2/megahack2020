var express = require('express');
var router = express.Router();
var MySql = require('../db');
MySql.connection();


/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});
router.post('/getvalue',function(req,res) {
let sql = `UPDATE progdb.temp SET porog = ${req.body.value} WHERE type = ${req.body.par} AND param = ${req.body.dat}`
  MySql.get().query(sql, function (err, result) {
console.log(err);
  res.send('Параметры изменены')

  //global.ws.send("Ты пидор")
  })
  MySql.get().query("SELECT * FROM progdb.temp", function (err, result) {
  let data = new  PorogValue()
  for (j in data) {
  let k = 0;
    for (let  i = 0; i < data[j].length; i++) {
        data[j][i] = result[i + k]
    }
  k++;
  }
  global.porogValue = data
  })
})
module.exports = router;
