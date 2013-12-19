KillDemAll.XShip = function() {
	KillDemAll.Ship.apply(this, arguments);
	this.sprites = {
		'base'   : KillDemAll.canvas2d.assets.sprite(17, 87, 22, 22),
		'top'    : KillDemAll.canvas2d.assets.sprite(87, 38, 16, 16),
		'part00' : KillDemAll.canvas2d.assets.sprite(21, 19, 25, 25),
		'part10' : KillDemAll.canvas2d.assets.sprite(49, 19, 25, 25),
		'part01' : KillDemAll.canvas2d.assets.sprite(21, 47, 25, 25),
		'part11' : KillDemAll.canvas2d.assets.sprite(49, 47, 25, 25)
	};
};
KillDemAll.XShip.prototype = new KillDemAll.Ship();
KillDemAll.XShip.prototype.render = function() {
	this.sprites.base  .draw(-11, -11);
	this.sprites.part00.draw(-23, -25);
	this.sprites.part10.draw( +0, -25);
	this.sprites.part01.draw(-23,  -2);
	this.sprites.part11.draw( +0,  -2);
	this.sprites.top   .draw( -7,  -9);
};
