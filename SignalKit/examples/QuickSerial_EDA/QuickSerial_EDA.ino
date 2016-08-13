/********************************************************

  Demo for using the QuickSerial Library
  Jonathan Reus-Brodsky

  23, July 2016 - File Created
  
**********************************************************/

#include <QuickSerial.h>

QuickSerial serial;

void setup(){
  serial.init(9600, '\n');
  delay(100);
  serial.println("Hello");
}

void loop(){
  uint16_t num = random(0, 65000);
  serial.write('I', num);
  delay(1000);
}

/*****
 * PYTHON CODE
 * 
 * 

 



 * 
 */








