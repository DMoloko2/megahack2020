const { ClickHouse } = require('clickhouse');
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

    // This object merge with request params (see request lib docs)
    // reqParams: {
    // }
});
// const queries = [
//     'DROP TABLE IF EXISTS session_temp',
//
//     `CREATE TABLE session_temp (
//         date Date,
//         time DateTime,
//         mark String,
//         ips Array(UInt32),
//         queries Nested (
//             act String,
//             id UInt32
//         )
//     )
//     ENGINE=MergeTree(date, (mark, time), 8192)`,
//
//     'OPTIMIZE TABLE ukit.loadstat PARTITION 201807 FINAL'
// ];
//
// async function main() {
//   for(const query of queries) {
//       const r = await clickhouse.query(query).toPromise();
//
//       console.log(query, r);
//   }
// }
// main()
var  i = 0
var dataSender = []
clickhouse.query(`SELECT DISTINCT number FROM system.numbers`).stream()
.on('data', function(data) {
    const stream = this;
    dataSender[i] = data
      if (i == 98 ) {
        // global.wss.clients.forEach(function each(client) {
        //   if (client.readyState === global.WebSocket.OPEN) {
        //     dataSender = JSON.stringify(dataSender)
        //     client.send(dataSender);
        //   }
        // });
console.log(data);
        console.log(dataSender);
        stream.pause();
        i = 0
        setTimeout(() => {
            stream.resume();
        }, 1000);
      }
      i++
})
    .on('error', err => {
        console.log(err);
    })
    .on('end', () => {

    });
