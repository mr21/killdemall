var KillDemAll = {
	ready: function(canvasloth) {
		this.canvasloth = canvasloth;
		this.pageGameover = document._domSelector('.canvasloth-page.gameover')[0];
		this.Scoring.init(canvasloth.getCtx());
		canvasloth.cursor('crosshair');
		this.cam = new Canvasloth.Math.V2(0,0);
		this.map = new KillDemAll.Map(this.canvasloth, this.cam);
		this.explosions = new KillDemAll.Explosions(this.canvasloth.assets);
		this.ammo = new KillDemAll.Ammo(this.canvasloth.assets);
		this.xship = new KillDemAll.UserShip_XShip(
			{
				x: this.canvasloth.canvas.width()  / 2,
				y: this.canvasloth.canvas.height() / 2
			},
			this.canvasloth.time,
			this.canvasloth.assets,
			this.ammo
		);
		this.kamikazes = [];
		this.reset();
		cssInit({
			elem  : canvasloth.container._domSelector('.start .difficulty')[0],
			click : function() {
				KillDemAll.difficulty(this.innerHTML);
			}
		});
	},
	difficulty: function(lvl) {
		if (!this.difficulty.elem) {
			this.difficulty.elem = document._domSelector('.scoring > .difficulty')[0];
		}
		this.difficulty.elem.innerHTML = lvl;
		var area, kamSpd, enemyFq;
		switch (lvl) {
			case 'Easy'   : area = 200; kamSpd = 0.8; enemyFq =  3; break;
			case 'Normal' : area = 125; kamSpd = 1.0; enemyFq =  6; break;
			case 'Hard'   : area =  90; kamSpd = 1.4; enemyFq = 12; break;
		}
		this.xship.areaRadius = area;
		this.EnemyShip_Kamikaze.speedFactor = kamSpd;
		this.enemiesTimer = 1 / enemyFq;
		this.level = lvl;
	},
	reset: function() {
		var self = this;
		this.isGameover = false;
		this.Scoring.reset();
		this.ammo.reset();
		this.kamikazes.length = 0;
		this.timeChronoEnemies = this.canvasloth.time.realTime;
	},
	gameover: function() {
		this.isGameover = true;
		var score = this.pageGameover.getElementsByTagName('b')[0];
		score.innerHTML = this.Scoring.dom.score.get();
		this.canvasloth.pages.open(this.pageGameover);
	},
	createWave: function(type, nb, distMin, distMax) {
		this.Scoring.dom.enemyAlive.add(nb);
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
		this.ammo.update(time, function(shot) { return self.shotCollision(shot); });
		// XShip
		this.xship.update(time);
		// Enemies
		if (time.realTime - this.timeChronoEnemies > this.enemiesTimer) {
			this.timeChronoEnemies = time.realTime;
			this.createWave('Kamikaze', 1, 600, 700);
		}
		for (var i = 0, k; k = this.kamikazes[i]; ++i)
			k.update(time);
		// Map
		this.explosions.update(time);
		var viewSpeed = 4 * time.frameTime;
		var vShip = this.xship.vPos;
		this.cam.addF(
			viewSpeed * ((-vShip.x + this.canvasloth.width()  / 2) - this.cam.x),
			viewSpeed * ((-vShip.y + this.canvasloth.height() / 2) - this.cam.y)
		);
		this.Scoring.update(time);
	},
	shotCollision: function(shot) {
		var pts, ptsWin = 0, ptsTmp,
		    i = 0, k,
		    shipPos = this.xship.vPos,
		    shipRad = this.xship.radius * this.xship.radius,
		    shotDistMax = this.xship.areaRadius * this.xship.areaRadius;
		for (; k = this.kamikazes[i]; ++i)
			if (shot.vPos.distSquare(k.vPos) <= (k.bodySprite.w / 2) * (k.bodySprite.w / 2)) {
				if (k.hp > shot.hp) { // l'ennemie a encaisse le tir.
					pts = shot.hp;
					k.hp -= shot.hp;
					shot.hp = 0;
				} else { // le tir a au moins tue cet ennemie la.
					pts = k.hp;
					this.kamikazes.splice(i, 1);
					this.Scoring.dom.enemyAlive.add(-1);
					this.Scoring.dom.enemyKilled.add(+1);
					this.explosions.create(k.vPos);
					shot.hp -= k.hp;
				}
				ptsTmp = Math.ceil(pts * (1 - (k.vPos.distSquare(shipPos) - shipRad) / (shotDistMax - shipRad)));
				if (ptsTmp > 0) {
					ptsWin += ptsTmp;
					this.Scoring.newNumber(ptsTmp, pts, k.vPos.x, k.vPos.y);
				}
			}
		if (ptsWin)
			this.Scoring.dom.score.add(ptsWin, ptsWin * 4);
		return shot.hp <= 0;
	},
	render: function(ctx) {
		ctx.lookAt(this.cam);
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
		this.Scoring.render(ctx);
	},
	keydown: function(k) {
		switch (k) {
			case 27 : this.canvasloth.unfocus(); break;
			default :
				this.xship.userMove(k, 1);
				this.xship.userShootTurrets(k, 1);
		}
	},
	keyup: function(k) { 
		this.xship.userMove(k, 0);
		this.xship.userShootTurrets(k, 0); 
	},
	mousemove: function(x, y) {
		this.xship.userMoveCannon(x, y);
	},
	mousedown: function(k) {
		if (k === Canvasloth.LEFT_BUTTON)
			this.xship.userShootCannon();
	}
};
