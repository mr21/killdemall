function lg(s) { console.log(s) }

window.onload = function() {
	// creation de l'objet canvasloth
	var canvasloth = new Canvasloth(
		document._domSelector('.canvasloth')[0],
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
		a.onclick = function() { return canvasloth.openPage(document._domSelector('.canvasloth-page.' + this.className)[0]), false };
	document._domSelector('.canvasloth-page.gameover a')[0].onclick = function() {
		KillDemAll.reset();
		KillDemAll.canvasloth.closePage();
		KillDemAll.canvasloth.focus();
		return false;
	};
	// Initialisation et lancement du jeu
	KillDemAll.init(canvasloth);
};
