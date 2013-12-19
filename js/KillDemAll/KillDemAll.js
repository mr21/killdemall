var KillDemAll = {
	init: function(elem) {
		var self      = this;
		this.canvas2d = new Canvas2D(
			elem,
			['css/sprites.png'],
			{
				load: function() { self.load() },
				loop: function() { self.loop() }
			}
		);
	},
	load: function() {
		this.xship_01 = new KillDemAll.XShip();
	},
	loop: function() {
		var ctx = this.canvas2d.ctx;
		ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
		ctx.save();
			ctx.translate(100, 100);
				this.xship_01.render();
		ctx.restore();
	}
};
