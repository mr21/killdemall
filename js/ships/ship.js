killdemall.Ship = function() {
	this.sprites;
	this.vPos  = {x:0, y:0};
	this.vMove = {x:0, y:0};
};

killdemall.Ship.prototype = {
	core: function() {
		lg('ship.core()');
	},
	render: function() {
		lg('ship.render()');
	}
};
