KillDemAll.UserShip = function() {
	// KillDemAll.UserShip herite de KillDemAll.Ship
	KillDemAll.Ship.apply(this, arguments);
	// user controls
	this.moveKeys = [0,0,0,0]; // ^ > v <
	this.shotKeys = [0,0,0,0]; // ^ > v <
	this.mouseRad = 0;
};

KillDemAll.UserShip.prototype = new KillDemAll.Ship();

KillDemAll.UserShip.prototype.userMove = function(key, press) {
	var dir = -1;
	switch (key) {
		case 87 : this.moveKeys[dir = 0] = press; break; // ^ (W)
		case 68 : this.moveKeys[dir = 1] = press; break; // > (D)
		case 83 : this.moveKeys[dir = 2] = press; break; // v (S)
		case 65 : this.moveKeys[dir = 3] = press; break; // < (A)
	}
	if (dir !== -1)
		this._calcDir();
	return dir;
};

KillDemAll.UserShip.prototype.userShoot = function(key, press) {
	var dir = -1;
	switch (key) {
		case 38 : this.shotKeys[dir = 0] = press; break; // ^
		case 39 : this.shotKeys[dir = 1] = press; break; // >
		case 40 : this.shotKeys[dir = 2] = press; break; // v
		case 37 : this.shotKeys[dir = 3] = press; break; // <
	}
	return dir;
};

KillDemAll.UserShip.prototype.calcMouseRad = function(x, y) {
	return this.mouseRad = Math.PI - Math.atan2(
		x - this.vPos.x,
		y - this.vPos.y
	);
};

KillDemAll.UserShip.prototype._calcDir = function() {
	this.vDir.x = this.moveKeys[1] === this.moveKeys[3] ? 0 : this.moveKeys[1] ? +1 : -1;
	this.vDir.y = this.moveKeys[0] === this.moveKeys[2] ? 0 : this.moveKeys[2] ? +1 : -1;
	this.vDir.normalize();
};
