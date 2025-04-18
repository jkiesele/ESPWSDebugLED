#include <DebugLED.h>

void DebugLED::begin() {
    strip.begin();
    setOff();
    strip.show();  // Initialize all pixels to 'off'
}
void DebugLED::setColor(uint8_t r, uint8_t g, uint8_t b) {
    strip.setPixelColor(0, strip.Color(g, r, b));
    strip.show();
}