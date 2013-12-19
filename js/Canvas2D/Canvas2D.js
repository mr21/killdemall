function Canvas2D(el, images, fns) {
	var self    = this;
	this.ctx    = el.getContext('2d');
	this.fns    = fns;
	this.assets = new Assets(this, images);
	this.active = false;
	// events
	el._addEvent('click', function(ev) {
		ev.stopPropagation();
		self.active = true;
		this._addClass('active');
	});
	document._addEvent('click', function() {
		self.active = false;
		el._delClass('active');
	});
	// keyboard
	this.keyBool = [];
	if (fns.keydown) document._addEvent('keydown', function(e) { if (self.active && !self.keyBool[e.keyCode]) { self.keyBool[e.keyCode] = 1; fns.keydown(e.keyCode) }});
	if (fns.keyup)   document._addEvent('keyup',   function(e) { if (self.active &&  self.keyBool[e.keyCode]) { self.keyBool[e.keyCode] = 0; fns.keyup  (e.keyCode) }});
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
