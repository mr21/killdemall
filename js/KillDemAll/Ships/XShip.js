KillDemAll.XShip = function(assets) {
	this.ship = new KillDemAll.Ship();
	this.sprites = {
		'base'    : assets.sprite(85, 48, 23, 23),
		'armor00' : assets.sprite(21, 19, 25, 25),
		'armor10' : assets.sprite(49, 19, 25, 25),
		'armor01' : assets.sprite(21, 47, 25, 25),
		'armor11' : assets.sprite(49, 47, 25, 25),
		'top'     : assets.sprite(89, 25, 16, 16)
	};
	this.anims = {
		'reactors' : [],
		'turrets'  : []
	};
	for (var i = 0; i < 4; ++i)
		this.anims.reactors[i] = assets.anim( 18, 77, 12, 24, 9, 5, true);
	for (var i = 0; i < 8; ++i)
		this.anims.turrets[i]  = assets.anim(137, 86, 10, 11, 7, 0, false);
	this.armorVector = [0,0,0,0]; // v < ^ >
};
KillDemAll.XShip.prototype = {
	userMove: function(key, press) {
		var dir = this.ship.userMove(key, press);
		var anim = this.anims.reactors[(dir + 2) % 4];
		press ? anim.play() : anim.stop();
	},
	update: function(time) {
		this.ship.update(time);
		var size = 8,
			speed = 15 * time.frameTime;
		for (var i = 0; i < 4; ++i)
			if (this.ship.moveKeys[i]) {
				this.armorVector[i] += (size - this.armorVector[i]) * speed;
				if (this.armorVector[i] > size)
					this.armorVector[i] = size;
			} else {
				this.armorVector[i] -= this.armorVector[i] * speed;
				if (this.armorVector[i] < 0)
					this.armorVector[i] = 0;
			}
	},
	render: function(ctx) {
		ctx.save();
			ctx.translate(this.ship.vPos.x, this.ship.vPos.y);

				// base
				this.sprites.base.draw(-11, -12);
				ctx.save();
					for (var i = 0; i < 4; ++i) {
						this.anims.reactors[i].draw(-6, -35);
						ctx.rotate(Math.PI / 2);
					}
				ctx.restore();
				// armor
				this.sprites.armor00.draw(-23 - this.armorVector[2], -25 - this.armorVector[1]);
				this.sprites.armor10.draw( +0 + this.armorVector[2], -25 - this.armorVector[3]);
				this.sprites.armor01.draw(-23 - this.armorVector[0],  -2 + this.armorVector[1]);
				this.sprites.armor11.draw( +0 + this.armorVector[0],  -2 + this.armorVector[3]);
				// turrets
				ctx.save();
					this.anims.turrets[0].draw(-11 - this.armorVector[2], -34 - this.armorVector[1]);
					this.anims.turrets[1].draw( +1 + this.armorVector[2], -34 - this.armorVector[3]);
					ctx.rotate(Math.PI / 2);
					this.anims.turrets[2].draw(-11 - this.armorVector[3], -34 - this.armorVector[2]);
					this.anims.turrets[3].draw( +1 + this.armorVector[3], -34 - this.armorVector[0]);
					ctx.rotate(Math.PI / 2);
					this.anims.turrets[4].draw(-11 - this.armorVector[0], -34 - this.armorVector[3]);
					this.anims.turrets[5].draw( +1 + this.armorVector[0], -34 - this.armorVector[1]);
					ctx.rotate(Math.PI / 2);
					this.anims.turrets[6].draw(-11 - this.armorVector[1], -34 - this.armorVector[0]);
					this.anims.turrets[7].draw( +1 + this.armorVector[1], -34 - this.armorVector[2]);
				ctx.restore();
				// top
				this.sprites.top.draw( -7,  -9);

		ctx.restore();
	}
};
