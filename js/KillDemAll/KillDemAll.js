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
		this.xship = new KillDemAll.XShip(this.canvas2d.assets);
		this.xship.vPos.x = 200;
		this.xship.vPos.y = 100;
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
		this.xship.update(this.canvas2d.time);
		var ctx = this.canvas2d.ctx;
		ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
		this.xship.render(ctx);
	}
};
