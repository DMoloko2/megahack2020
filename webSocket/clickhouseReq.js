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
clickhouse.query(`SELECT DISTINCT number FROM system.numbers`).stream()
    .on('data', function(data) {
        const stream = this;
        if(exports.i == 98){
        stream.pause();
        //dataSender = JSON.stringify(dataSender)


        setTimeout(() => {
                stream.resume();
        }, 1000);
        }



    })
    .on('error', err => {
        console.log(err);
    })
    .on('end', () => {

    });
    // global.wss.clients.forEach(function each(client) {
    //   if (client.readyState === global.WebSocket.OPEN) {
    //     // client.send(dataSender);
    //   }
    // });
