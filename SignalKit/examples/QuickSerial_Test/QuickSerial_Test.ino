/********************************************************

  Demo for using the QuickSerial Library
  Sends two data streams, under id 'S' and 'I'
  
  Jonathan Reus-Brodsky

  23, July 2016 - File Created
  
**********************************************************/

#include <QuickSerial.h>
QuickSerial serial;

#define SAMPLE_DELAY 25 // 40 samples per second - don't make this too fast!

void setup(){
  //serial.init(9600);
  serial.init(115200);
  delay(1000);
  serial.println("Hello");
  delay(1000);
}

void loop(){
  static uint16_t num1=0, num2=0;
  num1 += 250;
  num2 -= 250;
  serial.write('S', num1);
  delay(SAMPLE_DELAY); 
  serial.write('I', num2);
  delay(SAMPLE_DELAY);
}

/*****
 * PYTHON CODE
 * 
 * 

 



 * 
 */

/*****
 * SC CODE
 * 
 * 

 



 * 
 */







