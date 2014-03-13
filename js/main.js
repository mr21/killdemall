function lg(s) { console.log(s) }

window.onload = function()
{
	var container = document._domSelector('.canvasloth')[0];
	var canvasloth = new Canvasloth({
		type   : '2d',
		node   : container,
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

	var domA_menu = document._domSelector('#menu a');
	for (var i = 0, a; a = domA_menu[i]; ++i)
		a.onclick = function() {
			canvasloth.pages.open(container._domSelector('.canvasloth-page.' + this.className)[0]);
			return false;
		};

	container._domSelector('.start    a.btn.start')[0].onclick =
	container._domSelector('.gameover a.btn.retry')[0].onclick = function() {
		KillDemAll.reset();
		canvasloth.pages.close();
		canvasloth.focus();
		return false;
	};

	container._domSelector('.gameover a.btn.quit')[0].onclick = function() {
		canvasloth.pages.open();
		return false;
	};
};
