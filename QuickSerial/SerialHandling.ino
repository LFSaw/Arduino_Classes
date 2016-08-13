


/****  
  Sends Data to Serial Reading App
    symbol - data identifier symbol
      G - GSR raw
      E - ECG raw
      V - HRV
      B - BPM
      C - status code
  
    data - an integer to be sent over serial as a string
*/
void sendDataToSerial(char symbol, uint16_t data ) {
    Serial.print(symbol);
    Serial.println(data);                
}

