KillDemAll.Ammo = function(assets) {
	this.sprites = {
		'roquet' : assets.sprite(251, 18, 4, 14),
		'bullet' : assets.sprite(261, 18, 4,  4)
	};
	this.shots = [];
};
KillDemAll.Ammo.prototype = {
	createShot: function(type, vPos, rad) {
		this.shots.push(new KillDemAll.Ammo.Shot(this, type, vPos, rad));
	},
	update: function(time) {
		for (var i = 0, j = 0; i < this.shots.length; ++i)
			if (this.shots[i].update(time))
				this.shots[j++] = this.shots[i];
		this.shots.length = j;
	},
	render: function(ctx) {
		for (var i = 0, s; s = this.shots[i]; ++i)
			s.render(ctx);
	}
};
// Shot
KillDemAll.Ammo.Shot = function(Ammo, type, vPos, rad) {
	this.sprite = Ammo.sprites[type];
	this.vPos   = new Vector2D(vPos);
	this.vDir   = new Vector2D(Math.sin(rad), -Math.cos(rad));
	this.rad    = rad;
	this.dist   = 0;
	switch (type) {
		case 'bullet' : this.speed = 400; this.recoil =  50; this.distMax = 400; break;
		case 'roquet' : this.speed = 500; this.recoil = 100; this.distMax = 500; break;
	}
};
KillDemAll.Ammo.Shot.prototype = {
	update: function(time) {
		var speed = this.speed * time.frameTime;
		if ((this.dist += 1 * speed) > this.distMax)
			return false;
		this.vPos.x += this.vDir.x * speed;
		this.vPos.y += this.vDir.y * speed;
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