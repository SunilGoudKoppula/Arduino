#include "TrafficLight.h"

void TrafficLight::red() {
  redLed.on();
  yellowLed.off();
  greenLed.off();
}

void TrafficLight::yellow() {
  redLed.off();
  yellowLed.on();
  greenLed.off();
  pedestrianLed.off();
}

void TrafficLight::green() {
  redLed.off();
  yellowLed.off();
  greenLed.on();
  pedestrianLed.off();
}

void TrafficLight::allLedsOff() {
  redLed.off();
  yellowLed.off();
  greenLed.off();
  pedestrianLed.off();
}

void TrafficLight::init(bool isSevenSegmentCommonAnode) {
  redLed.init();
  yellowLed.init();
  greenLed.init();
  pedestrianLed.init();
  pedestrianButton.init();
  potentiometer.init();

  sevenSegment.init(isSevenSegmentCommonAnode);
  sevenSegment.off();

  redTimer.init(false, false);
  yellowTimer.init(false, false);
  greenTimer.init(false, false);

  delay(50);

  red();
}

// Manages the logic and LED state for each respective traffic signal
int TrafficLight::red(int setTime) {
  if (!isRedTimerStarted && !isYellowTimerStarted && !isGreenTimerStarted) {
    redTimer.setTimer(setTime + 1);
    isRedTimerStarted = true;
    red();
  } else if (isRedTimerStarted) {
    redTimer.update(1000);

    if (pedestrianButton.isPressed()) {
      pedestrianStateInRed = true;
    }

    if (redTimer.getRemainingTime() == 0) {
      allLedsOff();
      isRedTimerStarted = false;
      pedestrianState = false;
    }
    if (pedestrianStateInRed) {
      pedestrianState = true;
      return 0;
    } else if (pedestrianState) {
      return redTimer.getRemainingTime();
    }
  }
  return 0;
}

// Manages the logic and LED state for each respective traffic signal
void TrafficLight::yellow(int setTime) {
  if (!isRedTimerStarted && !isYellowTimerStarted && !isGreenTimerStarted) {
    yellowTimer.setTimer(setTime + 1);
    isYellowTimerStarted = true;
    yellow();
  } else if (isYellowTimerStarted) {
    yellowTimer.update(1000);
    if (pedestrianButton.isPressed() || pedestrianStateInRed) {
      pedestrianState = true;
      pedestrianStateInRed = false;
    }
    if (yellowTimer.getRemainingTime() == 0) {
      allLedsOff();
      isYellowTimerStarted = false;
    }
  }
}

// Manages the logic and LED state for each respective traffic signal
void TrafficLight::green(int setTime) {
  if (!isRedTimerStarted && !isYellowTimerStarted && !isGreenTimerStarted) {
    greenTimer.setTimer(setTime + 1);
    isGreenTimerStarted = true;
    green();
  } else if (isGreenTimerStarted) {
    greenTimer.update(1000);
    if (pedestrianButton.isPressed() || pedestrianStateInRed) {
      pedestrianState = true;
      pedestrianStateInRed = false;
    }
    if (greenTimer.getRemainingTime() == 0) {
      allLedsOff();
      isGreenTimerStarted = false;
    }
  }
}

//Central update loop for the traffic light system
//Handles pedestrian button press, LED transitions, and 7-segment display update
void TrafficLight::update(int redTime, int greenTime, int yellowTime) {
  int temp = red(redTime + 2);
  if (temp > 1) {
    sevenSegment.display(temp - 2);
    pedestrianLedBlinker.update();
  } else {
    sevenSegment.off();
    pedestrianLed.off();
  }
  green(greenTime);
  yellow(yellowTime);
}
