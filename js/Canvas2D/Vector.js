function Vector2D(x, y) {
	this.set(
		x || 0,
		y || 0
	);
}
Vector2D.prototype = {
	set: function(x, y) {
		this.x = x;
		this.y = y;
	},
	add: function(v, y) {
		this.x += v.x || v;
		this.y += v.y || y;
	},
	norm: function() {
		return Math.sqrt(
			this.x * this.x +
			this.y * this.y
		);
	},
	normalize: function() {
		var n = this.norm();
		if (n) {
			this.x /= n;
			this.y /= n;
		}
	},
	show: function() {
		console.log('vector = {x:' + this.x + ', y:' + this.y + '}');
	}
};
