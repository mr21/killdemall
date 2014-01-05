function lg(s) { console.log(s) }

window.onload = function() {
	var canvas2d = new Canvas2D(
		document._domSelector('.Canvas2D')[0],
		[
			'css/sprites.png',
			'css/EnemyShip_Kamikase.png',
			'css/map.png'
		],
		{
			load      : function() { KillDemAll.load     .apply(KillDemAll, arguments) },
			update    : function() { KillDemAll.update   .apply(KillDemAll, arguments) },
			render    : function() { KillDemAll.render   .apply(KillDemAll, arguments) },
			keydown   : function() { KillDemAll.keydown  .apply(KillDemAll, arguments) },
			keyup     : function() { KillDemAll.keyup    .apply(KillDemAll, arguments) },
			mousemove : function() { KillDemAll.mousemove.apply(KillDemAll, arguments) },
			mousedown : function() { KillDemAll.mousedown.apply(KillDemAll, arguments) }
		}
	);
	KillDemAll.init(canvas2d);
};
