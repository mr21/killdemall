var KillDemAll = {
	init: function(elem) {
		var self      = this;
		this.canvas2d = new Canvas2D(
			elem,
			['css/sprites.png'],
			{
				load    : function()  { self.load()     },
				loop    : function()  { self.loop()     },
				keydown : function(e) { self.keydown(e) },
				keyup   : function(e) { self.keyup(e)   }
			}
		);
	},
	load: function() {
		this.xship_01 = new KillDemAll.XShip();
	},
	keydown: function(key) {
		lg('keydown :' + key);
	},
	keyup: function(key) {
		lg('keyup   :' + key);
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
