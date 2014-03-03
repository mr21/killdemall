KillDemAll.Map = function(canvasloth, cam) {
	this.canvasloth = canvasloth;
	this.cam = cam;
	this.sprites = {
		'ground' : canvasloth.assets.sprites.create('Ground', 0, 0, 32, 32)
	};
};

KillDemAll.Map.prototype = {
	render: function(ctx) {
		var sprite = this.sprites.ground;
		var nbX = this.canvasloth.width()  / sprite.w + 1; // ctx.width
		var nbY = this.canvasloth.height() / sprite.h + 1; // ctx.height
		ctx.save();
			ctx.translate(
				sprite.w * -Math.ceil(this.cam.x / this.sprites.ground.w),
				sprite.h * -Math.ceil(this.cam.y / this.sprites.ground.h)
			);
				for (var y = 0; y < nbY; ++y)
					for (var x = 0; x < nbX; ++x)
						sprite.draw(x * sprite.w, y * sprite.h);
		ctx.restore();
	}
};
