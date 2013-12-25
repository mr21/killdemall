KillDemAll.Ammo = function(assets) {
	this.sprites = {
		'roquet' : assets.sprite(251, 18, 4, 14),
		'bullet' : assets.sprite(261, 18, 4,  4)
	};
	this.shots = [];
};
KillDemAll.Ammo.prototype = {
	createShot: function(type, vPos, vDir) {
		this.shots.push(new this.Shot(this, type, vPos, vDir));
	},
	update: function(time) {
		for (var i = 0, s; s = this.shots[i]; ++i) {
			s.update(time);
		}
	},
	render: function(ctx) {
		for (var i = 0, s; s = this.shots[i]; ++i)
			s.render(ctx);
	}
};
// Shot
KillDemAll.Ammo.Shot = function(Ammo, type, vPos, vDir) {
	this.sprite = Ammo.sprites[type];
	this.vPos   = new Vector2D(vPos);
	this.vDir   = new Vector2D(vDir);
	this.rad    = 0;
	switch (type) {
		case 'bullet' : this.speed  = 200; this.recoil =  50; this.distMax = 400; break;
		case 'roquet' : this.speed  = 250; this.recoil = 100; this.distMax = 500; break;
	}
};
KillDemAll.Ammo.Shot.prototype = {
	update: function(time) {

	},
	render: function(ctx) {
		ctx.save();
			ctx.rotate(this.rad);
				this.sprite.draw(this.vPos.x, this.vPos.y);
		ctx.restore();
	}
};