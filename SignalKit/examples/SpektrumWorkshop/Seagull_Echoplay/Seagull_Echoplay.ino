/********************************************************

  Connecting Mozzi to a GSR signal & using signal cooking to produce
  effects. 

  Reporting data using serial.

  Uses a combination of Mozzi, SignalKit and QuickSerial

  Also triggers the LED according to certain conditions.
  
  Jonathan Reus-Brodsky

  9, Aug 2016 - File Created
  
**********************************************************/

#include <MozziGuts.h>
#include <Sample.h>
#include <Seagull01.h>

#include <SKgsr.h>
#include <QuickSerial.h>

// Mozzi Config
#define AUDIO_MODE STANDARD
#define AUDIO_RATE 16384
#define USE_AREF_EXTERNAL false

// Mozzi extras
#include <IntMap.h> // a faster version of Arduino's map
#include <Metronome.h>

#include <mozzi_midi.h>
#include <Ead.h> // exponential attack/decay


#define SEND_SERIAL 25 // comment this line to disable serial feedback, number is the serial tick rate in ms
#define SERIAL_BAUD 115200 // standard for Mozzi
#define CONTROL_RATE 64 // powers of 2 please, 128 is better/faster than usual to help smooth CONTROL_RATE adsr interpolation
#define GSRPIN A0
#define LEDPIN 8
#define LED_SIG_THRESH 2000
#define SMOOTHNESS 0.7 // 0.0 no smoothing, 1.0 lots of smoothing

SKgsr gsr(GSRPIN, SMOOTHNESS);

#ifdef SEND_SERIAL
QuickSerial serial;
Metronome serialTick;
byte serialCounter = 0;
#endif

// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <Seagull01_NUM_CELLS, AUDIO_RATE> aSample1(Seagull01_DATA);

// Timing
Metronome metro;
byte tickCounter = 0;


// Data cooking
IntMap map_gsr_metro(0, 4095, 2000, 50); 
IntMap map_gsr_gain(0, 4095, 20, 50); 
IntMap map_gsr_pitch(0, 4095, 1, 40); 


Ead kEnv(CONTROL_RATE); // resolution is CONTROL_RATE
Ead kEnv1(CONTROL_RATE);
uint8_t env_gain = 0;   // globally accessible gain value from the envelope

byte gain = 128;
uint16_t metrorate_ms = 500;
float playspeed = 1.0;

void setup(){
#ifdef SEND_SERIAL
  serial.init(SERIAL_BAUD);
  delay(100); // don't use delay after starting Mozzi
  serial.println("Hello");
  serialTick.start(SEND_SERIAL);
#endif

  pinMode(LEDPIN, OUTPUT);
  delay(100);
  // Hello world
  for(int i = 0; i < 10; i++) {
    digitalWrite(LEDPIN, HIGH);
    delay(100);
    digitalWrite(LEDPIN, LOW);
    delay(50);
  }
  
  startMozzi(CONTROL_RATE); // start the sound engine
  // play at the speed it was recorded
  aSample1.setFreq((float) Seagull01_SAMPLERATE / (float) Seagull01_NUM_CELLS); 
  //aSample1.setLoopingOn();
  aSample1.start();
  metro.start(metrorate_ms);
}


// MOZZI: interrupt routine every CONTROL_RATE times per second
void updateControl(){
  gsr.readSample();
#ifdef SEND_SERIAL
  if(serialTick.ready()) {
    reportSerial();
    serialCounter++;
  };
#endif
  doControl();
  doLEDFeedback();
}

// MOZZI: update the audio frame here, audio rate interrupt handler
int updateAudio(){
  int sig1, sig2;
  sig1 = (int)aSample1.next();
  //sig2 = (int)aSample2.next();
  //return ((sig1 + sig2) * gain) >> 8;
  return sig1 * gain;
}

// Control data & parameter manipulations go here
void doControl() {
  if(metro.ready()){
    aSample1.setFreq(playspeed*((float) Seagull01_SAMPLERATE / (float) Seagull01_NUM_CELLS));
    aSample1.start();
    tickCounter++;
    metro.set(metrorate_ms);
  }
  
  gain = map_gsr_gain(gsr.smoothed);
  playspeed = map_gsr_pitch(gsr.smoothed) / 128.0F; 
  metrorate_ms = map_gsr_metro(gsr.smoothed);
}

// Serial data reporting goes here
void reportSerial() {
    switch(serialCounter % 2) 
    {
      case 0: serial.write('G', gsr.oversampled); // raw gsr
      break;
      case 1: serial.write('S', gsr.smoothed); // smoothed
      break;
    };
}

// Led feedback conditions go here
void doLEDFeedback() {
  // Led feedback condition
  if(gsr.smoothed > LED_SIG_THRESH) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  };
}

void loop(){
  audioHook(); // MOZZI: wraps audio-rate callback
}





