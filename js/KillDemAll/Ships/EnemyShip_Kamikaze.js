KillDemAll.EnemyShip_Kamikaze = function(vPos, assets) {
	// KillDemAll.EnemyShip_Kamikaze herite de KillDemAll.EnemyShip
	KillDemAll.EnemyShip.call(
		this,
		vPos,
		1,    // weight
		100,  // maxSpeeds
		1200  // acceleration
	);
	// sprites
	this.bodySprite = assets.sprite(5, 5, 16, 16, 'EnemyShip_Kamikase');
};

KillDemAll.EnemyShip_Kamikaze.prototype = new KillDemAll.EnemyShip();

KillDemAll.EnemyShip_Kamikaze.prototype.render = function(ctx) {
	ctx.save();
		ctx.translate(this.vPos.x, this.vPos.y);
			this.bodySprite.draw(-8, -8);
	ctx.restore();
};
