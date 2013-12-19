KillDemAll.XShip = function() {
	KillDemAll.Ship.apply(this, arguments);
	this.sprites = {
		'base'   : KillDemAll.canvas2d.assets.sprite(17, 87, 22, 22),
		'top'    : KillDemAll.canvas2d.assets.sprite(58, 30, 16, 16),
		'part00' : KillDemAll.canvas2d.assets.sprite( 5, 16, 23, 23),
		'part10' : KillDemAll.canvas2d.assets.sprite(28, 16, 23, 23),
		'part01' : KillDemAll.canvas2d.assets.sprite( 5, 39, 23, 23),
		'part11' : KillDemAll.canvas2d.assets.sprite(28, 39, 23, 23)
	};
};
KillDemAll.XShip.prototype = new KillDemAll.Ship();
KillDemAll.XShip.prototype.render = function() {
	this.sprites.base  .draw(-11, -11);
	this.sprites.part00.draw(-23, -23);
	this.sprites.part10.draw( +0, -23);
	this.sprites.part01.draw(-23,  +0);
	this.sprites.part11.draw( +0,  +0);
	this.sprites.top   .draw( -7,  -9);
};
