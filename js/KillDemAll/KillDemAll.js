var KillDemAll = {
	init: function(canvas2d) {
		var self      = this;
		this.canvas2d = canvas2d;
		//canvas2d.debug(true);
		// scoring
		this.scoring = {};
		var domScore = document._domSelector('.scoring > span');
		for (var i = 0; d = domScore[i]; ++i)
			this.scoring[d.className] = new DomIntIncrease(d._next());
	},
	load: function() {
		this.map   = new KillDemAll.Map(this.canvas2d);
		this.ammo  = new KillDemAll.Ammo(this.canvas2d.assets);
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
		var self = this;
		self.createWave('Kamikaze', 100, 400, 450);
		window.setInterval(function() {
			self.createWave('Kamikaze', 25, 400, 450);
		}, 10 * 1000);
	},
	createWave: function(type, nb, distMin, distMax) {
		var distRand = distMax - distMin;
		this.scoring.enemyAlive.add(nb, 500);
		for (var i = 0; i < nb; ++i)
			this.createEnemy(type, distMin, distRand);
	},
	createEnemy: function(type, distMin, distRand) {
		var dist = distMin + distRand * Math.random();
		var rad  = (2 * Math.PI) * Math.random();
		var enemy = new KillDemAll['EnemyShip_' + type](
			{
				x: this.xship.vPos.x + Math.sin(rad) * dist,
				y: this.xship.vPos.y - Math.cos(rad) * dist
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
		for (var i = 0, k; k = this.kamikazes[i]; ++i)
			if (shot.vPos.x >= k.vPos.x - k.bodySprite.w / 2 &&
			    shot.vPos.x <= k.vPos.x + k.bodySprite.w / 2 &&
			    shot.vPos.y >= k.vPos.y - k.bodySprite.h / 2 &&
			    shot.vPos.y <= k.vPos.y + k.bodySprite.h / 2)
			{
				if (k.hp > shot.hp) { // l'ennemie a encaisse le tir.
					k.hp -= shot.hp;
					this.scoring.score.add(shot.hp, 250);
					return true;
				} else { // le tir a au moins tue cet ennemie la.
					this.kamikazes.splice(i, 1);
					this.scoring.enemyAlive.add(-1);
					this.scoring.enemyKilled.add(+1);
					this.scoring.score.add(k.hp + k.hpMax, 250);
					if (shot.hp > k.hp) { // le tir a encore de la puissance.
						shot.hp -= k.hp;
						return false;
					}
				}
				return true;
			}
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
