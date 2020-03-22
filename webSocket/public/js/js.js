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
    $.post('http://localhost:3000/getvalue',formData,processData);
    function processData(data) {
				alert(data);
      }
    return false;
  });

	$('#humidity_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://localhost:3000/getvalue',formData,processData);
    function processData(data) {
				alert(data);
      }

    return false;
  });

	$('#room_temperature_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://localhost:3000/getvalue',formData,processData);
    function processData(data) {
				alert(data);
      }

    return false;
  });

	$('#temperature_working_area_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://localhost:3000/getvalue',formData,processData);
    function processData(data) {
			alert(data);
      }

    return false;
  });

	$('#ph_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://localhost:3000/getvalue',formData,processData);
    function processData(data) {
			alert(data);
      }

    return false;
  });

	$('#weight_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://localhost:3000/getvalue',formData,processData);
    function processData(data) {
			alert(data);
      }

    return false;
  });

	$('#flow_rate_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://localhost:3000/getvalue',formData,processData);
    function processData(data) {
			alert(data);
      }

    return false;
  });

	$('#CO2_form').submit(function() {
    var formData = $(this).serialize();
    $.post('http://localhost:3000/getvalue',formData,processData);
    function processData(data) {
			alert(data);
      }

    return false;
  });
});
