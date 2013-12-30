KillDemAll.Ship = function(vPos, weight, maxSpeed, acceleration) {
	if (arguments.length > 0) {
		this.vPos         = new Vector2D(vPos);
		this.vMove        = new Vector2D(0, 0);
		this.vDir         = new Vector2D(0, 0);
		this.weight       = weight;
		this.maxSpeed     = maxSpeed;
		this.acceleration = acceleration;
	}
};
KillDemAll.Ship.prototype = {
	update: function(time) {
		// deplacement
		var incX = this.vMove.x * time.frameTime;
		var incY = this.vMove.y * time.frameTime;
		this.vPos.x += incX;
		this.vPos.y += incY;
		// adherence selon le poids
		this.vMove.x -= incX * this.weight;
		this.vMove.y -= incY * this.weight;
		// acceleration
		this.vMove.addXY(
			this.vDir.x * this.acceleration * time.frameTime,
			this.vDir.y * this.acceleration * time.frameTime
		);
	}
};
