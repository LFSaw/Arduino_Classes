

// Multiple Plots from multiple data sources in a single window
/*
ex.

m = DynamicMultiPlot.new("Multiplot", 800, 600, 620, 800, numplots: 3,
	plot_specs: [["GSR", 512, 0, 4095],["ECG", 254, 0, 1024]], numlines: 1, resize: 2, margin: 15, flow: 'right');


Plot spec: [title, numdatapoints, minval, maxval]


*/
DynamicMultiPlot {
	var <>plots, <compositeplot, <lines_per_plot, <plotspecs, <parentwin, margin;
	var plotheight;
	var maxpoints, <dataflow;

	*new {|name, xpos=0, ypos=0, width=500, height=800, plot_specs, num_lines=1,
		parent=nil, resize=2, margin=10, flow='right'|
		^super.new.init(name, xpos, ypos, width, height, plot_specs, num_lines, parent, resize, margin, flow);

	}


	init {|name, xpos, ypos, width, height, plot_specs, num_lines, parent, resize, marginsize, flow|
		var plot_y, plot_h;
		lines_per_plot = num_lines;
		margin = marginsize;
		dataflow = flow;
		plotspecs = plot_specs;
		plots = Array.newClear(plotspecs.size);
		Post << "PLOT SPECS: " << plot_specs << "  numlines " << lines_per_plot << " Plots: " << plots.size << $\n;
		if(parent.isNil) {
			parentwin = Window(name, Rect(xpos, ypos, width, height));
		} {
			parentwin = parent;
		};
		compositeplot = CompositeView(parentwin, Rect(0, 0, width, height)).resize_(resize);

		// Make the plots
		plot_h = (height / (plotspecs.size * num_lines)) - (margin);
		plotspecs.do {|spec, i|
			plot_y = (i * (plot_h + margin)) + margin;
			Post << "PLOT AT Y=" << plot_y << "  HEIGHT: " << plot_h << "  MARGIN: " << margin << $\n;
			plots[i] = PlotterBank.new(spec[0], spec[1], spec[2], spec[3],
				num_lines: num_lines, parent_view: compositeplot, xpos: 0, ypos: plot_y,
				linespacing: (((plotspecs.size - 1) * plot_h) + (plotspecs.size * margin)), plotwidth: width, plotheight: plot_h, flow: dataflow);
		};

		parentwin.front;
		parentwin.refresh;
	}

	add {|plotidx, datapoint|
		plots[plotidx].add(datapoint);
	}


	/*********
	* Identical to setProperties method of Plotter, except with a plotidx argument that chooses
	* which plot to set properties on.
	* The first argument should be the plotter index!
	**********/
	setProperties {|... args|
		plots[args[0]].setProperties(args[1..].asPairs);
	}

	close {
		parentwin.close;
		this.release;
	}

}


// A bank of plotters representing a datastream, split into a number of plotters
// without embedding in a window.
PlotterBank {
	var <plotters;
	var <databuf, <maxdatapoints, <dataflow;
	var <name, <y_max, <y_min, <plot_height, <points_per_plot;
	var last_update, redraw_delay_s; // used to throttle redraw rate

	*new {|name, numdatapoints=512, miny=0, maxy=1.0, num_lines=1,
		parent_view, xpos=0, ypos=0, linespacing=10, plotwidth, plotheight, flow='right'|
		^super.new.init(name, numdatapoints, miny, maxy, num_lines, parent_view, xpos, ypos, linespacing, plotwidth, plotheight, flow);
	}

	init {|name, numdatapoints, miny, maxy, num_lines, parent_view, xpos, ypos, linespacing, plotwidth, plotheight, flow|
		var plotx, ploty, startpoint, endpoint, tmp;
		last_update = Process.elapsedTime;
		redraw_delay_s = 20.reciprocal; // 20 fps
		maxdatapoints = numdatapoints;
		y_max = maxy; y_min = miny;
		plot_height = plotheight;
		dataflow = flow;
		databuf = Array.fill(maxdatapoints, {(y_max - y_min) / 2});
		points_per_plot = maxdatapoints / num_lines;
		plotters = Array.fill(num_lines, {|i|
			var pl, dg;
			plotx = xpos;
			ploty = ypos + (i * (linespacing + plotheight));
			startpoint = (i * points_per_plot).asInteger;
			endpoint = (startpoint + points_per_plot).asInteger;
			Post << "Make plotter at: (" << plotx << ", " << ploty << ") with dimensions " << plotwidth << " x " << plotheight << " parent: " << parent_view << " points per plot: " << points_per_plot << $\n;
			pl = Plotter.new(name, bounds: Rect(plotx, ploty, plotwidth, plotheight), parent: parent_view);
			parent_view.front;
			pl.value = databuf.copyRange(startpoint, endpoint);
			pl.findSpecs = false; // turn on/off autospec
			pl.specs = [[y_min, y_max, 'lin', 0.0001].asSpec];
			dg = pl.plots[0].drawGrid; // The DrawGrid of Plot 0, a DrawGrid is responsible
			// for drawing an X/Y grid on to a view.
			dg.x = dg.x.asDrawGridXTicks(1);
			dg.y = dg.y.asDrawGridYTicks(8);
			dg.opacity = 0.5;
			dg.font = Font.new("Arial", 8);
			pl;
		});
	}



	add {|datapoint|
		var startpt, endpt, now;
		databuf = databuf.add(datapoint);
		if(databuf.size > maxdatapoints) {
			databuf.removeAt(0);
		};

		now = Process.elapsedTime;
		// Throttle redraws to a frame rate in case data is coming in fast!
		if((now - last_update) > redraw_delay_s) {

		{
			if(dataflow == 'left') {
				plotters.do {|theplot, i|
					startpt = (i * points_per_plot).asInteger;
					endpt = (startpt + points_per_plot).asInteger;
					theplot.value = databuf[startpt..endpt];
				};
			} { // flow is going right
				plotters.do {|theplot, i|
					startpt = (points_per_plot * (plotters.size - i)).asInteger;
					endpt = (startpt - points_per_plot).asInteger;
					theplot.value = databuf[startpt..endpt];
				};
			};
		}.fork(AppClock);
		last_update = now;
	};
	}

	/*********
	* Identical to setProperties method of Plotter, except sets properties identically to all
	* plotters in the PlotterBank
	**********/
	setProperties {| ... pairs|
		plotters.do {|theplotter|
			theplotter.setProperties(pairs);
			theplotter.refresh;
		};
	}
}


