KillDemAll.Map = function(canvas2d) {
	var assets  = canvas2d.assets;
	this.vView  = canvas2d.getView();
	this.width  = canvas2d.ctx.canvas.width;
	this.height = canvas2d.ctx.canvas.height;
	this.sprites = {
		'ground' : assets.sprite(0, 0, 32, 32, 'css/map.png')
	};
};
KillDemAll.Map.prototype = {
	render: function(ctx) {
		var sprite = this.sprites.ground;
		var nbX = this.width  / sprite.w + 1;
		var nbY = this.height / sprite.h + 1;
		ctx.save();
			ctx.translate(
				sprite.w * -Math.ceil(this.vView.x / this.sprites.ground.w),
				sprite.h * -Math.ceil(this.vView.y / this.sprites.ground.h)
			);
				for (var y = 0; y < nbY; ++y)
					for (var x = 0; x < nbX; ++x)
						sprite.draw(x * sprite.w, y * sprite.h);
		ctx.restore();
	}
};
