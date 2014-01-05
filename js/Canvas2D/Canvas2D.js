function Canvas2D(container, images, fns) {
	var self       = this;
	this.container = container;
	this.canvas    = container.getElementsByTagName('canvas')[0];
	this.ctx       = this.canvas.getContext('2d');
	this.fns       = fns;
	this.time      = new Time();
	this.assets    = new Assets(this, images);
	this.vectView  = new Vector2D(0, 0);
	// active/inactive
	var body = document.getElementsByTagName('body')[0];
	this.active = false;
	this.canvas._addEvent('click', function(ev) {
		ev.stopPropagation();
		self.active = true;
		body._addClass('Canvas2D_focus');
		self.container._addClass('active');
	});
	document._addEvent('click', function() {
		self.active = false;
		body._delClass('Canvas2D_focus');
		self.container._delClass('active');
	});
	this.canvas.click(); // tmp
	// create DOM pages
	this.pageCurr = null;
	this.domA_cross = document.createElement('a');
	this.domA_cross.href      = '#';
	this.domA_cross.className = 'cross';
	this.domA_cross.onclick   = function() { return self.closePage(), false };
	container.insertBefore(this.domA_cross, this.canvas);
}
Canvas2D.prototype = {
	debug: function(state) {
		this.assets.debug(state);
	},
	openPage: function(page) {
		if (page !== this.pageCurr) {
			this.closePage();
			this.page_animId = page._cssAnim(
				{css:'display',    val:'block'},
				{css:'opacity',    val:'1',   dur:500},
				{css:'top',        val:'0px', mov:'easeIn'},
				{elm:this.domA_cross, css:'top', val:'5px', del:500}
			);
			this.pageCurr = page;
		}
	},
	closePage: function() {
		if (this.pageCurr !== null) {
			document._cssAnimPause(this.page_animId);
			this.page_animId = this.pageCurr._cssAnim(
				{css:'opacity',    val:'0',     dur:250},
				{css:'top',        val:'-50px', mov:'easeIn'},
				{css:'display',    val:'none',  del:250},
				{elm:this.domA_cross, css:'top', val:'-16px', del:0}
			);
			this.pageCurr = null;

		}
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
		if (fns.mousedown) this.canvas._addEvent('mousedown', function(e) { if (self.active) fns.mousedown(e.layerX - self.vectView.x, e.layerY - self.vectView.y) });
		if (fns.mouseup)   this.canvas._addEvent('mouseup',   function(e) { if (self.active) fns.mouseup  (e.layerX - self.vectView.x, e.layerY - self.vectView.y) });
		if (fns.mousemove) this.canvas._addEvent('mousemove', function(e) { if (self.active) fns.mousemove(e.layerX - self.vectView.x, e.layerY - self.vectView.y, offsetMouse.xRel, offsetMouse.yRel) });
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
	getView: function()     { return this.vectView      },
	setView: function(x, y) { this.vectView.setXY(x, y) }
};
