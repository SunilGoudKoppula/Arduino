// Class to handle a push button with debounce and lon-press detection

#include <Arduino.h>

class PushButton {
private:
  byte pin;
  byte state;
  bool isPullUp;
  bool internalPullUpActivated;
  unsigned long lastTimeStateChanged;
  unsigned long debounceDelay;
  unsigned long pressStartTime;
  bool wasPreviouslyPressed;

  // Reads the debounced state of the button and updates press timing
  void readState();

public:
  PushButton() {}  // Default Constructor and Don't use if it is not initialized properly
  PushButton(byte pin, bool isPullUp, bool internalPullUpActivated);

  void init();

  bool isPressed();

  bool isLongPressed(unsigned long longPressDuration);
};