KillDemAll.Explosions = function(assets) {
	this.assets  = assets;
	this.explosions = [];
};
KillDemAll.Explosions.prototype = {
	create: function(vPos) {
		this.explosions.push(new KillDemAll.Explosions.Explosion(this.assets, 'a_48', vPos));
	},
	update: function() {
		for (var i = 0, e; e = this.explosions[i]; ++i)
			if (!e.anim.playing)
				this.explosions.splice(i, 1);
	},
	render: function(ctx) {
		for (var i = 0, e; e = this.explosions[i]; ++i)
			e.render(ctx);
	}
};

KillDemAll.Explosions.Explosion = function(assets, type, vPos) {
	this.x = vPos.x;
	this.y = vPos.y;
	this.rad = (Math.PI * 2) * Math.random();
	switch (type) {
		case 'a_48' : this.anim = assets.anim(0, 0, 64, 64, 48, 0, false, 0.33, 'explosion'); break;
	}
	this.anim.play();
};
KillDemAll.Explosions.Explosion.prototype = {
	render: function(ctx) {
		ctx.save();
			ctx.translate(this.x, this.y);
				ctx.rotate(this.rad);
					this.anim.draw(-32, -32);
		ctx.restore();
	}
};
