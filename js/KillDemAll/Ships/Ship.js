KillDemAll.Ship = function() {
	this.vPos     = new Vector2D();
	this.vDir     = new Vector2D(); // la direction que demande le joueur.
	this.vMove    = new Vector2D(); // ou l'on va reellement.
	this.weight   =   1.07;
	this.maxSpeed = 300;
	this.speed    =   0;
	this.moveKeys = [0,0,0,0]; // ^ > v <
	this.mouseRad = 0;
};
KillDemAll.Ship.prototype = {
	update: function(time) {
		// deplacement
		this.vPos.x += this.vMove.x * time.frameTime;
		this.vPos.y += this.vMove.y * time.frameTime;
		// adherence selon le poids
		this.vMove.div(this.weight);
		// acceleration
		this.vMove.addXY(
			this.vDir.x * 15,
			this.vDir.y * 15
		);
	},
	userMove: function(key, press) {
		var dir = -1;
		switch (key) {
			case 87 : this.moveKeys[dir = 0] = press; break; // ^ (W)
			case 68 : this.moveKeys[dir = 1] = press; break; // > (D)
			case 83 : this.moveKeys[dir = 2] = press; break; // v (S)
			case 65 : this.moveKeys[dir = 3] = press; break; // < (A)
		}
		if (dir !== -1)
			this.calcDir();
		return dir;
	},
	calcMouseRad: function(x, y) {
		return this.mouseRad = Math.PI - Math.atan2(
			x - this.vPos.x,
			y - this.vPos.y
		);
	},
	// private
	calcDir: function() {
		this.vDir.x = this.moveKeys[1] === this.moveKeys[3] ? 0 : this.moveKeys[1] ? +1 : -1;
		this.vDir.y = this.moveKeys[0] === this.moveKeys[2] ? 0 : this.moveKeys[2] ? +1 : -1;
		this.vDir.normalize();
	}
};
