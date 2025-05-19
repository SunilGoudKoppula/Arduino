// Class to represent an LED with basic ON/OFF/TOGGLE functionality

#include <Arduino.h>

class Led {
private:
  byte pin;
  byte state;
public:
  Led() {}  //Default Constructor
  Led(byte pin);
  //init the pin for the LED
  //call this in setup()
  void init();

  void init(byte defaultState);

  //Turn ON the LED
  void on();

  //Turn OFF the LED
  void off();

  //Toggle the LED
  void toggle();

  bool isPoweredOn();
};