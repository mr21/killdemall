KillDemAll.EnemyShip_Kamikaze = function(vPos, assets) {
	// KillDemAll.EnemyShip_Kamikaze herite de KillDemAll.EnemyShip
	KillDemAll.EnemyShip.call(this,
		2,   // HP
		vPos,
		2,    // weight
		100,  // maxSpeeds
		200 + 100 * Math.random()   // acceleration
	);
	this.type  = 'Kamikaze';
	this.nbPts = 10;
	// sprites
	this.bodySprite = assets.sprite(5, 5, 16, 16, 'EnemyShip_Kamikase');
	this.radSpeed   = 0.5 + 3 * Math.random();
};

KillDemAll.EnemyShip_Kamikaze.prototype = new KillDemAll.EnemyShip();

KillDemAll.EnemyShip_Kamikaze.prototype.update = function(time) {
	// ship
	KillDemAll.EnemyShip.prototype.update.call(this, time);
	// gestion temporaire de collision envers le joueur
	var xshipPos = KillDemAll.xship.vPos;
	if (this.vPos.x >= xshipPos.x - 16 && this.vPos.x < xshipPos.x + 16 &&
		this.vPos.y >= xshipPos.y - 16 && this.vPos.y < xshipPos.y + 16) {
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

KillDemAll.EnemyShip_Kamikaze.prototype.render = function(ctx) {
	ctx.save();
		ctx.translate(this.vPos.x, this.vPos.y);
			ctx.rotate(this.radCurr);
				this.bodySprite.draw(-8, -8);
	ctx.restore();
};
