#include "Led.h"

Led::Led(byte pin) {
  this->pin = pin;
  state = LOW;
}

//init the pin for the LED
//call this in setup()
void Led::init() {
  pinMode(pin, OUTPUT);
}

void Led::init(byte defaultState) {
  init();
  if (defaultState == HIGH) {
    on();
  } else {
    off();
  }
}

//Turn ON the LED
void Led::on() {
  state = HIGH;
  digitalWrite(pin, state);
}

//Turn OFF the LED
void Led::off() {
  state = LOW;
  digitalWrite(pin, state);
}

//Toggle the LED
void Led::toggle() {
  if (isPoweredOn()) {
    off();
  } else {
    on();
  }
}

bool Led::isPoweredOn() {
  return (state == HIGH);
}