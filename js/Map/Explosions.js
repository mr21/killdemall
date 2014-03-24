KillDemAll.explosions = {
	init: function(assets) {
		this.assets = assets;
		this.explosions = [];
	},
	create: function(vPos) {
		this.explosions.push(new this.explosion(this.assets, vPos, 125));
	},
	update: function(time) {
		for (var i = 0, e; e = this.explosions[i]; ++i) {
			e.update(time);
			if (!e.an_fire.playing && !e.sp_blast.opacity())
				this.explosions.splice(i, 1);
		}
	},
	render: function(ctx) {
		for (var i = 0, e; e = this.explosions[i]; ++i)
			e.render(ctx);
	}
};

KillDemAll.explosions.explosion = function(assets, vPos, blastRadius) {
	this.x = vPos.x;
	this.y = vPos.y;
	this.rad = Math.PI * 2 * Math.random();
	this.an_fire = assets.anims.create({img:'explosion_fire', w:64, h:64, nbFrames:48, duration:0.33});
	this.sp_blast = assets.sprites.create({img:'explosion_blast'});
	this.blastRadius = blastRadius;
	this.blastScale = 0;
	this.an_fire.play();
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

KillDemAll.explosions.explosion.prototype = {
	update: function(time) {
		time = time.frameTime;
		var prog = this.an_fire.progress(),
			op = this.sp_blast.opacity() - time * 3.5;
		if (op < 0)
			op = 0;
		this.blastScale = (1 - op) * 2;
		this.sp_blast.opacity(op);
	},
	render: function(ctx) {
		ctx.save();
			ctx.translate(this.x, this.y);
				ctx.save();
					ctx.scale(this.blastScale, this.blastScale);
						this.sp_blast.draw();
				ctx.restore();
				ctx.save();
					ctx.rotate(this.rad);
						this.an_fire.draw();
				ctx.restore();
		ctx.restore();
	}
};
