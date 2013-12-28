KillDemAll.XShip = function(time, assets, ammo) {
	this.time = time;
	this.ammo = ammo;
	// ship
	this.ship = new KillDemAll.Ship();
	// base
	this.base = { sprite : assets.sprite(52, 5, 22, 22) };
	// reactors
	this.reactors = { anim : [] };
	for (var i = 0; i < 4; ++i)
		this.reactors.anim[i] = assets.anim(18, 77, 12, 24, 9, 5, true, 0.04);
	// armors
	this.armors = {
		speed   : 15,
		sprite  : assets.sprite(5, 5, 23, 23),
		openMax : 8,
		open    : [0,0,0,0]
	};
	// turrets
	this.turrets = {
		delayInc : 0.025,
		delayMin : 0.100,
		delayMax : 0.500,
		couples  : []
	};
	for (var i = 0; i < 4; ++i) {
		this.turrets.couples[i] = { side : 0, delay : 0, time : 0, turrets : [] };
		for (var j = 0; j < 2; ++j) {
			this.turrets.couples[i].turrets[j] = {
				anim : assets.anim(137, 86, 10, 11, 7, 0, false),
				rad  : Math.PI / 2 * i
			};
		}
	}
	// top
	this.top = { sprite : assets.sprite(33, 5, 14, 14) };
	// cannon
	this.cannon = {
		speed : 10,
		rad   : 0,
		anim  : assets.anim(122, 21, 12, 50, 8, 0, false, 0.02)
	};
};
KillDemAll.XShip.prototype = {
	userMove: function(key, press) {
		var dir = this.ship.userMove(key, press);
		if (dir !== -1) {
			var anim = this.reactors.anim[(dir + 2) % 4];
			press ? anim.play() : anim.stop();
		}
	},
	userMoveCannon: function(x, y) {
		this.ship.calcMouseRad(x, y);
	},
	userShootCannon: function() {
		if (!this.cannon.anim.playing) {
			this.cannon.anim.play();
			var shotPos = new Vector2D(
				this.ship.vPos.x + 40 * +Math.sin(this.cannon.rad),
				this.ship.vPos.y + 40 * -Math.cos(this.cannon.rad)
			);
			this.ammo.createShot('roquet', shotPos, this.cannon.rad, this.ship.vMove);
		}
	},
	userShootTurrets: function(key, press) {
		var dir = this.ship.userShoot(key, press);
		if (dir !== -1) {
			this.turrets.couples[dir].delay = this.turrets.delayMin;
			this.turrets.couples[dir].time  = this.time.realTime;
		}
	},
	shootTurret: function(couple, ind) {
		var turret = couple.turrets[couple.side];
		if (!turret.anim.playing) {
			turret.anim.play();
			var side   = couple.side ? +1 : -1;
			var sinRad = Math.sin(turret.rad);
			var cosRad = Math.cos(turret.rad);
			var x = side * (6 + this.armors.open[ind]);
			var y = -33 - this.armors.open[(4 + ind + side) % 4];
			var shotPos = new Vector2D(
				this.ship.vPos.x + x * cosRad - y * sinRad,
				this.ship.vPos.y + x * sinRad + y * cosRad
			);
			this.ammo.createShot('bullet', shotPos, turret.rad, this.ship.vMove);
			if (couple.delay < this.turrets.delayMax)
				couple.delay += this.turrets.delayInc;
			couple.time = this.time.realTime;
			couple.side = couple.side ? 0 : 1;
		}
	},
	update: function(time) {
		// ship
		this.ship.update(time);
		// armors
		for (var i = 0; i < 4; ++i) {
			var aInd = (i + 2) % 4;
			if (this.ship.moveKeys[i]) {
				this.armors.open[aInd] += (this.armors.openMax - this.armors.open[aInd]) * this.armors.speed * time.frameTime;
				if (this.armors.open[aInd] > this.armors.openMax)
					this.armors.open[aInd] = this.armors.openMax;
			} else {
				this.armors.open[aInd] -= this.armors.open[aInd] * this.armors.speed * time.frameTime;
				if (this.armors.open[aInd] < 0)
					this.armors.open[aInd] = 0;
			}
		}
		// turets
		for (var i = 0, couple; couple = this.turrets.couples[i]; ++i)
			if (this.ship.shotKeys[i] && time.realTime - couple.time >= couple.delay)
				this.shootTurret(couple, i);
		// cannon
		var diffRad = this.ship.mouseRad - this.cannon.rad;
		if (diffRad > Math.PI)
			diffRad -= Math.PI * 2;
		else if (diffRad < -Math.PI)
			diffRad += Math.PI * 2;
		this.cannon.rad += diffRad * this.cannon.speed * time.frameTime;
		this.cannon.rad = (Math.PI * 2 + this.cannon.rad) % (Math.PI * 2);
	},
	render: function(ctx) {
		ctx.save();
			ctx.translate(this.ship.vPos.x, this.ship.vPos.y);

				// base
				this.base.sprite.draw(-11, -11);
				// reactors
				ctx.save();
					this.reactors.anim[0].draw(-6, -35); ctx.rotate(Math.PI / 2);
					this.reactors.anim[1].draw(-6, -35); ctx.rotate(Math.PI / 2);
					this.reactors.anim[2].draw(-6, -35); ctx.rotate(Math.PI / 2);
					this.reactors.anim[3].draw(-6, -35);
				ctx.restore();
				// armors / turrets
				ctx.save();
					this.armors.sprite.draw(-23 - this.armors.open[0], -23 - this.armors.open[3]);
					this.turrets.couples[0].turrets[0].anim.draw(-11 - this.armors.open[0], -33 - this.armors.open[3]);
					this.turrets.couples[0].turrets[1].anim.draw( +1 + this.armors.open[0], -33 - this.armors.open[1]);
					ctx.rotate(Math.PI / 2);
					this.armors.sprite.draw(-23 - this.armors.open[1], -23 - this.armors.open[0]);
					this.turrets.couples[1].turrets[0].anim.draw(-11 - this.armors.open[1], -33 - this.armors.open[0]);
					this.turrets.couples[1].turrets[1].anim.draw( +1 + this.armors.open[1], -33 - this.armors.open[2]);
					ctx.rotate(Math.PI / 2);
					this.armors.sprite.draw(-23 - this.armors.open[2], -23 - this.armors.open[1]);
					this.turrets.couples[2].turrets[0].anim.draw(-11 - this.armors.open[2], -33 - this.armors.open[1]);
					this.turrets.couples[2].turrets[1].anim.draw( +1 + this.armors.open[2], -33 - this.armors.open[3]);
					ctx.rotate(Math.PI / 2);
					this.armors.sprite.draw(-23 - this.armors.open[3], -23 - this.armors.open[2]);
					this.turrets.couples[3].turrets[0].anim.draw(-11 - this.armors.open[3], -33 - this.armors.open[2]);
					this.turrets.couples[3].turrets[1].anim.draw( +1 + this.armors.open[3], -33 - this.armors.open[0]);
				ctx.restore();
				// top
				this.top.sprite.draw(-7, -7);
				// cannon
				ctx.save();
					ctx.rotate(this.cannon.rad);
						this.cannon.anim.draw(-6, -47);
				ctx.restore();

		ctx.restore();
	}
};
