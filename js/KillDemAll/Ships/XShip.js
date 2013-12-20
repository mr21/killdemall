KillDemAll.XShip = function(assets) {
	KillDemAll.Ship.call(this);
	this.sprites = {
		'base'   : assets.sprite(85, 48, 23, 23),
		'part00' : assets.sprite(21, 19, 25, 25),
		'part10' : assets.sprite(49, 19, 25, 25),
		'part01' : assets.sprite(21, 47, 25, 25),
		'part11' : assets.sprite(49, 47, 25, 25),
		'top'    : assets.sprite(89, 25, 16, 16)
	};
	this.partVector = [0,0,0,0]; // v < ^ >
};
KillDemAll.XShip.prototype = KillDemAll.Ship.prototype;
KillDemAll.XShip.prototype.update = function(time) {
	var size = 8,
		speed = 15 * time.frameTime;
	for (var i = 0; i < 4; ++i)
		if (this.moveKeys[i]) {
			this.partVector[i] += (size - this.partVector[i]) * speed;
			if (this.partVector[i] > size)
				this.partVector[i] = size;
		} else {
			this.partVector[i] -= this.partVector[i] * speed;
			if (this.partVector[i] < 0)
				this.partVector[i] = 0;
		}
};
KillDemAll.XShip.prototype.render = function(ctx) {
	ctx.save();
		ctx.translate(this.vPos.x, this.vPos.y);

			// base
			this.sprites.base.draw(-11, -12);
			// les 4 coins
			this.sprites.part00.draw(-23 - this.partVector[2], -25 - this.partVector[1]);
			this.sprites.part10.draw( +0 + this.partVector[2], -25 - this.partVector[3]);
			this.sprites.part01.draw(-23 - this.partVector[0],  -2 + this.partVector[1]);
			this.sprites.part11.draw( +0 + this.partVector[0],  -2 + this.partVector[3]);
			// top
			this.sprites.top.draw( -7,  -9);

	ctx.restore();
};
