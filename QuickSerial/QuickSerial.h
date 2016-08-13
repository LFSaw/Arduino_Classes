/********
QuickSerial.h - A very quick & simple, lightweight serial transmission library 
with matching libraries in Python & SuperCollider.

Created by Jonathan Reus-Brodsky, July 23, 2016
Released into the public domain.

**/

#ifndef QuickSerial_H
#define QuickSerial_H

#include <Arduino.h>

// NTS:: Base QuickSerial on the non-blocking delay from Mozzi
//   store the last value for each character id and send during a metronome 
//   tick
//#include <Metronome.h> // non-blocking delay from Mozzi
// Maybe using an unordered map of some kind?


class QuickSerial {

public:
  // Public data members
  // NOTE: Make these volatile if they are being used within interrupts

  
  // Public methods
  QuickSerial();
  ~QuickSerial();
  void init(long baud);
  void write(char data_id, uint16_t thedata);

  // Wrappers for standard Arduino serial functions
  void println(char * str) {
    Serial.println(str);
  }

private:
  /*
  uint8_t _adcPin;
  uint32_t lastBeatTime;
  uint16_t peak, trough, thresh; // used for detecting heartbeats, even as 

  // Internal methods
  void analyzeData();
*/

};

#endif
