#include "SevenSegmentDisplay.h"

void SevenSegmentDisplay::setDigit(int digit, byte sevenSegment[7]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(sevenSegment[i], isCommonAnode ? !digitSegment[digit][i] : digitSegment[digit][i]);
  }
}

SevenSegmentDisplay::SevenSegmentDisplay(byte sevenSegment1[7]) {
  memcpy(this->sevenSegment1, sevenSegment1, 7);
  isTwoSevenSegments = false;
  isMultiplexing = false;
}

SevenSegmentDisplay::SevenSegmentDisplay(byte sevenSegment1[7], byte sevenSegment2[7]) {
  memcpy(this->sevenSegment1, sevenSegment1, 7);
  memcpy(this->sevenSegment2, sevenSegment2, 7);
  isTwoSevenSegments = true;
  isMultiplexing = false;
}

SevenSegmentDisplay::SevenSegmentDisplay(byte sevenSegment1[7], byte commonPin1, byte commonPin2) {
  memcpy(this->sevenSegment1, sevenSegment1, 7);
  this->commonPin1 = commonPin1;
  this->commonPin2 = commonPin2;
  isMultiplexing = true;
  isTwoSevenSegments = false;
}


void SevenSegmentDisplay::init(bool isCommonAnode) {
  this->isCommonAnode = isCommonAnode;

  //Init pins for first display
  for (int i = 0; i < 7; i++) {
    pinMode(sevenSegment1[i], OUTPUT);
  }

  //Init pins for second display if needed
  if (isTwoSevenSegments) {
    for (int i = 0; i < 7; i++) {
      pinMode(sevenSegment2[i], OUTPUT);
    }
  }

  // Init common pins for multiplexing if applicable
  if (isMultiplexing) {
    pinMode(commonPin1, OUTPUT);
    pinMode(commonPin2, OUTPUT);
    digitalWrite(commonPin2, isCommonAnode ? LOW : HIGH);  //tens place
    digitalWrite(commonPin1, isCommonAnode ? HIGH : LOW);  //units place
  }

  off();
}

// Displays a 2-digit number on one or two 7-segment displays
// If using multiplexing, it alternates between digits rapidly
void SevenSegmentDisplay::display(int num) {
  this->num = num;
  if (num < 0 || num > 99) return;

  int tens = num / 10;
  int units = num % 10;


  if (!isTwoSevenSegments && !isMultiplexing) {
    setDigit(units, sevenSegment1);
  } else if (isTwoSevenSegments && !isMultiplexing) {
    setDigit(tens, sevenSegment2);
    setDigit(units, sevenSegment1);
  } else {
    timeNow = millis();
    if (timeNow - lastTimeChanged > 50 && state) {
      digitalWrite(commonPin2, isCommonAnode ? LOW : HIGH);
      digitalWrite(commonPin1, isCommonAnode ? HIGH : LOW);
      setDigit(units, sevenSegment1);
      lastTimeChanged = timeNow;
      state = !state;
    } else if (timeNow - lastTimeChanged > 50 && !state) {
      digitalWrite(commonPin1, isCommonAnode ? LOW : HIGH);
      digitalWrite(commonPin2, isCommonAnode ? HIGH : LOW);
      setDigit(tens, sevenSegment1);
      lastTimeChanged = timeNow;
      state = !state;
    }
  }
}

void SevenSegmentDisplay::reset() {
  num = 0;
  display(num);
}

void SevenSegmentDisplay::off() {
  if (!isTwoSevenSegments) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(sevenSegment1[i], isCommonAnode ? HIGH : LOW);
    }
  } else {
    for (int i = 0; i < 7; i++) {
      digitalWrite(sevenSegment1[i], isCommonAnode ? HIGH : LOW);
      digitalWrite(sevenSegment2[i], isCommonAnode ? HIGH : LOW);
    }
  }
}

void SevenSegmentDisplay::increment() {
  num++;
  display(num);
}

void SevenSegmentDisplay::decrement() {
  num--;
  display(num);
}