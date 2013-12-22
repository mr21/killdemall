var KillDemAll = {
	init: function(elem) {
		var self      = this;
		this.canvas2d = new Canvas2D(
			elem,
			[
				'css/sprites.png',
				'css/ground.jpg'
			],
			{
				load      : function() { self.load     .apply(self, arguments) },
				update    : function() { self.update   .apply(self, arguments) },
				render    : function() { self.render   .apply(self, arguments) },
				keydown   : function() { self.keydown  .apply(self, arguments) },
				keyup     : function() { self.keyup    .apply(self, arguments) },
				mousedown : function() { self.mousedown.apply(self, arguments) },
				mouseup   : function() { self.mouseup  .apply(self, arguments) },
				mousemove : function() { self.mousemove.apply(self, arguments) }
			}
		);
		//this.canvas2d.debug(true);
	},
	load: function() {
		this.map   = new KillDemAll.Map(this.canvas2d.assets);
		this.xship = new KillDemAll.XShip(this.canvas2d.assets);
		this.xship.ship.vPos.x = 200;
		this.xship.ship.vPos.y = 100;
		this.canvas2d.setView(50, 100);
	},
	keydown:   function(k) { this.xship.userMove(k, 1); },
	keyup:     function(k) { this.xship.userMove(k, 0); },
	mousedown: function(x, y) {
		lg('mousedown(' + x + ', ' + y + ')');
	},
	mouseup: function(x, y) {
		lg('mouseup(' + x + ', ' + y + ')');
	},
	mousemove: function(x, y, xRel, yRel) {
		this.xship.userMoveCannon(x, y);
		//lg('mousemove(' + x + ', ' + y + ', ' + xRel + ', ' + yRel + ')');
	},
	update: function(time) {
		this.xship.update(time);
	},
	render: function(ctx) {
		ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
		this.map.render(ctx);
		this.xship.render(ctx);
	}
};
