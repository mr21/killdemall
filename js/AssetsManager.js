// AssetsManager ####################################
function AssetsManager(ctx, timeManager, src) {
	this.ctx         = ctx;
	this.timeManager = timeManager;
	this.src         = src;
	this.images      = [];
	this.anims       = [];
}
AssetsManager.prototype = {
	// public
	add: function(x, y, w, h, nbFrames, returnTo, loop) {
		if (nbFrames) {
			var asset = new AssetsManager.anim(this, arguments);
			this.anims.push(asset);
		} else {
			var asset = new AssetsManager.image(this, arguments);
			this.images.push(asset);
		}
		return asset;
	},
	del: function(asset) {
		for (var i = 0, a; a = this.images[i]; ++i)
			if (a === asset) {
				this.images.splice(i, 1);
				break;
			}
		for (var i = 0, a; a = this.anims[i]; ++i)
			if (a === asset) {
				this.anims.splice(i, 1);
				break;
			}
	},
	// private
	update: function() {
		for (var i = 0, a; a = this.anims[i]; ++i)
			a.update(this.timeManager);
	}
};

// Image ####################################
AssetsManager.image = function(manager, args) {
	this.manager = manager;
	this.x       = args[0];
	this.y       = args[1];
	this.h       = args[2];
	this.w       = args[3];
};
AssetsManager.image.prototype = {
	// public
	draw: function(x, y) {
		this.manager.ctx.drawImage(
			this.manager.src,
			this.x, this.y,
			this.w, this.h,
			x,      y,
			this.w, this.h
		);
	}
};

// Animation ####################################
AssetsManager.anim = function(manager, args) {
	this.image     = new AssetsManager.image(manager, args);
	this.framesAxe = 'xy'[args[4] > 0];
	this.nbFrames  = Math.abs(args[4]);
	this.returnTo  = args[5];
	this.loop      = args[6];
	this.frame     = this.returnTo === -1 ? -1 : 0;
	this.pause();
};
AssetsManager.anim.prototype = {
	// public
	draw: function(x, y) {
		if (this.frame > -1)
			this.image.draw(x, y);
	},
	play: function() {
		this.playing = true;
		if (this.frame === -1)
			this.moveFrame(1);
	},
	pause: function() {
		this.playing = false;
	},
	stop: function() {
		this.playing = false;
		this.moveFrame(-this.frame - (this.returnTo === -1));
	},
	rewind: function() {
	},
	// private
	moveFrame: function(f) {
		switch (this.framesAxe) {
			case 'x' : this.image.x += this.image.w * f; break;
			case 'y' : this.image.y += this.image.h * f; break;
		}
		this.frame += f;
	},
	update: function(timeManager) {

	}
};
