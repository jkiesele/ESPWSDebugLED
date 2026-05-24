
#ifndef DEBUG_LED_H
#define DEBUG_LED_H
#include <Arduino.h>

// Detect board: adjust if you have a different macro
#if CONFIG_IDF_TARGET_ESP32S2
  #define HAS_DEBUG_LED 0
#else
  #define HAS_DEBUG_LED 1
#endif

#if HAS_DEBUG_LED
#include <Adafruit_NeoPixel.h>

#define LED_PIN 21      // Hardcoded GPIO for WS2812 LED
#define NUM_LEDS 1      // Only one LED for debugging

class DebugLED {
private:
    Adafruit_NeoPixel strip;

public:
    DebugLED(uint8_t pin=LED_PIN) : strip(NUM_LEDS, pin, NEO_GRB + NEO_KHZ800) {}

    void begin();
    void setColor(uint8_t r, uint8_t g, uint8_t b);

    void setRed() { setColor(100, 0, 0); }
    void setGreen() { setColor(0, 100, 0); }
    void setBlue() { setColor(0, 0, 100); }
    void setPurple() { setColor(100, 0, 100); }
    void setYellow() { setColor(100, 100, 0); }
    void setWhite() { setColor(100, 100, 100); }
    void setOrange() { setColor(100, 50, 0); }
    void setCyan() { setColor(0, 100, 100); }
    void setOff() { setColor(0, 0, 0); }

    bool isOn() const { return strip.Color(0, 0, 0) != 0; }
};


#else  // === Dummy implementation ===

class DebugLED {
public:
    void begin() {}
    void setColor(uint8_t, uint8_t, uint8_t) {}
    void setRed() {}
    void setGreen() {}
    void setBlue() {}
    void setPurple() {}
    void setYellow() {}
    void setWhite() {}
    void setOrange() {}
    void setCyan() {}
    void setOff() {}
    bool isOn() const { return false; }
};

#endif // HAS_DEBUG_LED


#endif // DEBUG_LED_H