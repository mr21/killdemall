KillDemAll.Ship = function() {
	this.vPos     = new Vector2D();
	this.vDir     = new Vector2D(); // la direction que demande le joueur.
	this.vMove    = new Vector2D(); // ou l'on va reellement.
	this.weight   =   1.07;
	this.maxSpeed = 300;
	this.speed    =   0;
	this.moveKeys = [0,0,0,0]; // ^ > v <
};
KillDemAll.Ship.prototype = {
	update: function(time) {

	},
	userMove: function(key, press) {
		var dir;
		switch (key) {
			case 38 : this.moveKeys[dir = 0] = press; break; // ^
			case 39 : this.moveKeys[dir = 1] = press; break; // >
			case 40 : this.moveKeys[dir = 2] = press; break; // v
			case 37 : this.moveKeys[dir = 3] = press; break; // <
		}
		this.calcDir();
		return dir;
	},
	// private
	calcDir: function() {
		this.vDir.x = this.moveKeys[1] === this.moveKeys[3] ? 0 : this.moveKeys[1] ? +1 : -1;
		this.vDir.y = this.moveKeys[0] === this.moveKeys[2] ? 0 : this.moveKeys[2] ? +1 : -1;
		this.vDir.normalize();
	}
};
