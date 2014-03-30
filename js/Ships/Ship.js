KillDemAll.Ship = function(hp, vPos, weight, maxSpeed, acceleration) {
	if (arguments.length > 0) {
		this.hpMax = hp;
		this.hp = hp;
		this.vPos = new Canvasloth.Math.V2(vPos);
		this.vMove = new Canvasloth.Math.V2(0, 0);
		this.vDir = new Canvasloth.Math.V2(0, 0);
		this.weight = weight;
		this.maxSpeed = maxSpeed;
		this.acceleration = acceleration;
	}
};

KillDemAll.Ship.prototype.update = function(times) {
	// deplacement
	var inc = this.vMove.new_mulS(times.frame);
	this.vPos.addV(inc);
	// adherence selon le poids
	this.vMove.subV(inc.mulS(this.weight));
	// acceleration
	this.vMove.addV(this.vDir.new_mulS(this.acceleration * times.frame));
};
