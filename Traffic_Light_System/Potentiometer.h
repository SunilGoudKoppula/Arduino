//Reads analog value from a potentiometer and maps it from 0-1023 to 0-255

#include <Arduino.h>

class Potentiometer {
private:
  byte pin;
public:
  Potentiometer() {}  //Default Contructor
  Potentiometer(byte pin);

  void init();

  int getValue();
};