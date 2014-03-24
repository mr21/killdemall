KillDemAll.map = {
	init: function(canvasloth, v2cam) {
		this.v2cam = v2cam;
		// ground
		this.sp_ground = canvasloth.assets.sprites.create({img:'map_ground'});
		this.grW = this.sp_ground.w;
		this.grH = this.sp_ground.h;
		// nombre de dalles a placer sur le sol
		this.nbX = canvasloth.width()  / this.grW + 1;
		this.nbY = canvasloth.height() / this.grH + 1;
	},
	render: function(ctx) {
		ctx.save();
			ctx.translate(
				this.grW * -Math.ceil(this.v2cam.x / this.grW),
				this.grH * -Math.ceil(this.v2cam.y / this.grH)
			);
				for (var y = 0; y < this.nbY; ++y)
					for (var x = 0; x < this.nbX; ++x)
						this.sp_ground.draw(x * this.grW, y * this.grH);
		ctx.restore();
	}
};
