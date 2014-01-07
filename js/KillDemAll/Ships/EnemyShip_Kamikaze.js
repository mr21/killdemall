KillDemAll.EnemyShip_Kamikaze = function(vPos, assets) {
	// KillDemAll.EnemyShip_Kamikaze herite de KillDemAll.EnemyShip
	KillDemAll.EnemyShip.call(
		this,
		vPos,
		1,    // weight
		100,  // maxSpeeds
		1200  // acceleration
	);
	this.type  = 'Kamikaze';
	this.nbPts = 10;
	// sprites
	this.bodySprite = assets.sprite(5, 5, 16, 16, 'EnemyShip_Kamikase');
	this.radCurr    = this.rad;
	this.radSpeed   = 2;
};

KillDemAll.EnemyShip_Kamikaze.prototype = new KillDemAll.EnemyShip();

KillDemAll.EnemyShip_Kamikaze.prototype.update = function(time) {
	// ship
	KillDemAll.EnemyShip.prototype.update.call(this, time);
	// rad
	var diffRad = this.rad - this.radCurr;
	if (diffRad > Math.PI)
		diffRad -= Math.PI * 2;
	else if (diffRad < -Math.PI)
		diffRad += Math.PI * 2;
	this.radCurr += diffRad * this.radSpeed * time.frameTime;
	this.radCurr = (Math.PI * 2 + this.radCurr) % (Math.PI * 2);
};

KillDemAll.EnemyShip_Kamikaze.prototype.render = function(ctx) {
	ctx.save();
		ctx.translate(this.vPos.x, this.vPos.y);
			ctx.rotate(this.radCurr);
				this.bodySprite.draw(-8, -8);
	ctx.restore();
};
