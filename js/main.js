function lg(s) { console.log(s) }

window.onload = function() {
	// creation de l'objet Canvas2D
	var canvas2d = new Canvas2D(
		document._domSelector('.Canvas2D')[0],
		[
			'css/explosion.png',
			'css/Ammo.png',
			'css/UserShip_XShip.png',
			'css/EnemyShip_Kamikase.png',
			'css/Ground.png'
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
	// Initialisation du menu
	var domA_menu = document.getElementById('menu').getElementsByTagName('a');
	for (var i = 0, a; a = domA_menu[i]; ++i)
		a.onclick = function() { return canvas2d.openPage(document._domSelector('.Canvas2D > .' + this.className)[0]), false };
	document._domSelector('.page.gameover a')[0].onclick = function() {
		KillDemAll.reset();
		KillDemAll.canvas2d.closePage();
		KillDemAll.canvas2d.focus();
		return false;
	};
	// Initialisation et lancement du jeu
	KillDemAll.init(canvas2d);
};
