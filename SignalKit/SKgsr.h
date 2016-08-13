/********
SKgsr.h - Library for reading EDA Data & Extracting useful information from it.
Created by Jonathan Reus-Brodsky, March 15, 2016
Released into the public domain.

Following the tutorial found @
http://playground.arduino.cc/Code/Library
http://stackoverflow.com/questions/1735990/using-classes-with-the-arduino

**/

#ifndef SKgsr_H
#define SKgsr_H

#include <Arduino.h>

// Oversampling for analog input signals
// Smoothing to remove high frequency noise
// classes from Mozzi
// http://sensorium.github.io/Mozzi/doc/html/class_over_sample.html#details
#include <MozziGuts.h>
#include <OverSample.h>   
#include <Smooth.h> // smooth out AC interference


class SKgsr {
public:
  // Public signal features
  // NOTE: make these volatile if they are being used within interrupts
  uint16_t raw, oversampled, smoothed; 
  // Raw (0-1023) & Oversampled (0-4095) & smoothed (oversampled) values
  uint16_t last_peak_val; // the height of the last response peak
  uint16_t ipl; // last inter-peak-latency (time in millis between peaks)
  uint16_t last_amp; // response amplitude of the most recent response (0-4095)
  uint8_t response_count_short; // number of responses, 1 removed every 5 seconds
  uint8_t response_count_long; // number of responses, 1 removed every 10 seconds
  bool response; // true if a response is happening now (ramping up from the resting state)
  uint16_t resting; // resting EDA signal value when no response is occuring
  
  
  // Public methods
  SKgsr(uint8_t inPin, float smoothness);
  ~SKgsr();
  uint16_t readSample();

private:
  uint8_t _adcPin;
  uint32_t last_peak_time;
  uint8_t response_timer_count;
  uint32_t response_timer_lasttime_ms;
  uint16_t peak, trough, thresh; // used for detecting responses, apex values and lows
  uint16_t ipls[10]; // holds the last 10 inter-peak latencies in ms
  bool first_peak, second_peak; // used to do special calculations on the first two responses
  
  OverSample <uint16_t, 2> oversampler; // gives 10+2=12 bit resolution 0->4095, using 32 bytes of memory
  Smooth<uint16_t> *smoother; // get rid of AC interference


  // Internal methods
  void analyzeData();


};

#endif
