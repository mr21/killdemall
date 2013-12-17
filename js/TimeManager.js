function TimeManager() {
	this.reset();
	this.realTime  = this.startTime;
	this.frameTime = 0;
}
TimeManager.prototype = {
	update: function() {
		var d = new Date().getTime() / 1000;
		this.frameTime = d - this.realTime;
		this.realTime  = d;
		this.gameTime  = d - this.startTime;
	},
	reset: function() {
		this.startTime = new Date().getTime() / 1000;
		this.gameTime  = 0;
	}
};
