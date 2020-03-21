$('#type1').click(function(){

});

  var ctx = document.getElementById('chart1').getContext('2d');
  ctx.canvas.width = 1000;
  ctx.canvas.height = 300;

  var timevar = 1584772210000;
  var datavar1 = 10.00;
  var datavar2 = 20.00;
  var datavar3 = 30.00;
  var datavar4 = 40.00;
  var porog = 65.00;

  var color = Chart.helpers.color;
  var cfg = {
    data: {
      datasets: [{
        label: 'Пороговое значение', //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        backgroundColor: color('#ff0000').alpha(0.5).rgbString(),
        // backgroundColor: '#ff0000',
        // borderColor: window.chartColors.blue,
        borderColor: '#ff0000', //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // data: generateData(),
        data: [
          {}
        ],
        type: 'line',
        pointRadius: 0,
        fill: false,
        lineTension: 0,
        borderWidth: 5
      },
      {
        label: 'Датчик 1', backgroundColor: color('#ffff00').alpha(0.5).rgbString(), borderColor: '#ffff00',
        data: [],
        type: 'line', pointRadius: 0, fill: false, lineTension: 0, borderWidth: 2
      },


      {
        label: 'Датчик 2', backgroundColor: color('#40ff00').alpha(0.5).rgbString(), borderColor: '#40ff00',
        data: [],
        type: 'line', pointRadius: 0, fill: false, lineTension: 0, borderWidth: 2
      },

      {
        label: 'Датчик 3', backgroundColor: color('#00ffbf').alpha(0.5).rgbString(), borderColor: '#00ffbf',
        data: [],
        type: 'line', pointRadius: 0, fill: false, lineTension: 0, borderWidth: 2
      },

      {
        label: 'Датчик 4', backgroundColor: color('#0000ff').alpha(0.5).rgbString(), borderColor: '#0000ff',
        data: [],
        type: 'line', pointRadius: 0, fill: false, lineTension: 0, borderWidth: 2
      }

    ]
    },
    options: {
      title:{
        display: true,
        position: 'top',
        text: 'Название графика'
      },
      legend: {
        position: 'right'
      },
      animation: {
        duration: 0
      },
      scales: {
        xAxes: [{
          scaleLabel:{
            display: false
          },
          type: 'time',
          distribution: 'series',
          offset: true,
          ticks: {
            major: {
              enabled: true,
              fontStyle: 'bold'
            },
            source: 'data',
            autoSkip: true,
            autoSkipPadding: 75,
            maxRotation: 0,
            sampleSize: 100
          },
          afterBuildTicks: function(scale, ticks) {
            var majorUnit = scale._majorUnit;
            var firstTick = ticks[0];
            var i, ilen, val, tick, currMajor, lastMajor;

            val = moment(ticks[0].value);
            if ((majorUnit === 'minute' && val.second() === 0)
                || (majorUnit === 'hour' && val.minute() === 0)
                || (majorUnit === 'day' && val.hour() === 9)
                || (majorUnit === 'month' && val.date() <= 3 && val.isoWeekday() === 1)
                || (majorUnit === 'year' && val.month() === 0)) {
              firstTick.major = true;
            } else {
              firstTick.major = false;
            }
            lastMajor = val.get(majorUnit);

            for (i = 1, ilen = ticks.length; i < ilen; i++) {
              tick = ticks[i];
              val = moment(tick.value);
              currMajor = val.get(majorUnit);
              tick.major = currMajor !== lastMajor;
              lastMajor = currMajor;
            }
            return ticks;
          }
        }],
        yAxes: [{
          gridLines: {
            drawBorder: false
          },
          scaleLabel: {
            display: true,
            labelString: 'Значение' //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
          }
        }]
      },
      tooltips: {
        intersect: false,
        mode: 'index',
        callbacks: {
          label: function(tooltipItem, myData) {
            var label = myData.datasets[tooltipItem.datasetIndex].label || '';
            if (label) {
              label += ': ';
            }
            label += parseFloat(tooltipItem.value).toFixed(2);
            return label;
          }
        }
      }
    }
  };

  var chart = new Chart(ctx, cfg);

  document.getElementById('btnDoble').addEventListener('click', function(){
    var porogset = chart.config.data.datasets[0];
    var dataset1 = chart.config.data.datasets[1];
    var dataset2 = chart.config.data.datasets[2];
    var dataset3 = chart.config.data.datasets[3];
    var dataset4 = chart.config.data.datasets[4];
    porogset.data.shift();
    dataset1.data.shift();
    dataset2.data.shift();
    dataset3.data.shift();
    dataset4.data.shift();
    timevar = timevar + 1000;
    datavar1 = datavar1 + 1;
    datavar2 = datavar2 + 1;
    datavar3 = datavar3 + 1;
    datavar4 = datavar4 + 1;
    porogset.data.push({t: timevar, y: porog});
    dataset1.data.push({t: timevar, y: datavar1});
    dataset2.data.push({t: timevar, y: datavar2});
    dataset3.data.push({t: timevar, y: datavar3});
    dataset4.data.push({t: timevar, y: datavar4});
    console.log(dataset1.data);
    chart.update();
  });


  document.getElementById('btnDelete').addEventListener('click', function(){
    var porogset = chart.config.data.datasets[0];
    var dataset1 = chart.config.data.datasets[1];
    var dataset2 = chart.config.data.datasets[2];
    var dataset3 = chart.config.data.datasets[3];
    var dataset4 = chart.config.data.datasets[4];
    porogset.data.shift();
    dataset1.data.shift();
    dataset2.data.shift();
    dataset3.data.shift();
    dataset4.data.shift();
    chart.update();
  });

  document.getElementById('btnAdd').addEventListener('click', function(){
    // console.log(date);
    var porogset = chart.config.data.datasets[0];
    var dataset1 = chart.config.data.datasets[1];
    var dataset2 = chart.config.data.datasets[2];
    var dataset3 = chart.config.data.datasets[3];
    var dataset4 = chart.config.data.datasets[4];
    timevar = timevar + 1000;
    datavar1 = datavar1 + 1;
    datavar2 = datavar2 + 1;
    datavar3 = datavar3 + 1;
    datavar4 = datavar4 + 1;
    porogset.data.push({t: timevar, y: porog});
    dataset1.data.push({t: timevar, y: datavar1});
    dataset2.data.push({t: timevar, y: datavar2});
    dataset3.data.push({t: timevar, y: datavar3});
    dataset4.data.push({t: timevar, y: datavar4});
    chart.update();
  });
