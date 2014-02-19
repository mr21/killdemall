KillDemAll.scoring = {
	init: function() {
		this.dom = {};
		var domScore = document._domSelector('.scoring > span');
		for (var i = 0; d = domScore[i]; ++i)
			this.dom[d.className] = new DomIntIncrease(d._next());
	},
	reset: function() {
		for (var s in this.dom)
			this.dom[s].set(0, 1000);
	}
};
