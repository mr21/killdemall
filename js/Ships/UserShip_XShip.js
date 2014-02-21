KillDemAll.UserShip_XShip = function(vPos, time, assets, ammo) {
	// heritage
	KillDemAll.UserShip.call(this,
		1000, // HP
		vPos,
		2,    // weight
		300,  // maxSpeed
		800   // acceleration
	);
	// objects needed
	this.time = time;
	this.ammo = ammo;
	this.radius = 30;
	this.hudRadius = 100;
	this.hudOpacity = 1;
	// base
	this.base = { sprite : assets.sprites.create('UserShip_XShip', 52, 5, 22, 22) };
	// reactors
	this.reactors = { anim : [] };
	for (var i = 0; i < 4; ++i)
		this.reactors.anim[i] = assets.anims.create('UserShip_XShip', 5, 32, 12, 24, 9, 5, true, 0.4);
	// armors
	this.armors = {
		speed   : 7,
		sprite  : assets.sprites.create('UserShip_XShip', 5, 5, 23, 23),
		openMax : 9,
		open    : [0,0,0,0]
	};
	// turrets
	this.turrets = {
		delayInc : 0.01,
		delayMin : 0.0,
		delayMax : 0.500,
		couples  : []
	};
	for (var i = 0; i < 4; ++i) {
		this.turrets.couples[i] = {
			rad   : Math.PI / 2 * i,
			side  : 0,
			delay : 0,
			time  : 0,
			anims : []
		};
		for (var j = 0; j < 2; ++j)
			this.turrets.couples[i].anims[j] = assets.anims.create('UserShip_XShip', 5, 61, 10, 11, 7, 0, false, 0.3);
	}
	// top
	this.top = { sprite : assets.sprites.create('UserShip_XShip', 33, 5, 14, 14) };
	// cannon
	this.cannon = {
		speed : 10,
		rad   : 0,
		anim  : assets.anims.create('UserShip_XShip', 5, 77, 12, 50, 8, 0, false, 0.2)
	};
};

KillDemAll.UserShip_XShip.prototype = new KillDemAll.UserShip();

KillDemAll.UserShip_XShip.prototype.userMove = function(key, press) {
	var dir  = KillDemAll.UserShip.prototype.userMove.call(this, key, press);
	if (dir !== -1) {
		var anim = this.reactors.anim[(dir + 2) % 4];
		press ? anim.play() : anim.stop();
	}
};

KillDemAll.UserShip_XShip.prototype.userMoveCannon = function(x, y) {
	this.calcMouseRad(x, y);
};

KillDemAll.UserShip_XShip.prototype.userShootCannon = function() {
	if (!this.cannon.anim.playing) {
		this.cannon.anim.play();
		var shotPos = new Canvasloth.Math.V2(
			this.vPos.x + 40 * +Math.sin(this.cannon.rad),
			this.vPos.y + 40 * -Math.cos(this.cannon.rad)
		);
		this.ammo.createShot('roquet', shotPos, this.cannon.rad, this);
		this.hudOpacity = 1;
	}
};

KillDemAll.UserShip_XShip.prototype.userShootTurrets = function(key, press) {
	var dir  = KillDemAll.UserShip.prototype.userShoot.call(this, key, press);
	if (dir !== -1) {
		this.turrets.couples[dir].delay = this.turrets.delayMin;
		this.turrets.couples[dir].time  = this.time.realTime;
	}
};

KillDemAll.UserShip_XShip.prototype.shootTurret = function(couple, ind) {
	var anim = couple.anims[couple.side];
	anim.stop();
	anim.play();
	var side   = couple.side ? +1 : -1;
	var sinRad = Math.sin(couple.rad);
	var cosRad = Math.cos(couple.rad);
	var x = side * (6 + this.armors.open[ind]);
	var y = -33 - this.armors.open[(4 + ind + side) % 4];
	var shotPos = new Canvasloth.Math.V2(
		this.vPos.x + x * cosRad - y * sinRad,
		this.vPos.y + x * sinRad + y * cosRad
	);
	this.ammo.createShot('bullet', shotPos, couple.rad, this);
	this.hudOpacity = 1;
	if (couple.delay < this.turrets.delayMax)
		couple.delay += this.turrets.delayInc;
	couple.time = this.time.realTime;
	couple.side = couple.side ? 0 : 1;
};

