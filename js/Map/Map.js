KillDemAll.Map = function(canvasloth, cam) {
	this.canvasloth = canvasloth;
	this.cam = cam;
	this.sp_ground = canvasloth.assets.sprites.create('map_ground');
};

KillDemAll.Map.prototype = {
	render: function(ctx) {
		var grW = this.sp_ground.w,
			grH = this.sp_ground.h,
			nbX = this.canvasloth.width()  / grW + 1, // ctx.width
			nbY = this.canvasloth.height() / grH + 1; // ctx.height
		ctx.save();
			ctx.translate(
				grW * -Math.ceil(this.cam.x / grW),
				grH * -Math.ceil(this.cam.y / grH)
			);
				for (var y = 0; y < nbY; ++y)
					for (var x = 0; x < nbX; ++x)
						this.sp_ground.draw(x * grW, y * grH);
		ctx.restore();
	}
};
