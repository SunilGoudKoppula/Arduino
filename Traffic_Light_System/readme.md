
# 🚦 Traffic Light System using Arduino & OOP

This project demonstrates how to build a modular **Traffic Light System** using **Arduino** and **Object-Oriented Programming (OOP)** principles. It simulates a real-world traffic scenario with red, yellow, green lights, pedestrian interaction, and countdown display using a 7-segment display.

---

## 🔧 Features

- 🚦 Fully functional traffic signal logic (Red, Yellow, Green)
- 🚶‍ Pedestrian button support with blinking LED indication
- ⏱️ Non-blocking timer-based transitions (no `delay()`)
- 🔢 Countdown timer on 7-segment display using multiplexing
- 🎛️ Adjustable timing via potentiometer
- 🧱 Structured and reusable OOP architecture

---

## 📁 File Structure

```bash
Traffic_Light_System/
├── Led.cpp / Led.h                # LED control class
├── LedBlinker.cpp / LedBlinker.h # Handles LED blinking (non-blocking)
├── PushButton.cpp / PushButton.h # Debounced button input with long-press detection
├── Potentiometer.cpp / Potentiometer.h # Reads analog input
├── Timer.cpp / Timer.h           # Custom non-blocking timer (up/down counter)
├── SevenSegmentDisplay.cpp / SevenSegmentDisplay.h # 7-segment display logic with optional multiplexing
├── TrafficLight.cpp / TrafficLight.h   # Main traffic light system logic
└── Traffic_Light_System.ino      # Arduino sketch to run the system
```

---

## 🎮 Simulation

Try the live simulation on Tinkercad:

🔗 **[Tinkercad Project](https://bit.ly/arduino-traffic-light)**

---

## 🧠 Learning Objectives

This project is a great starting point for anyone interested in:
- Embedded Systems Development
- Arduino Programming
- Object-Oriented Design
- Real-time systems and non-blocking logic

---

## 📦 Requirements

- Arduino Uno (or similar)
- 4 LEDs (Red, Yellow, Green, Pedestrian)
- Push Button
- Potentiometer
- 7-Segment Display (1 or 2 units)
- Breadboard & Wires
- Arduino IDE

---

## 🚀 Getting Started

1. Clone this repository:
   ```bash
   git clone https://github.com/SunilGoudKoppula/Arduino.git
   cd Arduino/Traffic_Light_System
   ```

2. Open `Traffic_Light_System.ino` in the **Arduino IDE**.

3. Make necessary **pin adjustments** based on your hardware setup.

4. Upload to your Arduino board and observe the system in action.

---

## 📷 Screenshots
![Circuit](https://github.com/user-attachments/assets/82faafd3-50eb-400f-8d04-7e12818d58b7)

---

## 🙌 Acknowledgments

This project was inspired by a desire to understand how **software principles** like OOP can be applied to **hardware systems** in a structured and scalable way.

---

## 📫 Connect

Feel free to connect with me on [LinkedIn](https://www.linkedin.com/in/sunilgoudkoppula) or explore my other projects!

---

## 🏷️ Tags

`#Arduino` `#EmbeddedSystems` `#OOP` `#TrafficLight` `#STEM` `#Tinkercad` `#LearningByDoing`
