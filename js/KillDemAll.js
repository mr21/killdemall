var KillDemAll = {
	init: function(canvasloth) {
		var self = this;
		this.canvasloth = canvasloth;
		// scoring
		this.scoring = {};
		var domScore = document._domSelector('.scoring > span');
		for (var i = 0; d = domScore[i]; ++i)
			this.scoring[d.className] = new DomIntIncrease(d._next());
		this.pageGameover = document._domSelector('.canvasloth-page.gameover')[0];
	},
	ready: function() {
		this.canvasloth.cursor('crosshair');
		this.map        = new KillDemAll.Map(this.canvasloth);
		this.explosions = new KillDemAll.Explosions(this.canvasloth.assets);
		this.ammo       = new KillDemAll.Ammo(this.canvasloth.assets);
		// UserShip::XShip
		this.xship = new KillDemAll.UserShip_XShip(
			{
				x: this.canvasloth.width()  / 2,
				y: this.canvasloth.height() / 2
			},
			this.canvasloth.time,
			this.canvasloth.assets,
			this.ammo
		);
		// EnemyShip::Kamikaze
		this.kamikazes = [];
		this.reset();
	},
	reset: function() {
		var self = this;
		this.isGameover = false;
		for (var s in this.scoring)
			this.scoring[s].set(0, 1000);
		this.ammo.reset();
		this.kamikazes.length = 0;
		this.timeChronoEnemies = this.canvasloth.time.realTime;
	},
	gameover: function() {
		this.isGameover = true;
		var score = this.pageGameover.getElementsByTagName('b')[0];
		score.innerHTML = this.scoring.score.get();
		this.canvasloth.pages.open(this.pageGameover);
	},
	createWave: function(type, nb, distMin, distMax) {
		this.scoring.enemyAlive.add(nb, 500);
		var distRand = distMax - distMin;
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
			this.canvasloth.assets
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
		if (time.realTime - this.timeChronoEnemies > 0.18) {
			this.timeChronoEnemies = time.realTime;
			this.createWave('Kamikaze', 1, 600, 700);
		}
		for (var i = 0, k; k = this.kamikazes[i]; ++i)
			k.update(time);
		// Map
		this.explosions.update();
		var viewSpeed = 4 * time.frameTime;
		var vShip = this.xship.vPos;
		var vView = this.canvasloth.getView();
		this.canvasloth.setView(
			vView.x + ((-vShip.x + this.canvasloth.width()  / 2) - vView.x) * viewSpeed,
			vView.y + ((-vShip.y + this.canvasloth.height() / 2) - vView.y) * viewSpeed
		);
	},
	shotCollision: function(shot) {
		var pts, ptsWin = 0,
		    i = 0, k,
		    shipPos = this.xship.vPos,
		    x, y, distMax = 100*100;
		for (; k = this.kamikazes[i]; ++i)
			if (shot.vPos.x >= k.vPos.x - k.bodySprite.w / 2 &&
			    shot.vPos.x <= k.vPos.x + k.bodySprite.w / 2 &&
			    shot.vPos.y >= k.vPos.y - k.bodySprite.h / 2 &&
			    shot.vPos.y <= k.vPos.y + k.bodySprite.h / 2)
			{
				if (k.hp > shot.hp) { // l'ennemie a encaisse le tir.
					pts = shot.hp;
					k.hp -= shot.hp;
					shot.hp = 0;
				} else { // le tir a au moins tue cet ennemie la.
					pts = k.hp;
					this.kamikazes.splice(i, 1);
					this.scoring.enemyAlive.add(-1);
					this.scoring.enemyKilled.add(+1);
					this.explosions.create(k.vPos);
					shot.hp -= k.hp;
				}
				x = k.vPos.x - shipPos.x;
				y = k.vPos.y - shipPos.y;
				x = (1 - (x*x + y*y)/distMax);
				if (x > 0)
					ptsWin += pts * x;
			}
		if (ptsWin)
			this.scoring.score.add(ptsWin, 250);
		return shot.hp <= 0;
	},
	render: function(ctx) {
		// map
		this.map.render(ctx);
		// explosions
		this.explosions.render(ctx);
		// enemies
		var i, k;
		for (i = 0; k = this.kamikazes[i]; ++i) k.renderAura(ctx);
		for (i = 0; k = this.kamikazes[i]; ++i) k.renderBody(ctx);
		this.xship.render(ctx);
		this.ammo.render(ctx);
	},
	keydown: function(k) {
		switch (k) {
			case 27 : this.canvasloth.unfocus(); break;
			default :
				this.xship.userMove(k, 1);
				this.xship.userShootTurrets(k, 1);
		}
	},
	keyup:     function(k)    { this.xship.userMove(k, 0); this.xship.userShootTurrets(k, 0) },
	mousemove: function(x, y) { this.xship.userMoveCannon(x, y) },
	mousedown: function()     { this.xship.userShootCannon()    }
};