KillDemAll.UserShip_XShip.prototype.update = function(time) {
	// ship
	KillDemAll.UserShip.prototype.update.call(this, time);
	// armors
	for (var i = 0; i < 4; ++i) {
		var aInd = (i + 2) % 4;
		if (this.moveKeys[i]) {
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
		if (this.shotKeys[i] && time.realTime - couple.time >= couple.delay)
			this.shootTurret(couple, i);
	// cannon
	var diffRad = this.mouseRad - this.cannon.rad;
	if (diffRad > Math.PI)
		diffRad -= Math.PI * 2;
	else if (diffRad < -Math.PI)
		diffRad += Math.PI * 2;
	this.cannon.rad += diffRad * this.cannon.speed * time.frameTime;
	this.cannon.rad = (Math.PI * 2 + this.cannon.rad) % (Math.PI * 2);
	// hud
	this.hudOpacity -= 0.5 * time.frameTime;
	if (this.hudOpacity < 0)
		this.hudOpacity = 0;
};

KillDemAll.UserShip_XShip.prototype.renderHUD = function(ctx) {
	var i = 0, turretPx = 6, radAngle, armorOpen;
	ctx.strokeStyle = '#fff';
	ctx.globalAlpha = 0.08 * this.hudOpacity;
	ctx.beginPath(); ctx.arc(0, 0, this.hudRadius - 1, 0, 2 * Math.PI); ctx.stroke();
	ctx.beginPath(); ctx.arc(0, 0, this.radius, 0, 2 * Math.PI); ctx.stroke();
	ctx.lineWidth = 2.8;
	ctx.globalAlpha = 0.1 * this.hudOpacity;
	ctx.save();
		ctx.beginPath();
			for (; i < 4; ++i) {
				armorOpen = this.armors.open[(i + 1) % 4];
				radAngle = Math.atan((turretPx + armorOpen) / this.hudRadius);
				ctx.moveTo(this.hudRadius, -turretPx -armorOpen); ctx.arc(0, 0, this.hudRadius, -radAngle, radAngle);
				ctx.moveTo(this.hudRadius, -turretPx -armorOpen); ctx.lineTo(this.hudRadius - 5, -turretPx -armorOpen);
				ctx.moveTo(this.hudRadius, +turretPx +armorOpen); ctx.lineTo(this.hudRadius - 5, +turretPx +armorOpen);
				ctx.rotate(Math.PI / 2);
			}
		ctx.stroke();
	ctx.restore();
};

KillDemAll.UserShip_XShip.prototype.render = function(ctx) {
	ctx.save();
		ctx.translate(this.vPos.x, this.vPos.y);

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
				this.turrets.couples[0].anims[0].draw(-11 - this.armors.open[0], -33 - this.armors.open[3]);
				this.turrets.couples[0].anims[1].draw( +1 + this.armors.open[0], -33 - this.armors.open[1]);
				ctx.rotate(Math.PI / 2);
				this.armors.sprite.draw(-23 - this.armors.open[1], -23 - this.armors.open[0]);
				this.turrets.couples[1].anims[0].draw(-11 - this.armors.open[1], -33 - this.armors.open[0]);
				this.turrets.couples[1].anims[1].draw( +1 + this.armors.open[1], -33 - this.armors.open[2]);
				ctx.rotate(Math.PI / 2);
				this.armors.sprite.draw(-23 - this.armors.open[2], -23 - this.armors.open[1]);
				this.turrets.couples[2].anims[0].draw(-11 - this.armors.open[2], -33 - this.armors.open[1]);
				this.turrets.couples[2].anims[1].draw( +1 + this.armors.open[2], -33 - this.armors.open[3]);
				ctx.rotate(Math.PI / 2);
				this.armors.sprite.draw(-23 - this.armors.open[3], -23 - this.armors.open[2]);
				this.turrets.couples[3].anims[0].draw(-11 - this.armors.open[3], -33 - this.armors.open[2]);
				this.turrets.couples[3].anims[1].draw( +1 + this.armors.open[3], -33 - this.armors.open[0]);
			ctx.restore();
			// top
			this.top.sprite.draw(-7, -7);
			// cannon
			ctx.save();
				ctx.rotate(this.cannon.rad);
					this.cannon.anim.draw(-6, -47);
			ctx.restore();
			// hud
			this.renderHUD(ctx);

	ctx.restore();
};
