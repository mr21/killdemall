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
		this.vPos.x += this.vMove.x * time.frameTime;
		this.vPos.y += this.vMove.y * time.frameTime;
		// adherence selon le poids
		this.vMove.div(this.weight); // rajouter le frametime
		// acceleration
		this.vMove.addXY(
			this.vDir.x * this.acceleration, // rajouter le frametime
			this.vDir.y * this.acceleration
		);
	}
};
