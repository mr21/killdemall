var KillDemAll = {
	init: function(elem) {
		var self      = this;
		this.canvas2d = new Canvas2D(
			elem,
			[
				'css/sprites.png',
				'css/map.png'
			],
			{
				load      : function() { self.load     .apply(self, arguments) },
				update    : function() { self.update   .apply(self, arguments) },
				render    : function() { self.render   .apply(self, arguments) },
				keydown   : function() { self.keydown  .apply(self, arguments) },
				keyup     : function() { self.keyup    .apply(self, arguments) },
				mousemove : function() { self.mousemove.apply(self, arguments) },
				mousedown : function() { self.mousedown.apply(self, arguments) }
			}
		);
		//this.canvas2d.debug(true);
	},
	load: function() {
		this.map   = new KillDemAll.Map(this.canvas2d);
		this.ammo  = new KillDemAll.Ammo(this.canvas2d.assets);
		// user ship : XShip
		this.xship = new KillDemAll.UserShip_XShip(
			{
				x: this.canvas2d.ctx.canvas.width  / 2,
				y: this.canvas2d.ctx.canvas.height / 2
			},
			this.canvas2d.time,
			this.canvas2d.assets,
			this.ammo
		);
	},
	update: function(time) {
		// update des tirs
		this.ammo.update(time);
		// update du XShip
		this.xship.update(time);
		// centrer la vue sur le XShip
		var viewSpeed = 4 * time.frameTime;
		var vShip = this.xship.vPos;
		var vView = this.canvas2d.getView();
		this.canvas2d.setView(
			vView.x + ((-vShip.x + this.canvas2d.elem.width  / 2) - vView.x) * viewSpeed,
			vView.y + ((-vShip.y + this.canvas2d.elem.height / 2) - vView.y) * viewSpeed
		);
	},
	render: function(ctx) {
		this.map.render(ctx);
		this.xship.render(ctx);
		this.ammo.render(ctx);
	},
	keydown:   function(k)    { this.xship.userMove(k, 1); this.xship.userShootTurrets(k, 1) },
	keyup:     function(k)    { this.xship.userMove(k, 0); this.xship.userShootTurrets(k, 0) },
	mousemove: function(x, y) { this.xship.userMoveCannon(x, y) },
	mousedown: function()     { this.xship.userShootCannon()    }
};
