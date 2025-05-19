#include "Timer.h"

void Timer::up() {
  if (count == time && isContinous) {
    count = 0;
  } else if (count == time && !isContinous) {
    count == time;
  } else {
    count++;
  }
}

void Timer::down() {
  if (count == 0 && isContinous) {
    count = time;
  } else if (count == 0 && !isContinous) {
    count == 0;
  } else {
    count--;
  }
}

void Timer::init(bool isUpCounter, bool isContinous) {
  this->isUpCounter = isUpCounter;
  this->isContinous = isContinous;
}

void Timer::setTimer(int time) {
  this->time = time;
  if (!isUpCounter) {
    count = time;
  } else {
    count = 0;
  }
}

void Timer::update(int milliSecs) {
  timeNow = millis();
  if (timeNow - lastTimeChanged > milliSecs) {
    lastTimeChanged = timeNow;
    if (isUpCounter) {
      up();
    } else {
      down();
    }
  }
}

int Timer::getRemainingTime() {
  return count;
}