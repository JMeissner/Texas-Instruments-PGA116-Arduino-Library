#include <Arduino.h>

#include "PGA116.h"

PGA116::PGA116(int cs_pin){
    pinMode(cs_pin, OUTPUT);
	digitalWrite(cs_pin, HIGH);
	_cs_pin = cs_pin;
}

void PGA116::SendCommand(uint16_t command){

    // Select the PGA116
    digitalWrite(_cs_pin, LOW);
	
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
    
    // Send the 16-bit command (high byte first, then low byte)
    SPI.transfer16(command);
	
	// End SPI transaction
    SPI.endTransaction();
    
    // Deselect the PGA116
    digitalWrite(_cs_pin, HIGH);
}

void PGA116::SetChannelAndGain(uint8_t channel, uint8_t gain){
    // Create command: Write command + gain + channel
  uint16_t command = CMD_WRITE | (gain << 4) | channel;
  
  // Send the command
  SendCommand(command);
}