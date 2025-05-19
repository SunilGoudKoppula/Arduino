#include "Potentiometer.h"

Potentiometer::Potentiometer(byte pin) {
  this->pin = pin;
}

void Potentiometer::init() {
  pinMode(pin, INPUT);
}

int Potentiometer::getValue() {
  return (analogRead(pin)) / 4;
}