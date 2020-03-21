new WOW().init();

$(document).ready(function() {
	$('div.sidebar-fixed div.list-group a').hover(
		function(){
			$(this).addClass('nav_left');
		},
		function(){
			$(this).removeClass('nav_left');
		}
	);

	$('#pressure_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://172.20.10.10:3000/getvalue',formData,processData);
    function processData(data) {
				// console.log(data);
      }
			alert('Параметры изменены');
    return false;
  });

	$('#humidity_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://172.20.10.10:3000/getvalue',formData,processData);
    function processData(data) {

      }
			alert('Параметры изменены');
    return false;
  });

	$('#room_temperature_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://172.20.10.10:3000/getvalue',formData,processData);
    function processData(data) {

      }
			alert('Параметры изменены');
    return false;
  });

	$('#temperature_working_area_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://172.20.10.10:3000/getvalue',formData,processData);
    function processData(data) {

      }
			alert('Параметры изменены');
    return false;
  });

	$('#ph_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://172.20.10.10:3000/getvalue',formData,processData);
    function processData(data) {

      }
			alert('Параметры изменены');
    return false;
  });

	$('#weight_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://172.20.10.10:3000/getvalue',formData,processData);
    function processData(data) {

      }
			alert('Параметры изменены');
    return false;
  });

	$('#flow_rate_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://172.20.10.10:3000/getvalue',formData,processData);
    function processData(data) {

      }
			alert('Параметры изменены');
    return false;
  });

	$('#CO2_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://172.20.10.10:3000/getvalue',formData,processData);
    function processData(data) {

      }
			alert('Параметры изменены');
    return false;
  });
});
