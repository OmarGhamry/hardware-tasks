#include <avr/io.h>
#include <util/delay.h>

void setup() {
  DDRD = 0xFF; 
}

void loop() {
  uint8_t pattern = 0x01; 

  for (int i = 0; i < 8; i++) {
    PORTD = pattern; 
    _delay_ms(250); 
    uint8_t extractedBit = pattern & 0x01;
    pattern = (pattern >> 1) | (extractedBit << 7);
  }
}
