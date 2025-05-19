#include "PushButton.h"

// Reads the debounced state of the button and updates press timing
void PushButton::readState() {
  unsigned long timeNow = millis();
  byte newState = digitalRead(pin);

  if (newState != state && (timeNow - lastTimeStateChanged) > debounceDelay) {
    state = newState;
    lastTimeStateChanged = timeNow;
  }

  bool currentlyPressed = isPullUp ? (state == LOW) : (state == HIGH);

  if (currentlyPressed && !wasPreviouslyPressed) {
    pressStartTime = timeNow;  // Start of press
  }

  wasPreviouslyPressed = currentlyPressed;
}

PushButton::PushButton(byte pin, bool isPullUp, bool internalPullUpActivated) {
  this->pin = pin;
  this->isPullUp = isPullUp;
  this->internalPullUpActivated = internalPullUpActivated;

  lastTimeStateChanged = millis();
  debounceDelay = 50;
  pressStartTime = 0;
  wasPreviouslyPressed = false;
}

void PushButton::init() {
  if (isPullUp && internalPullUpActivated) {
    pinMode(pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT);
  }
  state = digitalRead(pin);
}

bool PushButton::isPressed() {
  readState();
  return isPullUp ? (state == LOW) : (state == HIGH);
}

bool PushButton::isLongPressed(unsigned long longPressDuration) {
  readState();
  bool currentlyPressed = isPullUp ? (state == LOW) : (state == HIGH);
  if (currentlyPressed) {
    unsigned long timeNow = millis();
    return (timeNow - pressStartTime >= longPressDuration);
  }
  return false;
}