/********************************************************

  Demo for using the QuickSerial Library
  & GSR SignalKit

  Sends basic data for GSR
  
  Jonathan Reus-Brodsky

  24, July 2016 - File Created
  
**********************************************************/

#include <MozziGuts.h>
#include <SKgsr.h>
#include <QuickSerial.h>

// Mozzi Config
#define AUDIO_MODE STANDARD
//#define AUDIO_MODE STANDARD_PLUS
//#define AUDIO_MODE HIFI
#define AUDIO_RATE 16384
//#define AUDIO_RATE 32768
//#define USE_AREF_EXTERNAL true
#define USE_AREF_EXTERNAL false

// Serial & Audio enable
#define SEND_SERIAL 4 // comment this line to disable serial feedback, 1 - basic GSR/ECG, 2 - Full ECG, 3 - Full GSR, 4 - mixed
#define PROCESS_AUDIO   // comment this line to disable audio
#define SERIAL_BAUD 115200 // standard for Mozzi
//#define SERIAL_BAUD 9600 

#define CONTROL_RATE 64 // powers of 2 please, 128 is better/faster than usual to help smooth CONTROL_RATE adsr interpolation
#define GSRPIN A0

SKgsr gsr(GSRPIN);
QuickSerial serial;

void setup(){
  serial.init(115200);
  delay(100); // don't use delay after starting Mozzi
  serial.println("Hello");
  delay(100);
  startMozzi(CONTROL_RATE); // start the sound engine
}

// MOZZI: interrupt routine every CONTROL_RATE times per second
void updateControl(){
  // read the ADC input for the biosensors & do any signal processing here
  gsr.readSample();
  
#ifdef SEND_SERIAL
  serial.write('G', gsr.oversampled);
  // Send other datapoints
  // serial.write('P', gsr.peak);
  // serial.write('A', gsr.activity);
#endif  
}

// MOZZI: update the audio frame here, audio rate interrupt handler
int updateAudio(){
#ifndef PROCESS_AUDIO
  // Skip audio processing
  return 0;
#endif

  // Do audio processing here
  return random(0, 255);
}

void loop(){
  audioHook(); // MOZZI: wraps audio-rate callback
}





