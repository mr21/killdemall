function lg(s) { console.log(s) }

window.onload = function() {
	// creation de l'objet canvasloth
	var canvasloth = new Canvasloth(
		'2d',
		document._domSelector('.canvasloth')[0],
		KillDemAll,
		[
			'css/explosion.png',
			'css/Ammo.png',
			'css/UserShip_XShip.png',
			'css/EnemyShip_Kamikase.png',
			'css/kamikaze_aura.png',
			'css/Ground.png'
		]
	);
	// Initialisation du menu
	var domA_menu = document.getElementById('menu').getElementsByTagName('a');
	for (var i = 0, a; a = domA_menu[i]; ++i)
		a.onclick = function() { return canvasloth.pages.open(document._domSelector('.canvasloth-page.' + this.className)[0]), false };
	document._domSelector('.canvasloth-page.gameover a')[0].onclick = function() {
		KillDemAll.reset();
		KillDemAll.canvasloth.pages.close();
		KillDemAll.canvasloth.focus();
		return false;
	};
	// Initialisation et lancement du jeu
	KillDemAll.init(canvasloth);
};
