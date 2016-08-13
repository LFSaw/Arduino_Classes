
/*  Example of playing a sampled sound,
    using Mozzi sonification library.
  
    Demonstrates one-shot samples scheduled
    with EventDelay.
  
    Circuit: Audio output on digital pin 9 on a Uno or similar, or
  
    Mozzi help/discussion/announcements:
    https://groups.google.com/forum/#!forum/mozzi-users
  
    Tim Barrass 2012, CC by-nc-sa.
*/

#include <MozziGuts.h>
#include <Sample.h> // Sample template
#include <SUSANNE_SOUND.h> // this is your sample file
#include <QuickSerial.h>
#include <SKgsr.h>

// Mozzi Config
#define AUDIO_MODE STANDARD
#define AUDIO_RATE 16384
#define USE_AREF_EXTERNAL false

// Mozzi extras
#include <IntMap.h> // a faster version of Arduino's map
#include <Smooth.h> // smooth out AC interference
#include <Metronome.h> // used for sending serial data @ 20fps rather than send a data overload

#define CONTROL_RATE 64
#define GSRPIN A0
#define LEDPIN 8
#define LED_SIG_THRESH 1500
#define SEND_SERIAL 25 // comment this line to disable serial feedback, number is the serial tick rate in ms
#define SMOOTHNESS 0.7
#define SERIAL_BAUD 115200 // standard for Mozzi


QuickSerial serial;
Metronome serialTick;
byte serialCounter = 0;


SKgsr gsr(GSRPIN, SMOOTHNESS);

Metronome metro;
byte tickCounter = 0;

// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <SUSANNE_SOUND_NUM_CELLS, AUDIO_RATE> aSample(SUSANNE_SOUND_DATA);
Sample <SUSANNE_SOUND_NUM_CELLS, AUDIO_RATE> aSample2(SUSANNE_SOUND_DATA);

// Data cooking
IntMap map_gsr_metro(0, 4095, 1000, 300); 
IntMap map_gsr_gain(0, 4095, 30, 100); 
IntMap map_gsr_pitch(0, 4095, 50, 120); 


byte gain = 128;
uint16_t metro_rate_ms = 500;
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
  // Startup Signal
  for(int i = 0; i < 10; i++) {
    digitalWrite(LEDPIN, HIGH);
    delay(100);
    digitalWrite(LEDPIN, LOW);
    delay(50);
  }

  startMozzi(CONTROL_RATE);
  // play at the speed it was recorded
  aSample.setFreq((float) SUSANNE_SOUND_SAMPLERATE / (float) SUSANNE_SOUND_NUM_CELLS); 
  aSample.setLoopingOn();
  aSample2.setFreq(3.0F * (float) SUSANNE_SOUND_SAMPLERATE / (float) SUSANNE_SOUND_NUM_CELLS); 
  //metro.start(metro_rate_ms);
// metro ticks within resolution of CONTROL_RATE
}


void updateControl(){
  uint16_t gsrval;
  // read the ADC input for the biosensors & do any signal processing here
  gsr.readSample();
  gsrval = gsr.oversampled;

#ifdef SEND_SERIAL
  if(serialTick.ready()) {
    switch(serialCounter % 2) 
    {
      case 0: serial.write('G', gsr.oversampled); // raw gsr
      break;
      case 1: serial.write('S', gsr.smoothed); // smoothed
      break;
    };
    serialCounter++;
  };
#endif  


  if(metro.ready()){
    aSample.setFreq(playspeed*((float) SUSANNE_SOUND_SAMPLERATE / (float) SUSANNE_SOUND_NUM_CELLS));
    tickCounter++;
    metro.set(metro_rate_ms);
    if(gsrval > LED_SIG_THRESH) {
      aSample2.start();
    }
  }

  gain = map_gsr_gain(gsrval);
  playspeed = map_gsr_pitch(gsrval) / 64.0F;
  /*
  if(gsrval > LED_SIG_THRESH) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  };
  */
}

int updateAudio(){
  int sig1, sig2;
  sig1 = (int)aSample.next();
  sig2 = (int)aSample2.next();
  return ((sig1 + sig2) * gain) >> 8;
}

void loop(){
  audioHook();
}



