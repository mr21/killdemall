var KillDemAll = {
	ready: function(cnv) {
		this.canvasloth = cnv;
		this.pageGameover = document._domSelector('.canvasloth-page.gameover')[0];
		this.Scoring.init(cnv.ctx);
		cnv.canvas.cursor('crosshair');
		this.cam = new Canvasloth.Math.V2(0,0);
		this.map.init(cnv, this.cam);
		this.explosions.init(cnv);
		this.shots.init(cnv);
		this.xship = new KillDemAll.UserShip_XShip(
			cnv,
			{
				x: cnv.canvas.width()  / 2,
				y: cnv.canvas.height() / 2
			},
			this.shots
		);
		this.kamikazes = [];
		this.reset();
		cssInit({
			elem  : cnv.container._domSelector('.start .difficulty')[0],
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
		this.Scoring.reset();
		this.shots.reset();
		this.kamikazes.length = 0;
		this.timeChronoEnemies = this.canvasloth.times.real;
	},
	gameover: function() {
		var score = this.pageGameover.getElementsByTagName('b')[0];
		score.innerHTML = this.Scoring.dom.score.get();
		this.canvasloth.pages.open(this.pageGameover);
	},
	createWave: function(type, nb, distMin, distMax) {
		this.Scoring.dom.enemiesAlive.add(nb);
		var distRand = distMax - distMin;
		for (var i = 0; i < nb; ++i)
			this.createEnemy(type, distMin, distRand);
	},
	createEnemy: function(type, distMin, distRand) {
		var dist = distMin + distRand * Math.random();
		var rad  = (2 * Math.PI) * Math.random();
		var enemy = new KillDemAll['EnemyShip_' + type](
			this.canvasloth,
			{
				x: this.xship.vPos.x + Math.sin(rad) * dist,
				y: this.xship.vPos.y - Math.cos(rad) * dist
			}
		);
		enemy.setTarget(this.xship);
		this.kamikazes.push(enemy);
	},
	update: function(cnv) {
		var self = this,
		    times = cnv.times;
		this.shots.update(times, function(shot) { return self.shotCollision(shot); });
		this.xship.update(times);
		if (times.real - this.timeChronoEnemies > this.enemiesTimer) {
			this.timeChronoEnemies = times.real;
			this.createWave('Kamikaze', 1, 600, 700);
		}
		for (var i = 0, k; k = this.kamikazes[i]; ++i)
			k.update(times);
		this.explosions.update(times);
		var viewSpeed = 4 * times.frame;
		var vShip = this.xship.vPos;
		this.cam.addF(
			viewSpeed * ((-vShip.x + cnv.canvas.width()  / 2) - this.cam.x),
			viewSpeed * ((-vShip.y + cnv.canvas.height() / 2) - this.cam.y)
		);
		this.Scoring.update(times);
	},
	shotCollision: function(shot) {
		var pts, ptsWin = 0, ptsTmp,
		    i = 0, k,
		    shipPos = this.xship.vPos,
		    shipRad = this.xship.radius * this.xship.radius,
		    shotDistMax = this.xship.areaRadius * this.xship.areaRadius;
		for (; k = this.kamikazes[i]; ++i)
			if (shot.vPos.distSquare(k.vPos) <= (k.bodySprite.w / 2) * (k.bodySprite.w / 2)) {
				if (k.hp > shot.hp) { // l'ennemi a encaisse le tir.
					pts = shot.hp;
					k.hp -= shot.hp;
					shot.hp = 0;
				} else { // le tir a au moins tue cet ennemi la.
					pts = k.hp;
					this.kamikazes.splice(i, 1);
					this.Scoring.dom.enemiesAlive.add(-1);
					this.Scoring.dom.enemiesKilled.add(+1);
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
	render: function(cnv) {
		var ctx = cnv.ctx, i, k;
		cnv.camera.lookAt(this.cam);
		this.map.render(ctx);
		this.explosions.render(cnv);
		for (i = 0; k = this.kamikazes[i]; ++i) k.renderAura(ctx);
		for (i = 0; k = this.kamikazes[i]; ++i) k.renderBody(ctx);
		this.xship.render(ctx);
		this.shots.render(ctx);
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
