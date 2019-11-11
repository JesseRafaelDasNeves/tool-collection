

function callAjax(settings) {
    settings = $.extend({
	rotina   :1,
	acao     :1,
	processo :null,
	chave    :null,
	parametro:null,
	data     :{},
	dataGet  :{},
	method   :"POST",
	tipo     :"json",
	async    :false,
	url      :false,
	completo :function () {},
	exception:function () {},
	error    :function () {},
	'finally':function () {}
    }, settings);
    
    
    var fnConplete = 'tt';
    
    window.currentAjax = jQuery.ajax({
	url     :settings.url,
	type    :settings.method,
	async   :settings.async,
	data    :settings.data,
	dataType:"html",
	complete:fnComplete
    });
}