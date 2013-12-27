KillDemAll.XShip = function(time, assets, ammo) {
	this.time = time;
	this.ammo = ammo;
	// ship
	this.ship = new KillDemAll.Ship();
	// base
	this.base = {sprite:assets.sprite(85, 48, 23, 23)};
	// reactors
	this.reactors = [];
	for (var i = 0; i < 4; ++i)
		this.reactors[i] = {anim:assets.anim(18, 77, 12, 24, 9, 5, true, 0.04)};
	// armors
	this.armorOpenSize = 8;
	this.armorsOpen = [0,0,0,0]; // v < ^ >
	this.armors    = [];
	this.armors[0] = {sprite:assets.sprite(21, 19, 25, 25), x:-23, y:-25, openX:0, openY:0};
	this.armors[1] = {sprite:assets.sprite(49, 19, 25, 25), x: +0, y:-25, openX:0, openY:0};
	this.armors[2] = {sprite:assets.sprite(49, 47, 25, 25), x: +0, y: -2, openX:0, openY:0};
	this.armors[3] = {sprite:assets.sprite(21, 47, 25, 25), x:-23, y: -2, openX:0, openY:0};
	// turrets
	this.turretsDelayInc = 0.020;
	this.turretsDelayMin = 0.000;
	this.turretsDelayMax = 0.500;
	this.turretsCouples  = [];
	for (var i = 0; i < 4; ++i) {
		this.turretsCouples[i] = {side:0, delay:0, time:0, turrets:[]};
		for (var j = 0; j < 2; ++j) {
			this.turretsCouples[i].turrets[j] = {
				anim : assets.anim(137, 86, 10, 11, 7, 0, false),
				armor: this.armors[(i + j) % 4],
				rad  : Math.PI / 2 * i
			};
		}
	}
	this.turretsCouples[0].turrets[0].x =  -6; this.turretsCouples[0].turrets[0].y = -23;
	this.turretsCouples[0].turrets[1].x =  +6; this.turretsCouples[0].turrets[1].y = -23;
	this.turretsCouples[1].turrets[0].x = +23; this.turretsCouples[1].turrets[0].y =  -6;
	this.turretsCouples[1].turrets[1].x = +23; this.turretsCouples[1].turrets[1].y =  +6;
	this.turretsCouples[2].turrets[0].x =  +6; this.turretsCouples[2].turrets[0].y = +23;
	this.turretsCouples[2].turrets[1].x =  -6; this.turretsCouples[2].turrets[1].y = +23;
	this.turretsCouples[3].turrets[0].x = -23; this.turretsCouples[3].turrets[0].y =  +6;
	this.turretsCouples[3].turrets[1].x = -23; this.turretsCouples[3].turrets[1].y =  -6;
	// cannon
	this.cannon = {
		rad  : 0,
		anim : assets.anim(122, 21, 12, 50, 8, 0, false, 0.02)
	};
	// top
	this.top = {sprite:assets.sprite(89, 25, 16, 16)};
};
KillDemAll.XShip.prototype = {
	userMove: function(key, press) {
		var dir = this.ship.userMove(key, press);
		if (dir !== -1) {
			var anim = this.reactors[(dir + 2) % 4].anim;
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
			this.turretsCouples[dir].delay = this.turretsDelayMin;
			this.turretsCouples[dir].time  = this.time.realTime;
		}
	},
	shootTurret: function(turretsCouple) {
		var turret = turretsCouple.turrets[turretsCouple.side];
		turret.anim.play();
		var shotPos = new Vector2D(
			this.ship.vPos.x + turret.x + turret.armor.openX,
			this.ship.vPos.y + turret.y + turret.armor.openY
		);
		this.ammo.createShot('bullet', shotPos, turret.rad, this.ship.vMove);
		if (turretsCouple.delay < this.turretsDelayMax)
			turretsCouple.delay += this.turretsDelayInc;
		turretsCouple.time   = this.time.realTime;
		turretsCouple.side   = turretsCouple.side ? 0 : 1;
	},
	update: function(time) {
		// ship
		this.ship.update(time);
		// armors
		var speedArmor  = 15;
		for (var i = 0; i < 4; ++i)
			if (this.ship.moveKeys[i]) {
				this.armorsOpen[i] += (this.armorOpenSize - this.armorsOpen[i]) * speedArmor * time.frameTime;
				if (this.armorsOpen[i] > this.armorOpenSize)
					this.armorsOpen[i] = this.armorOpenSize;
			} else {
				this.armorsOpen[i] -= this.armorsOpen[i] * speedArmor * time.frameTime;
				if (this.armorsOpen[i] < 0)
					this.armorsOpen[i] = 0;
			}
		this.armors[0].openX = -this.armorsOpen[2]; this.armors[0].openY = -this.armorsOpen[1];
		this.armors[1].openX = +this.armorsOpen[2]; this.armors[1].openY = -this.armorsOpen[3];
		this.armors[2].openX = +this.armorsOpen[0]; this.armors[2].openY = +this.armorsOpen[3];
		this.armors[3].openX = -this.armorsOpen[0]; this.armors[3].openY = +this.armorsOpen[1];
		// turets
		for (var i = 0, turret; turret = this.turretsCouples[i]; ++i)
			if (this.ship.shotKeys[i] && time.realTime - turret.time >= turret.delay)
				this.shootTurret(turret);
		// cannon
		var speedCannon = 10;
		var diffRad = this.ship.mouseRad - this.cannon.rad;
		if (diffRad > Math.PI)
			diffRad -= Math.PI * 2;
		else if (diffRad < -Math.PI)
			diffRad += Math.PI * 2;
		this.cannon.rad += diffRad * speedCannon * time.frameTime;
		this.cannon.rad = (Math.PI * 2 + this.cannon.rad) % (Math.PI * 2);
	},
	render: function(ctx) {
		ctx.save();
			ctx.translate(this.ship.vPos.x, this.ship.vPos.y);

				// base
				this.base.sprite.draw(-11, -12);
				// reactors
				ctx.save();
					for (var i = 0; i < 4; ++i) {
						this.reactors[i].anim.draw(-6, -35);
						ctx.rotate(Math.PI / 2);
					}
				ctx.restore();
				// armors
				for (var i = 0, arm; arm = this.armors[i]; ++i)
					arm.sprite.draw(arm.x + arm.openX, arm.y + arm.openY);
				// turrets
				for (var i = 0, tur; tur = this.turretsCouples[i]; ++i)
					for (var j = 0, t; t = tur.turrets[j]; ++j) {
						ctx.save();
							ctx.translate(t.x + t.armor.openX, t.y + t.armor.openY);
								ctx.rotate(Math.PI / 2 * i);
									t.anim.draw(-5, -11);
						ctx.restore();
					}
				// top
				this.top.sprite.draw(-7, -9);
				// cannon
				ctx.save();
					ctx.rotate(this.cannon.rad);
						this.cannon.anim.draw(-6, -47);
				ctx.restore();

		ctx.restore();
	}
};
