var express = require('express');
var router = express.Router();
var MySql = require('../db');
MySql.connection();


/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});
router.post('/getvalue',function(req,res) {
  let sql = `INSERT INTO temp (param, porog, type)VALUES(${req.body.dat},${req.body.value},${req.body.par})`
  MySql.get().query(sql, function (err, result) {
console.log(err);
  res.send('Параметры изменены')
  //global.ws.send("Ты пидор")
  })
})
module.exports = router;
