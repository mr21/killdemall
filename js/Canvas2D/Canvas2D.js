function Canvas2D(el, images, fns) {
	var self      = this;
	this.elem     = el;
	this.ctx      = el.getContext('2d');
	this.fns      = fns;
	this.time     = new Time();
	this.assets   = new Assets(this, images);
	this.vectView = new Vector2D();
	// active/inactive
	this.active = false;
	el._addEvent('click', function(ev) {
		ev.stopPropagation();
		self.active = true;
		this._addClass('active');
	});
	document._addEvent('click', function() {
		self.active = false;
		el._delClass('active');
	});
	el.click(); // tmp
}
Canvas2D.prototype = {
	debug: function(state) {
		this.assets.debug(state);
	},
	launch: function() {
		var self = this;
		var fns  = this.fns;
		this.fns.load();
		// Events
		// -- keyboard
		var keyBool = [];
		if (fns.keydown) document._addEvent('keydown', function(e) { if (self.active && !keyBool[e = e.keyCode]) { keyBool[e] = 1; fns.keydown(e) }});
		if (fns.keyup)   document._addEvent('keyup',   function(e) { if (self.active &&  keyBool[e = e.keyCode]) { keyBool[e] = 0; fns.keyup  (e) }});
		// -- mouse
		if (fns.mousedown) this.elem._addEvent('mousedown', function(e) { if (self.active) fns.mousedown(e.layerX - self.vectView.x, e.layerY - self.vectView.y) });
		if (fns.mouseup)   this.elem._addEvent('mouseup',   function(e) { if (self.active) fns.mouseup  (e.layerX - self.vectView.x, e.layerY - self.vectView.y) });
		if (fns.mousemove) this.elem._addEvent('mousemove', function(e) { if (self.active) fns.mousemove(e.layerX - self.vectView.x, e.layerY - self.vectView.y, offsetMouse.xRel, offsetMouse.yRel) });
		this.time.reset();
		this.intervId = window.setInterval(function() {
			self.loop();
		}, 1000 / 40);
	},
	loop: function() {
		var time = this.time;
		var ctx  = this.ctx;
		this.time.update();
		this.fns.update(time);
		ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
		ctx.save();
			ctx.translate(this.vectView.x, this.vectView.y);
				this.fns.render(ctx);
		ctx.restore();
		this.assets.update();
	},
	stop: function() {
		window.clearInterval(this.intervId);
	},
	getView: function()     { return this.vectView    },
	setView: function(v, y) { this.vectView.set(v, y) }
};
