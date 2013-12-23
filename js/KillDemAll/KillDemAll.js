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
				mousemove : function() { self.mousemove.apply(self, arguments) },
				mousedown : function() { self.mousedown.apply(self, arguments) }
				//mouseup   : function() { self.mouseup  .apply(self, arguments) },
			}
		);
		//this.canvas2d.debug(true);
	},
	load: function() {
		this.map   = new KillDemAll.Map(this.canvas2d.assets);
		this.xship = new KillDemAll.XShip(this.canvas2d.assets);
		this.xship.ship.vPos.x = 100;
		this.xship.ship.vPos.y = 200;
	},
	update: function(time) {
		// update du XShip
		this.xship.update(time);
		// centrer la vue sur le XShip
		var viewSpeed = 3 * time.frameTime;
		var vShip = this.xship.ship.vPos;
		var vView = this.canvas2d.getView();
		this.canvas2d.setView(
			vView.x + ((-vShip.x + this.canvas2d.elem.width  / 2) - vView.x) * viewSpeed,
			vView.y + ((-vShip.y + this.canvas2d.elem.height / 2) - vView.y) * viewSpeed
		);
	},
	render: function(ctx) {
		this.map.render(ctx);
		this.xship.render(ctx);
	},
	keydown:   function(k)    { this.xship.userMove(k, 1)       },
	keyup:     function(k)    { this.xship.userMove(k, 0)       },
	mousemove: function(x, y) { this.xship.userMoveCannon(x, y) },
	mousedown: function()     { this.xship.userShootCannon()    }
	//mouseup:   function(x, y) { lg('mouseup(' + x + ', ' + y + ')') },
};
