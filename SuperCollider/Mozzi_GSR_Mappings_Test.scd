/*******************************************

Demonstrates using QuickSerial to communicate with Arduino also using QuickSerial lib

Jonathan Reus-Brodsky

2016, 24 Jul - File Created

**************************************/


/*********************************************
USING QUICKSERIAL with Arduino Pro Mini
running Mozzi_GSR_Mappings_Test sketch
**********************************************/

// Set up Serial Connection
~serial = QuickSerial.new();
~plots = DynamicMultiPlot.new("SerialData", 800, 700, 400, 800, [["Raw GSR", 250, 0, 4095],["GSR Smooth", 250, 0, 4095],["Linear", 250, 0, 255],["Exponential", 250, 0, 255],["Log", 250, 0, 255]], 1, margin: 10, flow: 'left');
~serial.addResponder($G, {|val|
		~plots.add(0, val);
});
~serial.addResponder($S, {|val|
		~plots.add(1, val);
});
~serial.addResponder($M, {|val|
		~plots.add(2, val);
});
~serial.addResponder($E, {|val|
		~plots.add(3, val);
});
~serial.addResponder($L, {|val|
		~plots.add(4, val);
});

// Start the whole thing
~serial.startSerial(115200);
~serial.stopSerial;


/*********************************************
Without QuickSerial
Arduino running Mozzi_GSR_Serial_Test sketch
**********************************************/

SerialPort.devices;
~dev = SerialPort.devices[3]; // set device here
//p = SerialPort.new(~dev, baudrate: 9600, crtscts: false);
//p = SerialPort.new(~dev, baudrate: 9600, crtscts: true);
//p = SerialPort.new(~dev, baudrate: 115200, crtscts: true);
p = SerialPort.new(~dev, baudrate: 115200, crtscts: false);
~plot = DynamicMultiPlot.new("SerialData", 800, 800, 600, 800, [["Raw GSR", 200, 0, 4095],["GSR Smoothed", 200, 0, 4095]], 1, margin: 10, flow: 'left');
CmdPeriod.add({
r.stop;
p.close;
});



//Post << p.next.asAscii << $\n;



(
~post = false;
~graph = true;
~pause = 0.003;
r = {
	var startbyte=255, startbytes=0;
	var byte, datacode, byte1, byte2, result;
	inf.do {
		var bad_read = false;
		while({startbytes < 4}) {
			byte = p.read;
			if(byte == startbyte) {
				startbytes = startbytes+1;
			} {
				startbytes = 0;
			};
		};

		byte = p.read;
		datacode = byte.asAscii;
		if(datacode == $G) {
			result = "GSR";
		} {
			if(datacode == $S) {
				result = "SMOOTH";
			} {
				// Data should be thrown out!
				bad_read = true;

			};
		};

		// if bad_read==true, read until a valid datacode is found
		// else read in two bytes.
		while({bad_read == true}) {
			Post << "!!!!!   ERROR      BAD     READ   " << byte << "  !!!!!!!  \n";

			startbytes = 0;
			while({startbytes < 4}) {
				byte = p.read;
				if(byte == startbyte) {
					startbytes = startbytes+1;
				} {
					startbytes = 0;
				};
			};

			byte = p.read;
			datacode = byte.asAscii;
			if(datacode == $G) {
				result = "GSR";
				bad_read=false;
			};
			if(datacode == $S) {
				result = "SMOOTH";
				bad_read=false;
			};
		};

		// Read two bytes
		byte1 = p.read;
		byte2 = p.read;

		// Reset startbytes, looking for 4 x 255 again
		startbytes = 0;

		byte1 = (byte1 << 8) + byte2;
		if(~post) {
			Post << "RESULT: " << result << " INT: " << byte1 << $\n;
		};
		if(~graph) {
			if(datacode == $G) {
				~plot.add(0, byte1);
			};
			if(datacode == $S) {
				~plot.add(1, byte1);
			};
		};

		~pause.wait;
	};
}.fork;
);



~post = false;
~post = true;
~graph = true;
~graph = false;
~pause = 0.1; // too slow, will cause serial data to be missed!
~pause = 0.020; // 40x per second
~pause = 0.001; // maybe too fast for SC to handle, causes errors..


