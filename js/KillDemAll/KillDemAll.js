var KillDemAll = {
	init: function(elem) {
		var self      = this;
		this.canvas2d = new Canvas2D(
			elem,
			['css/sprites.png'],
			{
				load      : function()  { self.load()     },
				loop      : function()  { self.loop()     },
				keydown   : function(e) { self.keydown(e) },
				keyup     : function(e) { self.keyup(e)   },
				mousedown : function()  { self.mousedown.apply(self, arguments) },
				mouseup   : function()  { self.mouseup  .apply(self, arguments) },
				mousemove : function()  { self.mousemove.apply(self, arguments) }
			}
		);
	},
	load: function() {
		this.xship = new KillDemAll.XShip();
	},
	keydown: function(k) { if (k >= 37 && k <= 40) this.xship.userMove(k, 1); },
	keyup:   function(k) { if (k >= 37 && k <= 40) this.xship.userMove(k, 0); },
	mousedown: function(x, y) {
		lg('mousedown(' + x + ', ' + y + ')');
	},
	mouseup: function(x, y) {
		lg('mouseup(' + x + ', ' + y + ')');
	},
	mousemove: function(x, y, xRel, yRel) {
		//lg('mousemove(' + x + ', ' + y + ', ' + xRel + ', ' + yRel + ')');
	},
	loop: function() {
		var ctx = this.canvas2d.ctx;
		ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
		ctx.save();
			ctx.translate(100, 100);
				this.xship.render();
		ctx.restore();
	}
};
