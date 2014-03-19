KillDemAll.Explosions = function(assets) {
	this.assets  = assets;
	this.explosions = [];
};

KillDemAll.Explosions.prototype = {
	create: function(vPos) {
		this.explosions.push(new KillDemAll.Explosions.Explosion(this.assets, vPos, 125));
	},
	update: function(time) {
		for (var i = 0, e; e = this.explosions[i]; ++i) {
			e.update(time);
			if (!e.explosion.playing && !e.blast.opacity())
				this.explosions.splice(i, 1);
		}
	},
	render: function(ctx) {
		for (var i = 0, e; e = this.explosions[i]; ++i)
			e.render(ctx);
	}
};

KillDemAll.Explosions.Explosion = function(assets, vPos, blastRadius) {
	this.x = vPos.x;
	this.y = vPos.y;
	this.rad = Math.PI * 2 * Math.random();
	this.explosion = assets.anims.create('explosion.png', 0, 0, 64, 64, 48, -1, false, 0.33);
	this.blast = assets.sprites.create('explosion_blast');
	this.blastRadius = blastRadius;
	this.blastScale = 0;
	this.explosion.play();
	// le blast souffle tous les vaisseaux aux alentours
	var vBlast = new Canvasloth.Math.V2(0,0);
	var blastRadius2 = Math.pow(blastRadius, 2);
	function moveShip(ship) {
		var norm2 = vBlast.setV(ship.vPos).subV(vPos).normSquare();
		if (norm2 < blastRadius2) {
			norm2 = (blastRadius2 - norm2) / blastRadius2;
			ship.vMove.addV(vBlast.normalize().mulS(norm2 * blastRadius));
		}
	}
	moveShip(KillDemAll.xship);
	for (var i = 0, e; e = KillDemAll.kamikazes[i]; ++i)
		moveShip(e);
};

KillDemAll.Explosions.Explosion.prototype = {
	update: function(time) {
		var op = this.blast.opacity() - time.frameTime * 3.5;
		if (op < 0)
			op = 0;
		this.blast.opacity(op);
		this.blastScale = (1 - op) * 2;
	},
	render: function(ctx) {
		ctx.save();
			ctx.translate(this.x, this.y);
				ctx.save();
					ctx.scale(this.blastScale, this.blastScale);
						this.blast.draw(-62, -62);
				ctx.restore();
				ctx.rotate(this.rad);
					this.explosion.draw(-32, -32);
		ctx.restore();
	}
};
