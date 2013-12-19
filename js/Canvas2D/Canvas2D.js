function Canvas2D(el, images, fnInit, fnLoop) {
	var self    = this;
	this.ctx    = el.getContext('2d');
	this.fnInit = fnInit;
	this.fnLoop = fnLoop;
	this.assets = new Assets(this, images);
}
Canvas2D.prototype = {
	launch: function() {
		this.fnInit();
		var self      = this;
		this.time     = new Time();
		this.intervId = window.setInterval(function() {
			self.loop();
		}, 1000 / 40);
	},
	loop: function() {
		this.time.update();
		this.fnLoop();
		this.assets.update();
	},
	stop: function() {
		window.clearInterval(this.intervId);
	}
};
