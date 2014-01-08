KillDemAll.Ammo = function(assets) {
	this.sprites = {
		'roquet' : assets.sprite(124, 5, 4, 14),
		'bullet' : assets.sprite(133, 5, 4,  4)
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
	}
};
// Shot
KillDemAll.Ammo.Shot = function(Ammo, type, vPos, rad, ship) {
	switch (type) {
		case 'bullet' : this.speed =  900; this.recoil = 160; this.distMax = 400; break;
		case 'roquet' : this.speed = 1100; this.recoil = 210; this.distMax = 500; break;
	}
	this.dist   = 0;
	this.rad    = rad;
	this.sprite = Ammo.sprites[type];
	this.vPos   = new Vector2D(vPos);
	var sinRad = +Math.sin(rad);
	var cosRad = -Math.cos(rad);
	this.vDir   = new Vector2D(
		sinRad * this.speed + ship.vMove.x,
		cosRad * this.speed + ship.vMove.y
	);
	ship.vMove.x -= this.recoil / (1 + ship.weight) * sinRad;
	ship.vMove.y -= this.recoil / (1 + ship.weight) * cosRad;
};
KillDemAll.Ammo.Shot.prototype = {
	update: function(time, isIncollision) {
		var incr = this.speed * time.frameTime
		this.dist += incr;
		if (this.dist > this.distMax)
			return false;
		var nbTests = Math.ceil(incr / 16);
		for (var i = 0; i < nbTests; ++i) {
			this.vPos.x += this.vDir.x * time.frameTime / nbTests;
			this.vPos.y += this.vDir.y * time.frameTime / nbTests;
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
