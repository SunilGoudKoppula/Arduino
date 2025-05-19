// Blinks a refrenced LED at a given delay (non-blocking delay)

#include "Led.h"

class LedBlinker {
private:
  Led led;  //Reference Object
  unsigned long lastTimeBlinked;
  unsigned long blinkDelay;

  void toggleLed();
public:
  LedBlinker() {}  //Default Constructor and don't use if it is not Initiliazed properly

  LedBlinker(Led &led);

  LedBlinker(Led &led, unsigned long blinkDelay);

  void initLed();

  // Toggles the LED if the defined delay has passed (non-blocking blink)
  void update();

  unsigned long getBlinkDelay();

  void setBlinkDelay(unsigned long blinkDelay);
};