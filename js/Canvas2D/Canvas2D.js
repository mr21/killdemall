function Canvas2D(el, images, fns) {
	var self      = this;
	this.ctx      = el.getContext('2d');
	this.fns      = fns;
	this.time     = new Time();
	this.assets   = new Assets(this, images);
	this.vectView = new Vector2D();
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
	el.click(); // tmp
	// keyboard
	var keyBool = [];
	if (fns.keydown) document._addEvent('keydown', function(e) { if (active && !keyBool[e = e.keyCode]) { keyBool[e] = 1; fns.keydown(e) }});
	if (fns.keyup)   document._addEvent('keyup',   function(e) { if (active &&  keyBool[e = e.keyCode]) { keyBool[e] = 0; fns.keyup  (e) }});
	// mouse
	if (fns.mousedown) el._addEvent('mousedown', function(e) { if (active) fns.mousedown(e.layerX, e.layerY) });
	if (fns.mouseup)   el._addEvent('mouseup',   function(e) { if (active) fns.mouseup  (e.layerX, e.layerY) });
	if (fns.mousemove) el._addEvent('mousemove', function(e) { if (active) fns.mousemove(e.layerX, e.layerY, offsetMouse.xRel, offsetMouse.yRel) });
}
Canvas2D.prototype = {
	debug: function(state) {
		this.assets.debug(state);
	},
	launch: function() {
		var self = this;
		this.fns.load();
		this.time.reset();
		this.intervId = window.setInterval(function() {
			self.loop();
		}, 1000 / 40);
	},
	loop: function() {
		this.time.update();
		this.fns.update();
		this.ctx.save();
			this.ctx.translate(this.vectView.x, this.vectView.y);
				this.fns.render();
		this.ctx.restore();
		this.assets.update();
	},
	stop: function() {
		window.clearInterval(this.intervId);
	},
	setView: function(x, y) {
		this.vectView.set(x, y);
	}
};
