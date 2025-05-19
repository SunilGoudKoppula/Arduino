// Manages state transitions between RED, GREEN, YELLOW for traffic lights
// Handles pedestrian requests and displays countdown via 7-segment display

#include "LedBlinker.h"
#include "PushButton.h"
#include "Potentiometer.h"
#include "Timer.h"
#include "SevenSegmentDisplay.h"

class TrafficLight {
private:
  Led redLed;
  Led yellowLed;
  Led greenLed;
  Led pedestrianLed;

  LedBlinker pedestrianLedBlinker;

  PushButton pedestrianButton;
  Potentiometer potentiometer;
  Timer redTimer, yellowTimer, greenTimer;

  SevenSegmentDisplay &sevenSegment;

  byte ledsBrightness;
  byte time;

  bool isRedTimerStarted = false;
  bool isYellowTimerStarted = false;
  bool isGreenTimerStarted = false;

  bool pedestrianState = false;
  bool pedestrianStateInRed = false;

  void red();

  void yellow();

  void green();

  void allLedsOff();

public:
  TrafficLight() = delete;  //Default Constructor
  TrafficLight(Led &redLed, Led &yellowLed, Led &greenLed, Led &pedestrianLed,
               LedBlinker &pedestrianLedBlinker, PushButton &pedestrianButton,
               Potentiometer &potentiometer, SevenSegmentDisplay &sevenSegment)
    : redLed(redLed),
      yellowLed(yellowLed),
      greenLed(greenLed),
      pedestrianLed(pedestrianLed),
      pedestrianLedBlinker(pedestrianLedBlinker),
      pedestrianButton(pedestrianButton),
      potentiometer(potentiometer),
      sevenSegment(sevenSegment) {}

  void init(bool isSevenSegmentCommonAnode);

  // Manages the logic and LED state for each respective traffic signal
  int red(int setTime);

  // Manages the logic and LED state for each respective traffic signal
  void yellow(int setTime);

  // Manages the logic and LED state for each respective traffic signal
  void green(int setTime);

  //Central update loop for the traffic light system
  //Handles pedestrian button press, LED transitions, and 7-segment display update
  void update(int redTime, int greenTime, int yellowTime);
};