// Plots live signal data
DynamicPlot {
	var <>plotters, <compositeplot, <lines, <parentwin, <name;
	var <>databuf;
	var maxpoints, <>dataflow;
	var last_update, redraw_delay_s; // used to throttle redraw rate

	*new {|name, maxdatapoints=500, xpos=0, ypos=0,	width=500, height=200, miny=0.0, maxy=1.0,
		numlines=1, parent=nil, resize=2, margin=10, flow='right'|
		^super.new.init(name, maxdatapoints, xpos, ypos, width, height, miny, maxy,
			numlines, parent, resize, margin, flow);

	}

	init {|thename, maxdatapoints, xpos, ypos, width, height, miny, maxy,
		numlines, parent, resize, margin, flow|
		var plotheight, plotpoints, start, stop, ploty, parentx=0, parenty=0;
		last_update = Process.elapsedTime;
		redraw_delay_s = 20.reciprocal; // 20 fps
		maxpoints = maxdatapoints;
		name = thename;
		lines = numlines;
		dataflow = flow;
		databuf = Array.fill(maxpoints, {(maxy - miny) / 2});
		plotters = Array.newClear(lines);
		if(parent.isNil) {
			parentwin = Window(name, Rect(xpos, ypos, width, height));
		} {
			parentwin = parent;
			parentx = xpos;
			parenty = ypos;
		};
		compositeplot = CompositeView(parentwin, Rect(parentx, parenty, width, height)).resize_(resize);
		plotheight = (height - (lines * margin)) / lines;
		plotpoints = maxpoints / lines;
		lines.do {|i|
			ploty = i * (plotheight + margin);
			start = i * plotpoints;
			stop = start + plotpoints;
			plotters.put(i, Plotter.new(name, bounds: Rect(0, ploty, width, plotheight), parent: compositeplot));
			plotters[i].value = databuf.copyRange(start.asInteger, stop.asInteger);
		};


		// If window is closed...
		parentwin.onClose = { "Closing Plot".postln; };
		parentwin.front;
		parentwin.refresh;

		this.configGrid(miny, maxy);
	}

	configGrid {|miny, maxy|
		var drawGrid;

		plotters.do {|theplot, i|
			theplot.findSpecs = false; // turn on/off autospec
			theplot.specs = [[miny, maxy, 'lin', 0.0001].asSpec];
			//plot.setProperties(\backgroundColor, Color.black, \plotColor, Color.green, \gridColorY, Color.white, \labelY, "Pulse", \gridLinePattern, );
			// Y AXIS SPEC SETTINGS
			//x.specs = [[0.0,1.0,\lin,0.0001].asSpec]; // set Y axis range
			drawGrid = theplot.plots[0].drawGrid; // The DrawGrid of Plot 0, a DrawGrid is responsible
			// for drawing an X/Y grid on to a view.

			drawGrid.x = drawGrid.x.asDrawGridXTicks(1);
			drawGrid.y = drawGrid.y.asDrawGridYTicks(8);
			//x.resolution = 1;
			//drawGrid.x.gridTicks = 1;
			//drawGrid.y.gridTicks = 8;
			drawGrid.opacity = 0.5;
			drawGrid.font = Font.new("Arial", 8);
		};
	}


	resize {|boundsrect|
		plotters[0].bounds = boundsrect;
		plotters[0].refresh;
	}

	add {|data|
		var plotpoints = maxpoints / lines, start, stop, now;
		databuf = databuf.add(data);
		if(databuf.size > maxpoints) {
			databuf.removeAt(0);
		};

		now = Process.elapsedTime;
		// Throttle redraws to a frame rate in case data is coming in fast!
		if((now - last_update) > redraw_delay_s) {
		{
			if(dataflow == 'left') {
				plotters.do {|theplot, i|
					start = (i * plotpoints).asInteger;
					stop = (start + plotpoints).asInteger;
					theplot.value = databuf[start..stop];
				};
			} {
				plotters.do {|theplot, i|
					start = (plotpoints * (lines - i)).asInteger;
					stop = (start - plotpoints).asInteger;
					theplot.value = databuf[start..stop];
				};
			};
			parentwin.refresh;
		}.fork(AppClock);
	};
	}

	close {
		parentwin.close();
	}
}


