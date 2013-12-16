killdemall.XShip = function() {
	killdemall.Ship.apply(this, arguments);
	this.sprites = {
		'base'   : killdemall.assetsManager.add(17, 87, 22, 22),
		'top'    : killdemall.assetsManager.add(58, 30, 16, 16),
		'part00' : killdemall.assetsManager.add( 5, 16, 23, 23),
		'part10' : killdemall.assetsManager.add(28, 16, 23, 23),
		'part01' : killdemall.assetsManager.add( 5, 39, 23, 23),
		'part11' : killdemall.assetsManager.add(28, 39, 23, 23)
	};
};

killdemall.XShip.prototype = new killdemall.Ship();

killdemall.XShip.prototype.render = function() {
	this.sprites.base  .draw(-11, -11);
	this.sprites.part00.draw(-23, -23);
	this.sprites.part10.draw( +0, -23);
	this.sprites.part01.draw(-23,  +0);
	this.sprites.part11.draw( +0,  +0);
	this.sprites.top   .draw( -7,  -9);
};
