KillDemAll.XShip = function(assets) {
	this.ship = new KillDemAll.Ship();
	this.sprites = {
		'base'   : assets.sprite(85, 48, 23, 23),
		'part00' : assets.sprite(21, 19, 25, 25),
		'part10' : assets.sprite(49, 19, 25, 25),
		'part01' : assets.sprite(21, 47, 25, 25),
		'part11' : assets.sprite(49, 47, 25, 25),
		'top'    : assets.sprite(89, 25, 16, 16)
	};
	this.anims = {
		'reactor' : [
			assets.anim(18, 77, 12, 24, 9, 5, true),
			assets.anim(18, 77, 12, 24, 9, 5, true),
			assets.anim(18, 77, 12, 24, 9, 5, true),
			assets.anim(18, 77, 12, 24, 9, 5, true)
		]
	};
	this.partVector = [0,0,0,0]; // v < ^ >
};
KillDemAll.XShip.prototype = {
	userMove: function(key, press) {
		var dir = this.ship.userMove(key, press);
		var anim = this.anims.reactor[(dir + 2) % 4];
		press ? anim.play() : anim.stop();
	},
	update: function(time) {
		this.ship.update(time);
		var size = 8,
			speed = 15 * time.frameTime;
		for (var i = 0; i < 4; ++i)
			if (this.ship.moveKeys[i]) {
				this.partVector[i] += (size - this.partVector[i]) * speed;
				if (this.partVector[i] > size)
					this.partVector[i] = size;
			} else {
				this.partVector[i] -= this.partVector[i] * speed;
				if (this.partVector[i] < 0)
					this.partVector[i] = 0;
			}
	},
	render: function(ctx) {
		ctx.save();
			ctx.translate(this.ship.vPos.x, this.ship.vPos.y);

				// base
				this.sprites.base.draw(-11, -12);
				ctx.save();
					for (var i = 0; i < 4; ++i) {
						this.anims.reactor[i].draw(-6, -35);
						ctx.rotate(3.14 / 2);
					}
				ctx.restore();
				// les 4 coins
				this.sprites.part00.draw(-23 - this.partVector[2], -25 - this.partVector[1]);
				this.sprites.part10.draw( +0 + this.partVector[2], -25 - this.partVector[3]);
				this.sprites.part01.draw(-23 - this.partVector[0],  -2 + this.partVector[1]);
				this.sprites.part11.draw( +0 + this.partVector[0],  -2 + this.partVector[3]);
				// top
				this.sprites.top.draw( -7,  -9);

		ctx.restore();
	}
};
