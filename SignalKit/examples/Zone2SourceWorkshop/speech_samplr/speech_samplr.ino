
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
#include <VICTORIA_SOUND.h> // this is your sample file
#include <SKgsr.h>
#include <QuickSerial.h>


// Mozzi Config
#define AUDIO_MODE STANDARD
#define SEND_SERIAL 25 // comment this line to disable serial feedback, number is the serial tick rate in ms
#define SERIAL_BAUD 115200 // standard for Mozzi
#define AUDIO_RATE 16384
#define USE_AREF_EXTERNAL false

// Mozzi extras
#include <IntMap.h> // a faster version of Arduino's map
#include <Smooth.h> // smooth out AC interference
#include <Metronome.h> // used for sending serial data @ 20fps rather than send a data overload
#include <DCfilter.h> // a DC filter


#define CONTROL_RATE 64
#define GSRPIN A0
#define LEDPIN 8

// thresholding
#define LED_SIG_THRESH 300
#define DC_SIG_CENTER 2048

#define SMOOTHNESS 0.70 // float between 0.0-1.0 - where 1.0 is very smooth
SKgsr gsr(GSRPIN, SMOOTHNESS);


// DC filter for gsr
DCfilter dcGSR(0.95);

Metronome metro;
byte tickCounter = 0;

QuickSerial serial;
Metronome serialTick;
byte serialCounter = 0;

// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <VICTORIA_SOUND_NUM_CELLS, AUDIO_RATE> aSample(VICTORIA_SOUND_DATA);
Sample <VICTORIA_SOUND_NUM_CELLS, AUDIO_RATE> aSample2(VICTORIA_SOUND_DATA);

// Data cooking
IntMap map_gsr_metro(0, 4095, 2000, 300); 
IntMap map_gsr_gain(0, 4095, 4, 100); 
IntMap map_gsr_pitch(0, 4095, 70, 320); 


byte gain = 128;
uint16_t metro_rate_ms = 250;
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
  aSample.setFreq((float) VICTORIA_SOUND_SAMPLERATE / (float) VICTORIA_SOUND_NUM_CELLS); 
  aSample.setLoopingOn();
  aSample2.setFreq(12.0F * (float) VICTORIA_SOUND_SAMPLERATE / (float) VICTORIA_SOUND_NUM_CELLS); 
  metro.start(metro_rate_ms);
// metro ticks within resolution of CONTROL_RATE
}


void updateControl(){
  uint16_t gsrval;
  // read the ADC input for the biosensors & do any signal processing here
  gsr.readSample();
  // gsrval = gsr.oversampled;
  // remove DC offset
  gsrval = dcGSR.next(gsr.oversampled) + DC_SIG_CENTER; 

  //gsrval = gsr.oversampled;
  // gsrval = gsr.smoothed;


#ifdef SEND_SERIAL
  if(serialTick.ready()) {
    switch(serialCounter % 3) 
    {
      case 0: serial.write('G', gsr.oversampled); // raw gsr
      break;
      case 1: serial.write('S', gsrval); // DC removed
      break;
      case 2: serial.write('R', gsr.smoothed); // smoothed
      break;
    };
    serialCounter++;
  };
#endif  


  if(metro.ready()){
    // aSample.setFreq(playspeed*((float) VICTORIA_SOUND_SAMPLERATE / (float) VICTORIA_SOUND_NUM_CELLS));
    tickCounter++;
    //metro.set(metro_rate_ms);
    if(gsrval > (DC_SIG_CENTER + LED_SIG_THRESH) && (!aSample2.isPlaying())) {
      aSample2.start();
    }
  }

  gain = map_gsr_gain(gsrval);
  playspeed = map_gsr_pitch(gsrval) / 64.0F;
  //metro_rate_ms = map_gsr_metro(gsrval);
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
  //sig1 = (int)aSample.next();
  sig2 = (int)aSample2.next();
  return ((sig1 + sig2) * gain) >> 8;
}

void loop(){
  audioHook();
}



