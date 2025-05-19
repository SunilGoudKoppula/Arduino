// Controls 1 or 2 7-segment displays, including multiplexed displays

#include <Arduino.h>

class SevenSegmentDisplay {
private:
  byte sevenSegment1[7];
  byte sevenSegment2[7];
  byte commonPin1;
  byte commonPin2;

  int num = 0;

  bool isMultiplexing;
  bool isTwoSevenSegments;
  bool isCommonAnode;

  unsigned long timeNow;
  unsigned long lastTimeChanged = 0;
  bool state = true;

  byte digitSegment[10][7] = {
    { 1, 1, 1, 1, 1, 1, 0 },  // 0
    { 0, 1, 1, 0, 0, 0, 0 },  // 1
    { 1, 1, 0, 1, 1, 0, 1 },  // 2
    { 1, 1, 1, 1, 0, 0, 1 },  // 3
    { 0, 1, 1, 0, 0, 1, 1 },  // 4
    { 1, 0, 1, 1, 0, 1, 1 },  // 5
    { 1, 0, 1, 1, 1, 1, 1 },  // 6
    { 1, 1, 1, 0, 0, 0, 0 },  // 7
    { 1, 1, 1, 1, 1, 1, 1 },  // 8
    { 1, 1, 1, 1, 0, 1, 1 }   // 9
  };

  void setDigit(int digit, byte sevenSegment[7]);

public:
  SevenSegmentDisplay() {}  //Default constructor;

  SevenSegmentDisplay(byte sevenSegment1[7]);

  SevenSegmentDisplay(byte sevenSegment1[7], byte sevenSegment2[7]);

  SevenSegmentDisplay(byte sevenSegment1[7], byte commonPin1, byte commonPin2);


  void init(bool isCommonAnode);

  // Displays a 2-digit number on one or two 7-segment displays
  // If using multiplexing, it alternates between digits rapidly
  void display(int num);

  void reset();

  void off();
  void increment();
  void decrement();
};