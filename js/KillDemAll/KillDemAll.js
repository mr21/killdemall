var KillDemAll = {
	init: function(canvas2d) {
		var self      = this;
		this.canvas2d = canvas2d;
		//canvas2d.debug(true);
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
		// tmp
		this.enemyTest = new KillDemAll.EnemyShip_Kamikaze(
			{
				x: this.xship.vPos.x + 100,
				y: this.xship.vPos.y,
			},
			this.canvas2d.assets
		);
		this.enemyTest.setTarget(this.xship);
	},
	update: function(time) {
		// update des tirs
		var self = this;
		this.ammo.update(time, function(shot) { return self.shotCollision(shot) });
		// update du XShip
		this.xship.update(time);
		this.enemyTest.update(time);
		// centrer la vue sur le XShip
		var viewSpeed = 4 * time.frameTime;
		var vShip = this.xship.vPos;
		var vView = this.canvas2d.getView();
		this.canvas2d.setView(
			vView.x + ((-vShip.x + this.canvas2d.canvas.width  / 2) - vView.x) * viewSpeed,
			vView.y + ((-vShip.y + this.canvas2d.canvas.height / 2) - vView.y) * viewSpeed
		);
	},
	shotCollision: function(shot) {
		return false;
	},
	render: function(ctx) {
		this.map.render(ctx);
		this.enemyTest.render(ctx);
		this.xship.render(ctx);
		this.ammo.render(ctx);
	},
	keydown:   function(k)    { this.xship.userMove(k, 1); this.xship.userShootTurrets(k, 1) },
	keyup:     function(k)    { this.xship.userMove(k, 0); this.xship.userShootTurrets(k, 0) },
	mousemove: function(x, y) { this.xship.userMoveCannon(x, y) },
	mousedown: function()     { this.xship.userShootCannon()    }
};
