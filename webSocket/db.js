const Mysql = require('mysql');
var MysqlClient = Mysql.createConnection({
host     : 'localhost',
user     : 'root',
password : '0000',
database : 'progdb'})
exports.connection= function () {

  var MysqlClient = Mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : '0000',
    database : 'progdb'
});

return  MysqlClient.connect();
}
exports.get = function () {


  return MysqlClient;
}
exports.options = {
  host     : 'localhost',
  user     : 'root',
  password : '0000',
  database : 'progdb'
};
