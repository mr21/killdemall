KillDemAll.Map = function(assets) {
	this.sprites = {
		'ground' : assets.sprite(0, 0, 0, 0, 'css/ground.jpg')
	};
};
KillDemAll.Map.prototype = {
	render: function() {
		this.sprites.ground.draw(0, 0);
	}
};
