/****
Sample incoming ECG data & do analysis / feature extraction.

****/

#include "SKecg.h"

// Constructor
SKecg::SKecg(byte inPin) {
 // Do stuff 
 pinMode(inPin, INPUT);
 _adcPin = inPin;
 ibi = 600; // initialize ibi to something sensible
 pulse = false;
 lastBeatTime = 0;
 peak = 2048; trough = 2048; thresh = 2060;
 firstBeat=true; secondBeat=false;
}

// Destructor
SKecg::~SKecg() {
 // Do stuff 
}

// Get a new sample from the ADC 
// Called approx every 7.008/7.015 milliseconds
uint16_t SKecg::readSample() {
    // Sample the ADC    
    raw = mozziAnalogRead(_adcPin); // value is 0-1023
    oversampled = oversampler.next(raw);
    analyzeData();
}

// Internal private method..
void SKecg::analyzeData() {
    uint16_t current_time, running_total = 0, time_elapsed;
    uint16_t ibi_thresh = (ibi / 5) * 3;

  // Get current time & time elapsed since last detected ecg beat
    current_time = mozziMicros() / 1000; // get the latest time in ms
    time_elapsed = current_time - lastBeatTime;  // monitor the time in us since the last beat
    
    // Track the peak
    if(oversampled > thresh && oversampled > peak) { // thresh is used for debouncing
       peak = oversampled; 
    }
    
    // Track the trough - TODO: Add a bit of code here to ignore the dichrotic noise..
    if(oversampled < thresh && time_elapsed > ibi_thresh) {
      if(oversampled < trough) {
        trough = oversampled;
      }
    }
    
    // Look for a heart beat, during every cardiac pulse wave the signal surges upwards
    // from the average
    // Only check if it's been at least 250 ms since the last beat to avoid noise
    if(time_elapsed > 250) {
       if((oversampled > thresh) && (pulse == false) && (time_elapsed > ibi_thresh)) {
         pulse = true;
         ibi = current_time - lastBeatTime;
         lastBeatTime = current_time;
         
         if(secondBeat) {
              secondBeat = false;
              // at the second beat we have a single IBI value that can be used to
              // get a realistic BPM & HRV
              for(int i=0; i<10; i++) {
                rate[i] = ibi;
              }
         }
         
         if(firstBeat) {
           firstBeat = false;
           secondBeat = true;
           return; // ibi value is worthless, at this point we just track the beat 
         }
         
         // Keep a running total of the last 10 IBI values
         uint16_t sum_ibi = 0;
         for(int i=0; i<9;i++) {
           rate[i] = rate[i+1];
           sum_ibi += rate[i]; 
         }
         rate[9] = ibi;
         sum_ibi = sum_ibi / 10;                // get the avg ibi
         bpm = 60000 / sum_ibi;             // how many ibi's in 60000 ms? This gives us the average IBI and thus the avg BPM
       }
    } // end, beat check
    
    // When the signal starts going down below the threshhold, the beat is over
    if(oversampled < thresh && pulse == true) {
      pulse = false;                  // reset the pulse flag, the pule is over
      amp = peak - trough;            // calculate the amplitude of the last pulse
      thresh = (amp / 2) + trough;    // calculate a new threshhold value for detecting the next pulse
      peak = thresh;                  // reset the peak and trough values for detecting the amplitude of the next pulse
      trough = thresh;
    }
    
    // If 2.5s go by without a beat, reset the system...
    if(time_elapsed > 2500) {
      thresh = 2048;
      peak = 2048;
      trough = 2048;
      lastBeatTime = current_time;
      firstBeat = true;
      secondBeat = false;
    };
}
