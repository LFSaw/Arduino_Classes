/********
SKecg.h - Library for reading ECG Data & Extracting useful information from it.
Created by Jonathan Reus-Brodsky, March 15, 2016
Released into the public domain.

Following the tutorial found @
http://playground.arduino.cc/Code/Library
http://stackoverflow.com/questions/1735990/using-classes-with-the-arduino

**/

#ifndef SKecg_H
#define SKecg_H

#include <Arduino.h>
#include <MozziGuts.h>
#include <OverSample.h>   
// Oversampling for analog input signals, from Mozzi
//      http://sensorium.github.io/Mozzi/doc/html/class_over_sample.html#details


class SKecg {
public:
  // Public signal features
  // NOTE: Make some of these volatile if they are being used within interrupts.
  #define ECG_AVG_SAMPLES 64 
  uint16_t raw, oversampled; // Raw (0-1023) & Oversampled (0-4095) ECG Values
  uint16_t ibi; // inter-beat-interval (period in millis)
  uint16_t amp; // ecg peak amplitude (0-1023)
  uint8_t bpm; // ecg calculated beats per minute
  uint16_t hrv; // ecg heart rate variation
  boolean pulse; // true if a pulse is happening
  
  // Public methods
  SKecg(uint8_t inPin);
  ~SKecg();
  uint16_t readSample();

private:
  uint8_t _adcPin;
  uint32_t lastBeatTime;
  uint16_t peak, trough, thresh; // used for detecting heartbeats, even as they fluxuate in amplitude
  uint16_t rate[10]; // holds the last 10 IBI values
  boolean firstBeat, secondBeat; // used to detect the first two beats
  // MOZZI: Signal Processing & Mapping
  // Oversampling smooths the signal as a bonus!
  OverSample <uint16_t, 2> oversampler; // gives 10+2=12 bit resolution 0->4095, using 32 bytes of memory

  // Internal methods
  void analyzeData();


};

#endif