// Extensions to DrawGrid to allow changing the number of grid ticks.
// IMPROVE:  propose this functionality in DrawGrid be added in the next SC iteration.
DrawGridXTicks : DrawGridX {
	var <>gridTicks;


	// Method override to include variable grid ticks
	commands {
		var p;
		if(cacheKey != [range,bounds],{ commands = nil });
		^commands ?? {
			cacheKey = [range,bounds];
			commands = [];
			if(gridTicks.isNil) {
				p = grid.getParams(range[0],range[1],bounds.left,bounds.right);
			} {
				p = grid.getParams(range[0],range[1],bounds.left,bounds.right,gridTicks);
			};
			p['lines'].do { arg val;
				// value, [color]
				var x;
				val = val.asArray;
				x = val[0].linlin(range[0],range[1],bounds.left,bounds.right);
				commands = commands.add( ['strokeColor_',val[1] ? gridColor] );
				commands = commands.add( ['line', Point( x, bounds.top), Point(x,bounds.bottom) ] );
				commands = commands.add( ['stroke' ] );
			};
			if(bounds.width >= 12	,{
				commands = commands.add(['font_',font ] );
				commands = commands.add(['color_',fontColor ] );
				p['labels'].do { arg val;
					var x;
					// value, label, [color, font]
					if(val[2].notNil,{
						commands = commands.add( ['color_',val[2] ] );
					});
					if(val[3].notNil,{
						commands = commands.add( ['font_',val[3] ] );
					});
					x = val[0].linlin(range[0],range[1],bounds.left,bounds.right);
					commands = commands.add( ['stringAtPoint', val[1].asString, Point(x, bounds.bottom) + labelOffset ] );
				}
			});
			commands;
		}
	}

}


DrawGridYTicks : DrawGridY {
	var <>gridTicks;
	commands {
		var p;
		if(cacheKey != [range,bounds],{ commands = nil });
		^commands ?? {
			commands = [];

			if(gridTicks.isNil) {
				p = grid.getParams(range[0],range[1],bounds.top,bounds.bottom);
			} {
				p = grid.getParams(range[0],range[1],bounds.top,bounds.bottom,gridTicks);
			};
			p['lines'].do { arg val;
				// value, [color]
				var y;
				val = val.asArray;
				y = val[0].linlin(range[0],range[1],bounds.bottom,bounds.top);
				commands = commands.add( ['strokeColor_',val[1] ? gridColor] );
				commands = commands.add( ['line', Point( bounds.left,y), Point(bounds.right,y) ] );
				commands = commands.add( ['stroke' ] );
			};
			if(bounds.height >= 20	,{
				commands = commands.add(['font_',font ] );
				commands = commands.add(['color_',fontColor ] );
				p['labels'].do { arg val,i;
					var y;
					y = val[0].linlin(range[0],range[1],bounds.bottom,bounds.top);
					if(val[2].notNil,{
						commands = commands.add( ['color_',val[2] ] );
					});
					if(val[3].notNil,{
						commands = commands.add( ['font_',val[3] ] );
					});
					commands = commands.add( ['stringAtPoint', val[1].asString, Point(bounds.left, y) + labelOffset ] );
				}
			});
			commands;
		}
	}
}

+ DrawGridX {
	// Factory method. Returns a DrawGridXTicks which allows a variable number of tickmarks.
	asDrawGridXTicks {|numticks=nil|
		var result;
		result = DrawGridXTicks.new();
		result.grid = grid;
		result.bounds = bounds;
		result.range = range;
		result.gridTicks = numticks;
		^result;
	}
}
+ DrawGridY {
	// Factory method. Returns a DrawGridYTicks which allows a variable number of tickmarks.
	asDrawGridYTicks {|numticks=nil|
		var result;
		result = DrawGridYTicks.new();
		result.grid = grid;
		result.bounds = bounds;
		result.range = range;
		result.gridTicks = numticks;
		^result;
	}
}