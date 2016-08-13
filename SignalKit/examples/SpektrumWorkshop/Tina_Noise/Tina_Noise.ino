
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
#include <TINA_SOUND.h> // this is your sample file

#include <SKgsr.h>

// Mozzi Config
#define AUDIO_MODE STANDARD
#define AUDIO_RATE 16384
#define USE_AREF_EXTERNAL false

// Mozzi extras
#include <IntMap.h> // a faster version of Arduino's map
//#include <Smooth.h> // smooth out AC interference
#include <Metronome.h> // used for sending serial data @ 20fps rather than send a data overload
#include <ReverbTank.h>

#define CONTROL_RATE 64
#define GSRPIN A0
#define LEDPIN 8
#define LED_SIG_THRESH 1500

SKgsr gsr(GSRPIN);

Metronome metro;
byte tickCounter = 0;

// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <TINA_SOUND_NUM_CELLS, AUDIO_RATE> aSample(TINA_SOUND_DATA);

// Data cooking
#define SMOOTHNESS 0.7
IntMap map_gsr_metro(0, 4095, 5000, 1000); 
IntMap map_gsr_gain(0, 4095, 20, 100); 
IntMap map_gsr_feedback(0, 4095, 20, 120); 
//Smooth<uint16_t> smooth_gsr(SMOOTHNESS); // get rid of AC interference

ReverbTank reverb;

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
  aSample.setFreq((float) TINA_SOUND_SAMPLERATE / (float) TINA_SOUND_NUM_CELLS); 
  metro.start(metro_rate_ms);
// metro ticks within resolution of CONTROL_RATE

reverb.setFeebackLevel(115); // 127 dancing feedback
reverb.setEarlyReflections(120, 110, 120);
reverb.setLoopDelays(100, 100);
}


void updateControl(){
  uint16_t gsrval;
  // read the ADC input for the biosensors & do any signal processing here
  gsr.readSample();
//  gsrval = smooth_gsr(gsr.oversampled);
gsrval = gsr.oversampled;
  metro_rate_ms = map_gsr_metro(gsrval);

  if(metro.ready()){
    aSample.setFreq(playspeed*((float) TINA_SOUND_SAMPLERATE / (float) TINA_SOUND_NUM_CELLS));
    aSample.start();
    tickCounter++;
    metro.set(metro_rate_ms);
  };
  reverb.setFeebackLevel(map_gsr_feedback(gsrval)); // 127 dancing feedback
  gain = map_gsr_gain(gsrval);
  playspeed = gain / 32.0F;
  /*
  if(gsrval > LED_SIG_THRESH) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  };
  */
}

int updateAudio(){
  int verb, sig;
  sig = ((int)aSample.next() * gain) >> 8;
  verb = reverb.next(sig);
  return sig + verb;
}

void loop(){
  audioHook();
}



