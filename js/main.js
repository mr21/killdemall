function lg(s) { console.log(s) }

window.onload = function()
{
	var canvasloth = new Canvasloth({
		type   : '2d',
		node   : document._domSelector('.canvasloth')[0],
		app    : KillDemAll,
		images : [
			'css/explosion.png',
			'css/Ammo.png',
			'css/UserShip_XShip.png',
			'css/EnemyShip_Kamikase.png',
			'css/kamikaze_aura.png',
			'css/Ground.png'
		],
		fn : {
			ready     : KillDemAll.ready,
			update    : KillDemAll.update,
			render    : KillDemAll.render,
			mousemove : KillDemAll.mousemove,
			mousedown : KillDemAll.mousedown,
			keydown   : KillDemAll.keydown,
			keyup     : KillDemAll.keyup
		}
	});

	var domA_menu = document.getElementById('menu').getElementsByTagName('a');
	for (var i = 0, a; a = domA_menu[i]; ++i)
		a.onclick = function() { return canvasloth.pages.open(document._domSelector('.canvasloth-page.' + this.className)[0]), false };

	document._domSelector('.canvasloth-page.gameover a')[0].onclick = function() {
		KillDemAll.reset();
		KillDemAll.canvasloth.pages.close();
		KillDemAll.canvasloth.focus();
		return false;
	};

};
