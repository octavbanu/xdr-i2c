#include "uda1380.h"
#include <Arduino.h>

void printBits(byte myByte){
 for(byte mask = 0x80; mask; mask >>= 1){
   if(mask  & myByte)
       Serial.print('1');
   else
       Serial.print('0');
 }
}

bool uda1380_init() {
    Wire.begin(I2C_MASTER, 0x00, I2C_PINS_16_17, I2C_PULLUP_EXT, 30000);
    Wire.setDefaultTimeout(200000); // 10ms
    delay(500);
    
    uint8_t i = 0;
    while (1) 
    {
    
        if (UDA1380InitData[i][0] == 0xff) 
        {
            break;
        } 
        
        // Transmit to Slave
        Wire.beginTransmission(UDA1380_ADDR);   // Slave address
        Wire.write(UDA1380InitData[i], sizeof(UDA1380InitData[i])); // Write string to I2C Tx buffer (incl. string null at end)
        Wire.endTransmission();           // Transmit to Slave

        // Check if error occured
        if(Wire.getError()) {
            return false;
        } else {
            i++;
        }
    }
    
    return true;
}
