


/*****
Tests with GUI classes
*****/
a = ((0 .. 1000) / 1000).mirror;


~start = 0;
~end = 10;
a[~start..~end];
a.copyRange(~start, ~end);

~start = 10;
~end = 0;
a[~start..~end];
a.copyRange(~start, ~end);


w = Window("MyNewWindow", Rect(20, 20, 800, 800));
c = CompositeView(w, Rect(0, 0, 800, 1000));
p = Plotter("Plotter-S1", Rect(0, 5, 800, 150), parent: c).value_(a[0..500]);
p.findSpecs = false;
p.specs = [[0.0, 1.0, 'lin', 0.0001].asSpec];
p = Plotter("Plotter-S2", Rect(0, 205, 800, 150), parent: c).value_(a[500..1000]);
p.findSpecs = false;
p.specs = [[0.0, 1.0, 'lin', 0.0001].asSpec];
p = Plotter("Plotter-S3", Rect(0, 405, 800, 150), parent: c).value_(a[1000..1500]);
p.findSpecs = false;
p.specs = [[0.0, 1.0, 'lin', 0.0001].asSpec];
p = Plotter("Plotter-S4", Rect(0, 605, 800, 150), parent: c).value_(a[1500..2000]);
p.findSpecs = false;
p.specs = [[0.0, 1.0, 'lin', 0.0001].asSpec];
w.front;



a = Slider2D(c, Rect(0, 0, 100, 100))
w.front

copyRange

a[0..10]

a[1000..1500]
a[1500..2000]

(0..100).size


/******
Tests with Dynamic Plots & Multiplots

*******/
// 1 line plot
d = DynamicPlot.new("GSR", 256, 818, 530, 620, 300, 0, 4095, numlines: 1);


// Multiline plot
d = DynamicPlot.new("GSR", 512, 818, 600, 620, 800, 0, 4095, numlines: 3, resize: 2, margin: 15, flow: 'right');
d.add(rand(4095));

// Multiline wide spacing plot
d = DynamicPlot.new("GSR", 512, 818, 600, 620, 800, 0, 4095, numlines: 3, resize: 2, margin: 150, flow: 'right');
d.add(rand(4095));


// Multiple plots in a single graph
m = DynamicMultiPlot.new("Multiplot", 800, 600, 620, 800, plot_specs: [["GSR", 512, 0, 4095],["ECG", 254, 0, 1024]], num_lines: 1, resize: 5, margin: 20, flow: 'right');

// Same graph, two lines per plot...
m = DynamicMultiPlot.new("Multiplot", 800, 600, 620, 800, plot_specs: [["GSR", 512, 0, 4095],["ECG", 254, 0, 1024]], num_lines: 2, resize: 5, margin: 20, flow: 'right');

// One more, three graphs, three lines...
m = DynamicMultiPlot.new("Multiplot", 800, 600, 620, 800, plot_specs: [["GSR", 512, 0, 4095],["ECG", 254, 0, 1024],["IBI", 254, 250, 2500]], num_lines: 2, resize: 2, margin: 15, flow: 'right');

m.add(0, rand(4095));


m = DynamicMultiPlot.new("Multiplot", 800, 600, 620, 800, plot_specs: [["GSR", 512, 0, 4095],["ECG", 254, 0, 1024],["IBI", 254, 250, 2500],["AMP", 254, 250, 2500]], num_lines: 2, resize: 2, margin: 15, flow: 'right');

Tdef(\plot, {
	inf.do {|i|
		m.add(0, rand(4095));
		m.add(1, rand(1024));
		m.add(2, rand(2500));
		m.add(3, rand(2500));
		0.1.wait;
	};
}).play;

m = DynamicMultiPlot.new("Multiplot", 800, 600, 620, 800, plot_specs: [["GSR", 512, 0, 4095],["ECG", 254, 0, 1024]], num_lines: 2, resize: 2, margin: 15, flow: 'right');




