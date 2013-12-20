// Assets ####################################
function Assets(canvas2d, images) {
	this.ctx           = canvas2d.ctx;
	this.time          = canvas2d.time;
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
				canvas2d.launch();
		};
	}
	this.debug(false);
}
Assets.prototype = {
	// public
	debug: function(state) {
		this.debugging = state;
	},
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
Assets.assetSprite = function(assets, args) {
	this.assets = assets;
	this.x      = args[0];
	this.y      = args[1];
	this.w      = args[2];
	this.h      = args[3];
	this.src    = assets.findImg(args[4]);
};
Assets.assetSprite.prototype = {
	// public
	draw: function(x, y) {
		if (this.assets.debugging) {
			this.assets.ctx.fillStyle = 'rgba(255, 0, 0, 0.5)';
			this.assets.ctx.fillRect(x, y, this.w, this.h);
		}
		this.assets.ctx.drawImage(
			this.src,
			this.x, this.y,
			this.w, this.h,
			x,      y,
			this.w, this.h
		);
	}
};

// assetAnim ####################################
Assets.assetAnim = function(assets, args) {
	this.framesAxeX = args[4] > 0;
	this.nbFrames   = Math.abs(args[4]);
	this.returnTo   = args[5];
	this.loop       = args[6];
	this.frame      = this.returnTo === -1 ? -1 : 0;
	args[4]         = args[7];
	this.sprite     = new Assets.assetSprite(assets, args);
	this.timePrev   = assets.time.realTime;
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
			this.moveFrame(+1);
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
		this.frame += f;
		if (this.framesAxeX)
			this.sprite.x += this.sprite.w * f;
		else
			this.sprite.y += this.sprite.h * f;
	},
	update: function(time) {
		if (!this.playing) {
			this.timePrev = time.realTime;
		} else if (time.realTime - this.timePrev >= 0.040) {
			if (this.frame >= this.nbFrames - 1) {
				this.moveFrame(this.returnTo - this.nbFrames);
				this.rewind();
			} else {
				this.moveFrame(+1);
				this.timePrev = time.realTime;
			}
		}
	}
};
