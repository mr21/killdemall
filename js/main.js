function lg(s) { console.log(s) }

var killdemall = {
	init: function() {
		var self     = this;
		this.ctx     = document.getElementsByTagName('canvas')[0].getContext('2d');
		this.png     = new Image();
		this.png.src = 'css/sprites.png';
		this.timeManager = new TimeManager();
		this.png.onload = function() {
			self.assetsManager = new AssetsManager(self.ctx, self.timeManager, this);
			self.xship_01 = new self.XShip();
			self.intervId = window.setInterval(function() {
				self.loop();
			}, 1000/40);
		};
	},
	loop: function() {
		this.timeManager.update();
		this.render();
		this.assetsManager.update();
	},
	render: function() {
		var ctx = this.ctx;
		ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
		ctx.save();
			ctx.translate(100, 100);
				this.xship_01.render();
		ctx.restore();
	}
};

window.onload = function() {
	killdemall.init();
};
