function Canvas2D(el, images, fns) {
	var self    = this;
	this.ctx    = el.getContext('2d');
	this.fns    = fns;
	this.assets = new Assets(this, images);
	// events
	el._addEvent('click', function(ev) {
		ev.stopPropagation();
		this._addClass('active');
	});
	document._addEvent('click', function() {
		el._delClass('active');
	});
}
Canvas2D.prototype = {
	launch: function() {
		this.fns.load();
		var self      = this;
		this.time     = new Time();
		this.intervId = window.setInterval(function() {
			self.loop();
		}, 1000 / 40);
	},
	loop: function() {
		this.time.update();
		this.fns.loop();
		this.assets.update();
	},
	stop: function() {
		window.clearInterval(this.intervId);
	}
};
