KillDemAll.Scoring = {
	init: function(ctx) {
		this.ctx = ctx;
		// DOM (HUD)
		this.dom = {};
		var domScoring = document._domSelector('.canvasloth-hud-passive .scoring')[0];
		var domNumbers = domScoring._domSelector('.DomIntIncrease');
		for (var i = 0; d = domNumbers[i]; ++i)
			this.dom[d._prev().className] = new DomIntIncrease(d);
		this.accuracy.elem = domScoring._domSelector('.accuracy + b')[0];
		// Screen (ctx)
		this.numbers = [];
	},
	reset: function() {
		this.accuracy.shotsWin = 0;
		this.accuracy.elem.innerHTML = '100%';
		this.numbers.length = 0;
		for (var s in this.dom)
			this.dom[s].set(0, 1000);
	},
	accuracy: function(shotWin) {
		if (shotWin)
			++this.accuracy.shotsWin;
		var val = String(this.accuracy.shotsWin / this.dom['shots'].get() * 100),
			pt = val.indexOf('.');
		if (pt > -1)
			val = val.substr(0, pt + 2);
		this.accuracy.elem.innerHTML = val + '%';
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
	update: function(times) {
		this.opacity -= times.frame / KillDemAll.Scoring.Number.DURATION;
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
