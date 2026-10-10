
#include <avr/io.h>

#define LED_MASK 0b00011111  // PB0-PB4 = Arduino pins 8-12
#define BUTTON_PIN PD2       // Arduino pin 2

void setup() {
  // Configure pins 8-12 as outputs
  DDRB |= LED_MASK;

  // Configure pin 2 as input
  DDRD &= ~(1 << BUTTON_PIN);

  // Enable internal pull-up resistor on pin 2
  PORTD |= (1 << BUTTON_PIN);

  // All LEDs OFF initially
  PORTB &= ~LED_MASK;
}

void loop() {
  // Button pressed (LOW because of INPUT_PULLUP)
  if (!(PIND & (1 << BUTTON_PIN))) {

    // Debounce delay
    delay(30);

    // Confirm the button is still pressed
    if (!(PIND & (1 << BUTTON_PIN))) {

      // Wait until the button is released
      while (!(PIND & (1 << BUTTON_PIN))) {
        // Wait
      }

      // Debounce the release
      delay(30);

      // Start the pattern: all LEDs OFF at t = 0
      PORTB &= ~LED_MASK;
      delay(1000);

      //start
      for (int i = 0; i < 5; i++) {
        PORTB |= (1 << i);
        delay(1000);
      }
      // end
        for (int i = 0; i < 5; i++) {
        PORTB &= ~(1 << i);
        delay(1000);
      }

    }
  }
}