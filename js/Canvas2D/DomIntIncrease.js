function DomIntIncrease(elem) {
	// parsing de la value de depart
	var content    = elem.innerHTML;
	this.numWidth  = content.length;
	elem.innerHTML = '';
	for (var size = 0; size < content.length && isNaN(this.value = parseInt(content.substr(size))); ++size) {}
	if (isNaN(this.value))
		this.value = 0;
	this.fill(this.numWidth, content[0] >= 0 && content[0] <= 9 ? '0' : content[0]);
	// attributs
	this.valueTmp   = this.value;
	this.incr       = 0;
	this.timer      = 40;
	this.intervalId = null;
	this.nbFrames   = 0;
	// creation du DOM
	this.spanZeros = document.createElement('span'); this.spanZeros.className = 'zeros';
	this.spanValue = document.createElement('span'); this.spanValue.className = 'value';
	elem.appendChild(this.spanZeros, elem.parentNode);
	elem.appendChild(this.spanValue, elem.parentNode);
	// init
	this._set(this.value);
};

DomIntIncrease.prototype = {
	fill: function(width, c) {
		this.fillStr = '';
		this.valueMax = 1;
		while (--width >= 0) {
			this.fillStr += c;
			this.valueMax *= 10;
		}
		--this.valueMax;
	},
	add: function(val, duration) {
		this.set(this.value + val, duration);
	},
	set: function(val, duration) {
		if (val > this.valueMax)
			val = this.valueMax;
		this.value = val;
		window.clearInterval(this.intervalId);
		if (!duration) {
			this._set(val);
		} else {
			var self = this;
			this.nbFrames = Math.ceil(duration / this.timer);
			this.incr = (val - this.valueTmp) / this.nbFrames;
			this.intervalId = window.setInterval(function() {
				if (--self.nbFrames > 0) {
					self._set(self.valueTmp += self.incr);
				} else {
					self._set(self.valueTmp = self.value);
					window.clearInterval(self.intervalId);
				}
				self._set(self.valueTmp);
			}, this.timer);
		}
	},
	_set: function(val) {
		val = Math.floor(val);
		this.spanValue.innerHTML = val;
		var width = 1;
		while (parseInt(val /= 10))
			++width;
		this.spanZeros.innerHTML = this.fillStr.substr(width);
	}
};
