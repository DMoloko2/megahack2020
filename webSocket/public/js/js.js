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
});