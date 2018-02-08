#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUMPIXELS 8*8*8
#define RELAY 4
#ifdef __AVR__
  #include <avr/power.h>
#endif
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
}
 
void loop() {
  rainbowCycle(1);
}
 
void rainbowCycle(uint8_t wait) {
uint16_t i, j;
for(j=256; j>0; j--) {
  for(i=0; i< NUMPIXELS; i++) {
    strip.setPixelColor(i, Wheel((((i) * 256 / NUMPIXELS) + j) & 255));      
    }  
    strip.show();
    delay(5000);   
    }
}
 
uint32_t Wheel(byte WheelPos) { if(WheelPos < 85) {
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
    WheelPos -= 85; return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else {
      WheelPos -= 170; return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
      }
      }
