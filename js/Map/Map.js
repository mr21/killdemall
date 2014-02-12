KillDemAll.Map = function(canvasloth) {
	this.canvasloth = canvasloth;
	this.vView = canvasloth.getView();
	this.sprites = {
		'ground' : canvasloth.assets.sprite(0, 0, 32, 32, 'css/Ground.png')
	};
};
KillDemAll.Map.prototype = {
	render: function(ctx) {
		var sprite = this.sprites.ground;
		var nbX = this.canvasloth.width()  / sprite.w + 1;
		var nbY = this.canvasloth.height() / sprite.h + 1;
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
