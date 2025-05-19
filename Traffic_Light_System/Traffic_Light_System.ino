#include "TrafficLight.h"

#define RED_LED_PIN 11
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 9
#define PEDESTRIAN_LED_PIN A5

#define PEDESTRIAN_BUTTON A4

byte SEVEN_SEGMENT_DISPLAY_PINS[7] = { 8, 7, 6, 5, 4, 3, 2 };
#define SEVEN_SEGMENT_DISPLAY1_COMMON_PIN A0
#define SEVEN_SEGMENT_DISPLAY2_COMMON_PIN A1

#define POTENTIOMETER_PIN A2

bool pedestrianState = false;

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);
Led pedestrianLed(PEDESTRIAN_LED_PIN);

PushButton pedestrianButton(PEDESTRIAN_BUTTON, true, true);

Potentiometer potentiometer(POTENTIOMETER_PIN);

LedBlinker pedestrianLedBlinker(pedestrianLed, 500);

SevenSegmentDisplay sevenSegment(SEVEN_SEGMENT_DISPLAY_PINS,
                                 SEVEN_SEGMENT_DISPLAY1_COMMON_PIN,
                                 SEVEN_SEGMENT_DISPLAY2_COMMON_PIN);

Timer redTimer, yellowTimer, greenTimer;

TrafficLight trafficLight(
  redLed, yellowLed, greenLed, pedestrianLed,
  pedestrianLedBlinker, pedestrianButton, potentiometer, sevenSegment);

// Initializes all components (LEDs, button, potentiometer, timer, display)
void setup() {
  Serial.begin(115200);
  trafficLight.init(true);
  delay(10);
}

// Continuously updates the traffic light system with fixed timings
void loop() {
  trafficLight.update(30, 25, 5);
}