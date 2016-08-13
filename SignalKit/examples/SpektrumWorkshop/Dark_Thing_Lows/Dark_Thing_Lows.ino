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
#include <tables/cos1024_int8.h> // sine table for oscillator
#include <IntMap.h> // a faster version of Arduino's map
#include <Metronome.h>
#include <mozzi_midi.h>
#include <Ead.h> // exponential attack/decay


// Serial & Audio enable
#define SEND_SERIAL 25 // comment this line to disable serial feedback, number is the serial tick rate in ms
#define PROCESS_AUDIO   // comment this line to disable audio
#define SERIAL_BAUD 115200 // standard for Mozzi
//#define SERIAL_BAUD 9600 

#define CONTROL_RATE 64 // powers of 2 please, 128 is better/faster than usual to help smooth CONTROL_RATE adsr interpolation
#define GSRPIN A0
#define LEDPIN 8
#define LED_SIG_THRESH 1800
#define SMOOTHNESS 0.70 // float between 0.0-1.0 - where 1.0 is very smooth

SKgsr gsr(GSRPIN, SMOOTHNESS);

QuickSerial serial;
Metronome serialTick;
byte serialCounter = 0;

// notes to play depending on whether temperature reading increases or decreases
float upnotes[] = { mtof(59.f),mtof(61.f), mtof(66.f), mtof(68.f)};

//float upnotes[] = { mtof(42.f),mtof(44.f),mtof(50.f),mtof(52.f),mtof(59.f),mtof(61.f), mtof(66.f), mtof(68.f)};

float downnotes[] = {
  mtof(64.f),mtof(65.f),mtof(88.f),mtof(72.f),mtof(79.f),mtof(84.f),mtof(86.f),mtof(89.f)};


// Oscillators
// MOZZI: Oscillators, Filters, Delays
// harmonics
Oscil<COS1024_NUM_CELLS, AUDIO_RATE> aCos1(COS1024_DATA);
Oscil<COS1024_NUM_CELLS, AUDIO_RATE> aCos2(COS1024_DATA);
Oscil<COS1024_NUM_CELLS, AUDIO_RATE> aCos3(COS1024_DATA);
Oscil<COS1024_NUM_CELLS, AUDIO_RATE> aCos4(COS1024_DATA);

// volume controls
Oscil<COS1024_NUM_CELLS, CONTROL_RATE> kVol1(COS1024_DATA);
Oscil<COS1024_NUM_CELLS, CONTROL_RATE> kVol2(COS1024_DATA);
Oscil<COS1024_NUM_CELLS, CONTROL_RATE> kVol3(COS1024_DATA);
Oscil<COS1024_NUM_CELLS, CONTROL_RATE> kVol4(COS1024_DATA);

Ead kEnv(CONTROL_RATE); // resolution is CONTROL_RATE
Ead kEnv1(CONTROL_RATE);
uint8_t env_gain = 0;   // globally accessible gain value from the envelope


uint8_t vol1, vol2, vol3, vol4, vol_swell = 0, vol_ostinato1 = 0, vol_ostinato2 = 0;

// Control Data Processing
#define FREQ_CHANGE_THRESH 10 // volume where a note change may happen
#define EDA_MIN 200
#define EDA_MAX 2500

#define EDA_THRESH 2000 // GSR val where a frequency change happens
IntMap map_gsr_freq(0, 4095, 580, 2580); 
IntMap map_gsr_gain(0, 4095, 2, 20); 
const IntMap map_eda_to_volume(EDA_MIN, EDA_MAX, 0, 180); 
const IntMap map_responses_to_volume_short(1, 10, 0, 255); 
const IntMap map_responses_to_volume_long(1, 50, 0, 255); 
const IntMap map_ecg_freq(1700, 2500, 150, 400);
const IntMap map_12bit_8bit(500, 2500, 0, 255);

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
  // Set frequencies of oscillators
  aCos1.setFreq(upnotes[0]);
  aCos2.setFreq(upnotes[1]);
  
  aCos3.setFreq(downnotes[4]);
  aCos4.setFreq(downnotes[2]);
  
  // Set frequencies of modulators
  kVol1.setFreq(0.56f);
  kVol2.setFreq(0.31f);
  
  kVol3.setFreq(4);
  kVol4.setFreq(7);
  
  startMozzi(CONTROL_RATE); // start the sound engine
}


// MOZZI: interrupt routine every CONTROL_RATE times per second
void updateControl(){
  uint16_t gsrval;
  // read the ADC input for the biosensors & do any signal processing here
  gsr.readSample();
  
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

  static uint8_t osc = 0, f_mod = 0, notes;
  if(gsr.smoothed > EDA_THRESH) {
    osc = random(0, 3); 
    switch(osc) {
      case 0:
        if(abs(vol1) < FREQ_CHANGE_THRESH) {
          notes = random(0, 2);
          aCos1.setFreq(upnotes[notes]);
        };
      break;
      case 1:
        if(abs(vol2) < FREQ_CHANGE_THRESH) {
          notes = random(0, 2);
          aCos2.setFreq(upnotes[notes]);
        };
      break;
      case 2:
        if(abs(vol3) < FREQ_CHANGE_THRESH) {
          f_mod = random(0, 14);
          kVol3.setFreq(f_mod);
        };
      break;
      case 3:
        if(abs(vol4) < FREQ_CHANGE_THRESH) {
          f_mod = random(0, 14);
          kVol4.setFreq(f_mod);
        };
      break;
    };
  };

  vol1 = kVol1.next();
  vol2 = kVol2.next();
  vol3 = kVol3.next();
  vol4 = kVol4.next();
  
  vol_swell = map_eda_to_volume(constrain(gsr.smoothed, EDA_MIN, EDA_MAX)); // swell volume is tracked by direct EDA values
  vol_ostinato1 = constrain(map_responses_to_volume_short(gsr.smoothed), 0, 255); // maps eda activity to ostinato volume
  vol_ostinato2 = constrain(map_responses_to_volume_long(gsr.smoothed), 0, 255); // maps eda activity to ostinato volume

  if(gsr.smoothed > LED_SIG_THRESH) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }
}

// MOZZI: update the audio frame here, audio rate interrupt handler
int updateAudio(){
  int sig;
  long swell = (long) aCos1.next()*vol1 + (long) aCos2.next()*vol2;
  swell = (swell * vol_swell) >> 8; // shift to audio output range
  //long ostinato = (long) aCos3.next()*vol3*vol_ostinato1 + (long) aCos4.next()*vol4*vol_ostinato2;
  //ostinato = ostinato >> 8;
  int mix = (int)swell >> 8; //((swell + ostinato) >> 8); 
  return mix;
}

void loop(){
  audioHook(); // MOZZI: wraps audio-rate callback
}





