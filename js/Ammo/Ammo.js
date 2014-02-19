KillDemAll.Ammo = function(assets) {
	this.sprites = {
		'roquet' : assets.sprites.create('Ammo',  5, 5, 4, 14),
		'bullet' : assets.sprites.create('Ammo', 14, 5, 4,  4)
	};
	this.shots = [];
};
KillDemAll.Ammo.prototype = {
	createShot: function(type, vPos, rad, ship) {
		var shot = new KillDemAll.Ammo.Shot(this, type, vPos, rad, ship);
		this.shots.push(shot);
	},
	update: function(time, isIncollision) {
		for (var i = 0, j = 0; i < this.shots.length; ++i)
			if (this.shots[i].update(time, isIncollision))
				this.shots[j++] = this.shots[i];
		this.shots.length = j;
	},
	render: function(ctx) {
		for (var i = 0, s; s = this.shots[i]; ++i)
			s.render(ctx);
	},
	reset: function() {
		this.shots.length = 0;
	}
};
// Shot
KillDemAll.Ammo.Shot = function(Ammo, type, vPos, rad, ship) {
	switch (type) {
		case 'bullet' : this.hp =   2; this.speed =  900; this.recoil =  50; this.distMax = 400; break;
		case 'roquet' : this.hp = 100; this.speed = 1100; this.recoil = 210; this.distMax = 500; break;
	}
	this.hpMax = this.hp;
	this.dist = 0;
	this.rad = rad;
	this.sprite = Ammo.sprites[type];
	this.vPos = vPos.copy();
	var sinRad = +Math.sin(rad);
	var cosRad = -Math.cos(rad);
	this.vDir = ship.vMove.new_addF(
		sinRad * this.speed,
		cosRad * this.speed
	);
	ship.vMove.subF(
		this.recoil / (1 + ship.weight) * sinRad,
		this.recoil / (1 + ship.weight) * cosRad
	);
};
KillDemAll.Ammo.Shot.prototype = {
	update: function(time, isIncollision) {
		var incr = this.speed * time.frameTime
		this.dist += incr;
		if (this.dist > this.distMax) {
			if (this.hp === this.hpMax) // si le tir est une balle perdue
				KillDemAll.scoring.score.add(-1, 250);
			return false;
		}
		var nbTests = Math.ceil(incr / 4);
		for (var i = 0; i < nbTests; ++i) {
			this.vPos.addF(
				this.vDir.x * time.frameTime / nbTests,
				this.vDir.y * time.frameTime / nbTests
			);
			if (isIncollision(this))
				return false;
		}
		return true;
	},
	render: function(ctx) {
		ctx.save();
			ctx.translate(this.vPos.x, this.vPos.y);
				ctx.rotate(this.rad);
					this.sprite.draw(this.sprite.w / -2, this.sprite.h / -2);
		ctx.restore();
	}
};
