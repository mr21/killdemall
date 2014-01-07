var KillDemAll = {
	init: function(canvas2d) {
		var self      = this;
		this.canvas2d = canvas2d;
		//canvas2d.debug(true);
	},
	score: {
		init: function() {
			this.score       = 0;
			this.scoreTmp    = this.score;
			this.scoreInc    = 1;
			this.enemyKilled = {'Kamikaze':0};
			this.numFill     = '000000000';
			// DOM
			this.DOM = {'score':0, 'enemyKilled':0};
			for (var d in this.DOM) {
				this.DOM[d] = [
					document._domSelector('.scoring .' + d + ' + * span:first-child')[0],
					document._domSelector('.scoring .' + d + ' + * span:last-child')[0]
				];
				this.set(d, 0);
			}
		},
		set: function(dom, val) {
			var width = 1, fill = '';
			for (var valTmp = val; parseInt(valTmp /= 10); ++width) {}
			this.DOM[dom][0].innerHTML = this.numFill.substr(width);
			this.DOM[dom][1].innerHTML = val;
		},
		add: function(pts) {
			this.score   += pts;
			this.scoreInc = (this.score - this.scoreTmp) / 100;
		},
		kill: function(EnemyShip) {
			this.set('enemyKilled', ++this.enemyKilled[EnemyShip.type]);
			this.add(EnemyShip.nbPts);
		},
		update: function() {
			if (this.scoreTmp < this.score) {
				if ((this.scoreTmp += this.scoreInc) > this.score)
					this.scoreTmp = this.score;
				this.set('score', parseInt(this.scoreTmp));
			}
		}
	},
	load: function() {
		this.map   = new KillDemAll.Map(this.canvas2d);
		this.ammo  = new KillDemAll.Ammo(this.canvas2d.assets);
		this.score.init();
		// UserShip::XShip
		this.xship = new KillDemAll.UserShip_XShip(
			{
				x: this.canvas2d.ctx.canvas.width  / 2,
				y: this.canvas2d.ctx.canvas.height / 2
			},
			this.canvas2d.time,
			this.canvas2d.assets,
			this.ammo
		);
		// EnemyShip::Kamikaze
		this.kamikazes = [];
		// tmp
		this.createEnemy('Kamikaze');
	},
	createEnemy: function(type) {
		var distMin = 50;
		var enemy = new KillDemAll['EnemyShip_' + type](
			{
				x: this.xship.vPos.x + (distMin + Math.random() * 200) * (Math.random() > 0.5 ? -1 : +1),
				y: this.xship.vPos.y + (distMin + Math.random() * 200) * (Math.random() > 0.5 ? -1 : +1),
			},
			this.canvas2d.assets
		);
		enemy.setTarget(this.xship);
		this.kamikazes.push(enemy);
	},
	update: function(time) {
		// tirs
		var self = this;
		this.ammo.update(time, function(shot) { return self.shotCollision(shot) });
		// scoring
		this.score.update();
		// XShip
		this.xship.update(time);
		// Enemies
		for (var i = 0, k; k = this.kamikazes[i]; ++i)
			k.update(time);
		// centrer la vue sur le XShip
		var viewSpeed = 4 * time.frameTime;
		var vShip = this.xship.vPos;
		var vView = this.canvas2d.getView();
		this.canvas2d.setView(
			vView.x + ((-vShip.x + this.canvas2d.canvas.width  / 2) - vView.x) * viewSpeed,
			vView.y + ((-vShip.y + this.canvas2d.canvas.height / 2) - vView.y) * viewSpeed
		);
	},
	shotCollision: function(shot) {
		return false;
	},
	render: function(ctx) {
		// map
		this.map.render(ctx);
		// enemies
		for (var i = 0, k; k = this.kamikazes[i]; ++i)
			k.render(ctx);
		this.xship.render(ctx);
		this.ammo.render(ctx);
	},
	keydown:   function(k)    { this.xship.userMove(k, 1); this.xship.userShootTurrets(k, 1) },
	keyup:     function(k)    { this.xship.userMove(k, 0); this.xship.userShootTurrets(k, 0) },
	mousemove: function(x, y) { this.xship.userMoveCannon(x, y) },
	mousedown: function()     { this.xship.userShootCannon()    }
};
