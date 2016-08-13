/****
Sample incoming EDA data & do analysis / feature extraction.

****/

#include "SKgsr.h"

// Constructor
SKgsr::SKgsr(byte inPin, float smoothness) {
 // Do stuff 
 pinMode(inPin, INPUT);
 smoother = new Smooth<uint16_t>(smoothness);
 _adcPin = inPin;
 response = false;
 peak = 2048; trough = 2048; thresh = 2060;
 resting = 1024;
 response_timer_count = 0;
 response_timer_lasttime_ms = mozziMicros() / 1000;
 response_count_short = 0; // number of responses, 1 removed every 5 seconds
 response_count_long = 0; // number of responses, 1 removed every 10 seconds
  
}

// Destructor
SKgsr::~SKgsr() {
 // Do stuff 
}

// Get a new sample from the ADC 
// Called approx every 7.008/7.015 milliseconds in a Mozzi sketch
uint16_t SKgsr::readSample() {
    // Sample the ADC    
    raw = mozziAnalogRead(_adcPin); // value is 0-1023
    oversampled = oversampler.next(raw);
    smoothed = smoother->next(oversampled);
    analyzeData();
    return oversampled;
}

// Internal private method..
void SKgsr::analyzeData() {
    uint16_t current_time, running_total = 0, time_elapsed;
    uint16_t ipl_thresh = (ipl / 5) * 3;

  // Get current time & time elapsed since last detected ecg beat
    current_time = mozziMicros() / 1000; // get the latest time in ms
    time_elapsed = current_time - last_peak_time;  // monitor the time in us since the last peak
    
    if((current_time - response_timer_lasttime_ms) > 5000) { // 5 seconds have passed since last response timer tick
      response_timer_count++;
      // Subtract responses as necessary..
      if(response_count_short > 0) response_count_short -= 1;
      if((response_count_long > 1) && (response_timer_count % 2 == 0)) response_count_long -= 2; 
      response_timer_lasttime_ms = current_time;
    }

    
    // Track the peak as it increases
    if(oversampled > thresh && oversampled > peak) { // thresh is used for debouncing
       peak = oversampled; 
    }
    
    // If the value goes below the threshhold, and is past a certain time period, then we can assume it is beginning a descent
    if(oversampled < thresh && time_elapsed > ipl_thresh) {
      last_peak_val = peak; // at this point the peak has reached its apex, the last_peak value can be set
      if(oversampled < trough) {
        trough = oversampled;
      }
    }
    
    // Look for a response, during every EDA response the signal surges upwards from the average
    // Only check if it's been at least 300 ms since the last response to avoid noise
    if(time_elapsed > 300) {
       if((oversampled > thresh) && (response == false) && (time_elapsed > ipl_thresh)) {
         response = true;
         ipl = current_time - last_peak_time;
         last_peak_time = current_time;
         
         // We have a response!
         response_count_short++;
         response_count_long++;

         
         if(second_peak) {
              second_peak = false;
              // at the second beat we have a single IBI value that can be used to
              // get a realistic BPM & HRV
              for(int i=0; i<10; i++) {
                ipls[i] = ipl;
              }
         }
         
         if(first_peak) {
           first_peak = false;
           second_peak = true;
           return; // ibi value is worthless, at this point we just track the beat 
         }
         
         // Keep a running total of the last 10 inter-peak time values
         uint16_t sum_ipl = 0;
         for(int i=0; i<9;i++) {
           ipls[i] = ipls[i+1];
           sum_ipl += ipls[i]; 
         }
         ipls[9] = ipl;
         sum_ipl = sum_ipl / 10;                // get the avg ibi
         //bpm = 60000 / sum_ipl;             // how many ipl's in 60000 ms? This gives us the average IPL over 10 seconds
       }
    } // end, beat check
    
    // When the signal starts going down below the threshhold, the beat is over
    if(oversampled < thresh && response == true) {
      response = false;                  // reset the pulse flag, the pule is over
      last_amp = peak - trough;            // calculate the amplitude of the last pulse
      thresh = (last_amp / 2) + trough;    // calculate a new threshhold value for detecting the next pulse
      peak = thresh;                  // reset the peak and trough values for detecting the amplitude of the next pulse
      trough = thresh;
    }
    
    // If 2.5s go by without a beat, reset the system...
    if(time_elapsed > 2500) {
      thresh = 2048;
      peak = 2048;
      trough = 2048;
      last_peak_time = current_time;
      first_peak = true;
      second_peak = false;
    };
}
