function AssetsManager(ctx, src) {
	this.ctx    = ctx;
	this.src    = src;
	this.assets = [];
}
AssetsManager.prototype.add = function(x, y, w, h, nbFrames, repeatAt) {
	var asset = nbFrames
		? new AssetsManager.anim (this, x, y, w, h, nbFrames, repeatAt)
		: new AssetsManager.image(this, x, y, w, h);
	this.assets.push(asset);
	return asset;
};

AssetsManager.image = function(manager, x, y, w, h) {
	this.manager = manager;
	this.x = x;
	this.y = y;
	this.h = h;
	this.w = w;
};
AssetsManager.image.prototype.draw = function(x, y) {
	this.manager.ctx.drawImage(
		this.manager.src,
		this.x, this.y,
		this.w, this.h,
		x,      y,
		this.w, this.h
	);
};

AssetsManager.anim = function(manager, x, y, w, h, nbFrames, repeatAt) {
	AssetsManager.image.apply(this, arguments);
	this.nbFrames = nbFrames;
	this.repeatAt = repeatAt;
};
AssetsManager.anim.prototype = new AssetsManager.image();
AssetsManager.anim.prototype.draw = function(x, y) {
	AssetsManager.image.draw.apply(this, arguments);
};
