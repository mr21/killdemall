KillDemAll.EnemyShip = function() {
	// KillDemAll.EnemyShip herite de KillDemAll.Ship
	KillDemAll.Ship.apply(this, arguments);
	// EnemyShip
	this.type  = '';
	this.rad     = 0;
	this.radCurr = this.rad;
	this.shipTargeted = null;
};

KillDemAll.EnemyShip.prototype = new KillDemAll.Ship();

KillDemAll.EnemyShip.prototype.setTarget = function(ship) { this.shipTargeted = ship };
KillDemAll.EnemyShip.prototype.getTarget = function()     { return this.shipTargeted };

KillDemAll.EnemyShip.prototype.update = function(time) {
	KillDemAll.Ship.prototype.update.call(this, time);
	if (this.shipTargeted) {
		this._calcRad(this.shipTargeted.vPos);
		this._calcDir();
	}
};

KillDemAll.EnemyShip.prototype._calcRad = function(target_vPos) {
	this.rad = Math.PI - Math.atan2(
		target_vPos.x - this.vPos.x,
		target_vPos.y - this.vPos.y
	);
};

KillDemAll.EnemyShip.prototype._calcDir = function() {
	this.vDir.x = +Math.sin(this.radCurr);
	this.vDir.y = -Math.cos(this.radCurr);
};
