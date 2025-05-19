// General-purpose timer that can count up or down; can run continuously or once

#include <Arduino.h>

class Timer {
private:
  bool isUpCounter;
  bool isContinous;

  int time;
  int count;
  unsigned long timeNow;
  unsigned long lastTimeChanged = 0;

  void up();

  void down();

public:
  Timer() {}  //Default contructor

  void init(bool isUpCounter, bool isContinous);

  void setTimer(int time);

  void update(int milliSecs);

  int getRemainingTime();
};