/****
A very quick & simple, lightweight serial transmission library 
with matching libraries in Python & SuperCollider.
****/

#include "QuickSerial.h"
//#include <unordered_map.h>

// Constructor
QuickSerial::QuickSerial() {
 // Do stuff 
}

// Destructor
QuickSerial::~QuickSerial() {
 // Do stuff 
}

void QuickSerial::init(long baud) {
  Serial.begin(baud);
}

/****  
  Sends Data out
    id - data identifier byte (could be an ascii character)
      should uniquely identify the data to follow
  
    data - a 16-bit integer to be sent over serial
*/
void QuickSerial::write(char data_id, uint16_t data) {
    // Write start packet bytes 4x255
    Serial.write(0xFF); Serial.write(0xFF); 
    Serial.write(0xFF); Serial.write(0xFF);

    Serial.write(data_id);
    Serial.write(data >> 8); // send upper byte
    Serial.write(data & 0x00FF); // send lower byte
    //Serial.print(data >> 8);
    //Serial.print(" ");
    //Serial.print(data & 0x00FF);
}
