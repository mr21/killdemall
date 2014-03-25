KillDemAll.EnemyShip_Kamikaze = function(vPos, assets) {
	// KillDemAll.EnemyShip_Kamikaze herite de KillDemAll.EnemyShip
	var spd = KillDemAll.EnemyShip_Kamikaze.speedFactor;
	KillDemAll.EnemyShip.call(this,
		100,   // HP
		vPos,
		2,    // weight
		100,  // maxSpeeds
		spd * (200 + 100 * Math.random())  // acceleration
	);
	this.type = 'Kamikaze';
	// sprites
	this.bodySprite = assets.sprites.create({img:'kamikaze', x:5, y:5, w:16, h:16});
	this.aura = assets.sprites.create({img:'kamikaze_aura'});
	this.aura.opacity(0.05);
	this.radSpeed = spd * (0.5 + 3 * Math.random());
};

KillDemAll.EnemyShip_Kamikaze.speedFactor = 1;

KillDemAll.EnemyShip_Kamikaze.prototype = new KillDemAll.EnemyShip();

KillDemAll.EnemyShip_Kamikaze.prototype.update = function(time) {
	// ship
	KillDemAll.EnemyShip.prototype.update.call(this, time);
	// gestion temporaire de collision envers le joueur
	if (this.vPos.distSquare(KillDemAll.xship.vPos) <= KillDemAll.xship.radius * KillDemAll.xship.radius) {
	    KillDemAll.gameover();
	} else {
		// rad
		var diffRad = this.rad - this.radCurr;
		if (diffRad > Math.PI)
			diffRad -= Math.PI * 2;
		else if (diffRad < -Math.PI)
			diffRad += Math.PI * 2;
		this.radCurr += diffRad * this.radSpeed * time.frameTime;
		this.radCurr = (Math.PI * 2 + this.radCurr) % (Math.PI * 2);
	}
};

KillDemAll.EnemyShip_Kamikaze.prototype.renderAura = function(ctx) {
	this.aura.draw(this.vPos.x, this.vPos.y);
};

KillDemAll.EnemyShip_Kamikaze.prototype.renderBody = function(ctx) {
	ctx.save();
		ctx.translate(this.vPos.x, this.vPos.y);
			ctx.rotate(this.radCurr);
				this.bodySprite.draw();
	ctx.restore();
};
