KillDemAll.Scoring = {
	init: function(ctx) {
		this.ctx = ctx;
		// DOM (HUD)
		this.dom = {};
		var domScore = document._domSelector('.scoring > span');
		for (var i = 0; d = domScore[i]; ++i)
			this.dom[d.className] = new DomIntIncrease(d._next());
		// Screen (ctx)
		this.numbers = [];
	},
	reset: function() {
		this.numbers.length = 0;
		for (var s in this.dom)
			this.dom[s].set(0, 1000);
	},
	newNumber: function(val, valMax, x, y) {
		this.numbers.push(new this.Number(this.ctx, val, valMax, x, y));
	},
	update: function(time) {
		for (var i = 0, t; t = this.numbers[i]; ++i)
			if (t.update(time))
				this.numbers.splice(i, 1);
	},
	render: function(ctx) {
		for (var i = 0, t; t = this.numbers[i]; ++i)
			t.render(ctx);
		ctx.globalAlpha = 1;
	}
};

KillDemAll.Scoring.Number = function(ctx, val, valMax, x, y) {
	this.x = x;
	this.y = y - 25;
	this.opacity = 1;
	this.marginTop = 0;
	this.size = (1 + val / valMax) * KillDemAll.Scoring.Number.SIZE;
	ctx.font = 'bold ' + this.size + 'px consolas';
	this.widthTxt = ctx.measureText(this.val).width / 2;
	this.val = '+' + val;
};

KillDemAll.Scoring.Number.SIZE = 11;
KillDemAll.Scoring.Number.DURATION = 2;

KillDemAll.Scoring.Number.prototype = {
	update: function(time) {
		this.opacity -= time.frameTime / KillDemAll.Scoring.Number.DURATION;
		this.marginTop = 3 * this.val * (1 - this.opacity);
		return this.opacity <= 0;
	},
	render: function(ctx) {
		ctx.globalAlpha = this.opacity;
		ctx.font = 'bold ' + (this.size + 0) + 'px consolas';
		ctx.fillStyle = "#9AFF5D";
		ctx.fillText(this.val, this.x - this.widthTxt, this.y - this.marginTop);
	}
};
