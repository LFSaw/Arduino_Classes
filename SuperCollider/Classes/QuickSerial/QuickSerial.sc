/*****************************************

QuickSerial

Jonathan Reus-Brodsky

Simple Arduino serial communication classes for interfacing with the QuickSerial Arduino Library.

Updated Jul 24, 2016 - created


****************************************/


QuickSerial {
	var <thread, <serialPort, <eventResponders;
	var <>postSerial = false;

	// The serial polling delay needs to be tweaked. Too long and the buffer backs up,
	// resulting in read errors. Too short and you're wasting CPU cycles in SuperCollider.
	var <>pollingDelay = 0.015; // a good general purpose value


	*new {
		^super.new.initme();
	}

	initme {
		CmdPeriod.add({
			this.stopSerial;
		});
		eventResponders = ();
	}


	/********************
	addResponder
	Add a function to respond to a given data id.

	data_code - The single character data code that will come from the Arduino to identify the data.
	responder_func - The function to call when data arrives under a given code. The function should take
	a single argument, which is the data point coming in over serial.
	*/
	addResponder {|data_code, responder_func|
		eventResponders.put(data_code, responder_func);
	}

	/*******
	startSerial
	Start the serial communication / create the connection.
	*******/
	startSerial {|baud=115200, devicePattern="/dev/tty.usbserial*"|
		var setup_serial_func;
		setup_serial_func = {
			var tmp = SerialPort.devicePattern;
			SerialPort.devicePattern = devicePattern;
			Post << "Opening Serial Port... " << SerialPort.devices[0] << $\n;
			serialPort = SerialPort.new(SerialPort.devices[0], baud, crtscts: false);
			Post << "Success!" << $\n;
			thread = {
				var startbyte=255, startbytes=0;
				var byte, datacode, byte1, byte2, responder, result;
				Post << "Starting Serial Polling Thread..." << $\n;
				inf.do {
					var bad_read = true;

					// read until a valid start code + datacode is found else read in two bytes.
					while({bad_read == true}) {
						startbytes = 0;
						while({startbytes < 4}) {
							byte = serialPort.read;
							if(byte == startbyte) {
								startbytes = startbytes+1;
							} {
								startbytes = 0;
							};
						};
						byte = serialPort.read;
						datacode = byte.asAscii;
						responder = eventResponders[datacode];
						if(responder.isNil) {
							// Data should be thrown out!
							bad_read = true;
							JUtil.debug("BAD READ " + byte.asString + " - bad data form or no such datacode !!!!", 1);
						} {
							bad_read = false;
						};
					};

					// Read two bytes
					byte1 = serialPort.read;
					byte2 = serialPort.read;
					// Reset startbytes, looking for 4 x 255 again
					startbytes = 0;
					byte1 = (byte1 << 8) + byte2;
					if(postSerial) {
						Post << datacode << "   " << byte1.trunc(0.00001) << $\n;
					};
					responder.value(byte1);
					pollingDelay.wait;
				};
			}.fork;
			SerialPort.devicePattern = tmp;
		};

		if(serialPort.notNil) {
			this.stopSerial(setup_serial_func);
		} {
			setup_serial_func.value;
		};

	}



	/*******
	serialReadIntAsString
	Read a string from the incoming serial data and return it as an integer.
	*******/
	serialReadStringAsInt {|line_end_byte=13|
		var byte, str="";
		while({byte = serialPort.read(); byte != line_end_byte}) {
			str = str ++ byte.asAscii;
		};
		^(str.asInteger);
	}


	/*******
	stopSerial
	Close the serial port and stop the serial reading routine

	finished_func - A function to evaluate once the serial connection has been successfully closed.
	**/
	stopSerial {|finished_func=nil|
		{
			if(thread.notNil) {
				thread.stop;
			};

			if(serialPort.notNil) {
				serialPort.close;
				Post << "Closing serial port ... ";
				while({serialPort.notNil && serialPort.isOpen}) {
					// Do nothing...
					0.2.wait;
					Post << ".";
				};
				Post << ".. Done" << $\n;
			};

			if(finished_func.notNil) {
				finished_func.value();
			};
		}.fork(SystemClock);
	}


}

