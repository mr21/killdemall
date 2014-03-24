function lg(s) { console.log(s) }

function cssInit(obj) {
	if (obj.elem._hasClass('btn-grp')) {
		var links = obj.elem._domSelector('> a');
		var linkSelected = null;
		for (var i = 0, l; l = links[i]; ++i) {
			l.onclick = function() { return false; };
			l._addEvent('click', function() {
				if (linkSelected !== this) {
					if (linkSelected)
						linkSelected._delClass('selected');
					this._addClass('selected');
					linkSelected = this;
					obj.click.call(this);
				}
			});
			if (l._hasClass('selected')) {
				linkSelected = l;
				obj.click.call(l);
			}
		}
	}
}

window.onload = function()
{
	var container = document._domSelector('.canvasloth')[0];
	var canvasloth = new Canvasloth({
		type   : '2d',
		node   : container,
		app    : KillDemAll,
		images : [
			'css/map_ground.png',
			'css/explosion_fire.png',
			'css/explosion_blast.png',
			'css/explosion_fragment.png',
			'css/shots.png',
			'css/xship.png',
			'css/kamikaze.png',
			'css/kamikaze_aura.png'
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
