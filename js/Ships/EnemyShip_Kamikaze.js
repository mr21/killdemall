KillDemAll.EnemyShip_Kamikaze = function(vPos, assets) {
	// KillDemAll.EnemyShip_Kamikaze herite de KillDemAll.EnemyShip
	KillDemAll.EnemyShip.call(this,
		100,   // HP
		vPos,
		2,    // weight
		100,  // maxSpeeds
		200 + 100 * Math.random()   // acceleration
	);
	this.type  = 'Kamikaze';
	// sprites
	this.bodySprite = assets.sprites.create('EnemyShip_Kamikase', 5, 5, 16, 16);
	this.aura = assets.sprites.create('kamikaze_aura', 0, 0, 155, 155);
	this.aura.opacity(0.05);
	this.radSpeed = 0.5 + 3 * Math.random();
};

KillDemAll.EnemyShip_Kamikaze.prototype = new KillDemAll.EnemyShip();

KillDemAll.EnemyShip_Kamikaze.prototype.update = function(time) {
	// ship
	KillDemAll.EnemyShip.prototype.update.call(this, time);
	// gestion temporaire de collision envers le joueur
	var xshipPos = KillDemAll.xship.vPos;
	if (this.vPos.x >= xshipPos.x - 20 && this.vPos.x < xshipPos.x + 20 &&
	    this.vPos.y >= xshipPos.y - 20 && this.vPos.y < xshipPos.y + 20) {
		KillDemAll.gameover();
	}
	// rad
	var diffRad = this.rad - this.radCurr;
	if (diffRad > Math.PI)
		diffRad -= Math.PI * 2;
	else if (diffRad < -Math.PI)
		diffRad += Math.PI * 2;
	this.radCurr += diffRad * this.radSpeed * time.frameTime;
	this.radCurr = (Math.PI * 2 + this.radCurr) % (Math.PI * 2);
};

KillDemAll.EnemyShip_Kamikaze.prototype.renderAura = function(ctx) {
	this.aura.draw(this.vPos.x - 77, this.vPos.y - 77);
};

KillDemAll.EnemyShip_Kamikaze.prototype.renderBody = function(ctx) {
	ctx.save();
		ctx.translate(this.vPos.x, this.vPos.y);
			ctx.rotate(this.radCurr);
				this.bodySprite.draw(-8, -8);
	ctx.restore();
};
