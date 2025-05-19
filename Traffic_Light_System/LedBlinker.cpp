#include "LedBlinker.h"

void LedBlinker::toggleLed() {
  led.toggle();
}

LedBlinker::LedBlinker(Led &led) {
  this->led = led;
  lastTimeBlinked = millis();
  blinkDelay = 500;
}

LedBlinker::LedBlinker(Led &led, unsigned long blinkDelay) {
  this->led = led;
  lastTimeBlinked = millis();
  this->blinkDelay = blinkDelay;
}

void LedBlinker::initLed() {
  led.init();
}

// Toggles the LED if the defined delay has passed (non-blocking blink)
void LedBlinker::update() {
  unsigned long timeNow = millis();
  if (timeNow - lastTimeBlinked > blinkDelay) {
    lastTimeBlinked = timeNow;
    toggleLed();
  }
}

unsigned long LedBlinker::getBlinkDelay() {
  return blinkDelay;
}

void LedBlinker::setBlinkDelay(unsigned long blinkDelay) {
  this->blinkDelay = blinkDelay;
}