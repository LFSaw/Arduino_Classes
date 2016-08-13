/********************************************************

  Demo connecting Mozzi to a GSR signal &
  reporting using serial.

  Uses a combination of Mozzi, SignalKit and QuickSerial

  Also flickers the LED
  
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

// Mozzi extras
#include <Oscil.h> // oscillator templates
#include <tables/sin2048_int8.h> // 2048 sample sine wavetable
#include <IntMap.h> // a faster version of Arduino's map
#include <Smooth.h> // smooth out AC interference
#include <Metronome.h>

// Serial & Audio enable
#define SEND_SERIAL 25 // comment this line to disable serial feedback, number is the serial tick rate in ms
#define PROCESS_AUDIO   // comment this line to disable audio
#define SERIAL_BAUD 115200 // standard for Mozzi
//#define SERIAL_BAUD 9600 

#define CONTROL_RATE 64 // powers of 2 please, 128 is better/faster than usual to help smooth CONTROL_RATE adsr interpolation
#define GSRPIN A0
#define LEDPIN 8
#define LED_SIG_THRESH 2000

SKgsr gsr(GSRPIN);

QuickSerial serial;
Metronome serialTick;
byte serialCounter = 0;

// Oscillator
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sin0(SIN2048_DATA);

// Control Data Processing
#define SMOOTHNESS 0.70 // float between 0.0-1.0 - where 1.0 is very smooth

IntMap map_gsr_freq(0, 4095, 70, 580); 
IntMap map_gsr_gain(0, 4095, 255, 20); 
Smooth<uint16_t> smooth_gsr(SMOOTHNESS); // get rid of AC interference

byte gain = 0;

void setup(){
#ifdef SEND_SERIAL
  serial.init(SERIAL_BAUD);
  delay(100); // don't use delay after starting Mozzi
  serial.println("Hello");
  serialTick.start(SEND_SERIAL);
#endif
  pinMode(LEDPIN, OUTPUT);
  delay(100);
  // Startup Signal
  for(int i = 0; i < 10; i++) {
    digitalWrite(LEDPIN, HIGH);
    delay(100);
    digitalWrite(LEDPIN, LOW);
    delay(50);
  }
  
  startMozzi(CONTROL_RATE); // start the sound engine
}


// MOZZI: interrupt routine every CONTROL_RATE times per second
void updateControl(){
  uint16_t gsrval;
  // read the ADC input for the biosensors & do any signal processing here
  gsr.readSample();
  gsrval = smooth_gsr(gsr.oversampled);
  
#ifdef SEND_SERIAL
  if(serialTick.ready()) {
    switch(serialCounter % 2) 
    {
      case 0: serial.write('G', gsr.oversampled); // raw gsr
      break;
      case 1: serial.write('S', gsrval); // smoothed
      break;
    };
    serialCounter++;
  };
#endif  

  // Set the frequency of the oscillator
  sin0.setFreq(map_gsr_freq(gsrval));
  gain = map_gsr_gain(gsr.oversampled);

  if(gsr.oversampled > LED_SIG_THRESH) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }
}

// MOZZI: update the audio frame here, audio rate interrupt handler
int updateAudio(){
  int sig;
#ifndef PROCESS_AUDIO
  // Skip audio processing
  return 0;
#endif
  sig = sin0.next();
  //sig = random(-32000, 32000);
  // Do audio processing here
  return (sig * gain) >> 8;
}

void loop(){
  audioHook(); // MOZZI: wraps audio-rate callback
}





