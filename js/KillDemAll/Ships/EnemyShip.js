KillDemAll.EnemyShip = function() {
	// KillDemAll.EnemyShip herite de KillDemAll.Ship
	KillDemAll.Ship.apply(this, arguments);
	// 
	this.rad = 0;
	this.shipTargeted = null;
};

KillDemAll.EnemyShip.prototype = new KillDemAll.Ship();

KillDemAll.EnemyShip.prototype.setTarget = function(ship) { this.shipTargeted = ship };
KillDemAll.EnemyShip.prototype.getTarget = function()     { return this.shipTargeted };

KillDemAll.EnemyShip.prototype.update = function(time) {
	KillDemAll.Ship.prototype.update.call(this, time);
	if (this.shipTargeted) {
		this._calcRadDir(this.shipTargeted.vPos);
	}
};

KillDemAll.EnemyShip.prototype._calcRadDir = function(target_vPos) {
	this.rad = Math.PI - Math.atan2(
		target_vPos.x - this.vPos.x,
		target_vPos.y - this.vPos.y
	);
	this.vDir;
};
