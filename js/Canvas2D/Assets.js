// Assets ####################################
function Assets(Canvas2D, images) {
	this.ctx           = Canvas2D.ctx;
	this.time          = Canvas2D.time;
	this.images        = [];
	this.sprites       = [];
	this.anims         = [];
	var self           = this;
	var nbImagesToLoad = images.length;
	for (var i = 0, imgSrc; imgSrc = images[i]; ++i) {
		var img = new Image();
		img.src = imgSrc;
		img.onload = function() {
			self.images.push(this);
			if (--nbImagesToLoad === 0)
				Canvas2D.launch();
		};
	}
}
Assets.prototype = {
	// public
	sprite: function(x, y, w, h, imgPath) {
		var sprite = new Assets.assetSprite(this, arguments);
		this.sprites.push(sprite);
		return sprite;
	},
	anim: function(x, y, w, h, nbFrames, returnTo, loop, imgPath) {
		var anim = new Assets.assetAnim(this, arguments);
		this.anims.push(anim);
		return anim;
	},
	del: function(asset) {
		for (var i = 0, a; a = this.sprites[i]; ++i)
			if (a === asset) {
				this.sprites.splice(i, 1);
				break;
			}
		for (var i = 0, a; a = this.anims[i]; ++i)
			if (a === asset) {
				this.anims.splice(i, 1);
				break;
			}
	},
	// private
	findImg: function(imgPath) {
		var img, ind;
		if (imgPath === undefined)
			img = this.images[0];
		else if (!isNaN(ind = parseInt(imgPath)))
			img = this.images[ind];
		else
			for (var i = 0; img = this.images[i] && img.src !== imgPath; ++i) {}
		return img || null;
	},
	update: function() {
		for (var i = 0, a; a = this.anims[i]; ++i)
			a.update(this.time);
	}
};

// assetSprite ####################################
Assets.assetSprite = function(manager, args) {
	this.manager = manager;
	this.x       = args[0];
	this.y       = args[1];
	this.h       = args[2];
	this.w       = args[3];
	this.src     = manager.findImg(args[4]);
};
Assets.assetSprite.prototype = {
	// public
	draw: function(x, y) {
		this.manager.ctx.drawImage(
			this.src,
			this.x, this.y,
			this.w, this.h,
			x,      y,
			this.w, this.h
		);
	}
};

// assetAnim ####################################
Assets.assetAnim = function(manager, args) {
	this.framesAxe = 'xy'[args[4] > 0];
	this.nbFrames  = Math.abs(args[4]);
	this.returnTo  = args[5];
	this.loop      = args[6];
	this.frame     = this.returnTo === -1 ? -1 : 0;
	args[4]        = args[7];
	this.sprite    = new manager.assetSprite(manager, args);
	this.pause();
};
Assets.assetAnim.prototype = {
	// public
	draw: function(x, y) {
		if (this.frame > -1)
			this.sprite.draw(x, y);
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
			case 'x' : this.sprite.x += this.sprite.w * f; break;
			case 'y' : this.sprite.y += this.sprite.h * f; break;
		}
		this.frame += f;
	},
	update: function(time) {

	}
};
