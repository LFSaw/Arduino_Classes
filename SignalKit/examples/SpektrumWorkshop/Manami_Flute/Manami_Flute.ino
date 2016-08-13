
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
#include <MANAMI1_SOUND.h> // this is your sample file

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

SKgsr gsr(GSRPIN);

Metronome metro;
byte tickCounter = 0;

// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <MANAMI1_SOUND_NUM_CELLS, AUDIO_RATE> aSample(MANAMI1_SOUND_DATA);

// Data cooking
#define SMOOTHNESS 0.7
IntMap map_gsr_metro(0, 4095, 500, 100); 
IntMap map_gsr_gain(0, 4095, 20, 250); 
Smooth<uint16_t> smooth_gsr(SMOOTHNESS); // get rid of AC interference


byte gain = 128;
uint16_t metro_rate_ms = 500;
float playspeed = 1.0;

void setup(){
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
  aSample.setFreq((float) MANAMI1_SOUND_SAMPLERATE / (float) MANAMI1_SOUND_NUM_CELLS); 
  metro.start(metro_rate_ms);
// metro ticks within resolution of CONTROL_RATE
}


void updateControl(){
  uint16_t gsrval;
  float newspeed;
  // read the ADC input for the biosensors & do any signal processing here
  gsr.readSample();
  gsrval = smooth_gsr(gsr.oversampled);
  metro_rate_ms = map_gsr_metro(gsrval);

  
  if(metro.ready()){
    aSample.setFreq(playspeed*((float) MANAMI1_SOUND_SAMPLERATE / (float) MANAMI1_SOUND_NUM_CELLS));
    aSample.start();
    tickCounter++;
    metro.set(metro_rate_ms);
  };

  gain = map_gsr_gain(gsrval);
  playspeed = gain / 16.0F;
  /*
  if(gsrval > LED_SIG_THRESH) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  };
  */
}

int updateAudio(){
  return (((int)aSample.next()) * gain) >> 2;
}

void loop(){
  audioHook();
}



