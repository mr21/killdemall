function Canvas2D(el, images, fns) {
	var self    = this;
	this.ctx    = el.getContext('2d');
	this.fns    = fns;
	this.assets = new Assets(this, images);
	// active/inactive
	var active = false;
	el._addEvent('click', function(ev) {
		ev.stopPropagation();
		active = true;
		this._addClass('active');
	});
	document._addEvent('click', function() {
		active = false;
		el._delClass('active');
	});
	// keyboard
	var keyBool = [];
	if (fns.keydown) document._addEvent('keydown', function(e) { if (active && !keyBool[e = e.keyCode]) { keyBool[e] = 1; fns.keydown(e) }});
	if (fns.keyup)   document._addEvent('keyup',   function(e) { if (active &&  keyBool[e = e.keyCode]) { keyBool[e] = 0; fns.keyup  (e) }});
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
