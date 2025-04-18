#include <Adafruit_NeoPixel.h>

#ifndef DEBUG_LED_H
#define DEBUG_LED_H

#define LED_PIN 21      // Hardcoded GPIO for WS2812 LED
#define NUM_LEDS 1      // Only one LED for debugging

class DebugLED {
private:
    Adafruit_NeoPixel strip;

public:
    DebugLED() : strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800) {}

    void begin();
    void setColor(uint8_t r, uint8_t g, uint8_t b);

    void setRed() { setColor(100, 0, 0); }
    void setGreen() { setColor(0, 100, 0); }
    void setBlue() { setColor(0, 0, 100); }
    void setOff() { setColor(0, 0, 0); }
};
#endif