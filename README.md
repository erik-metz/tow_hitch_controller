# Tow Hitch Controller

This project is an **ESP32-based control system** for a retractable tow hitch (Anhängerkupplung) on a BMW X3 F25. The system allows you to extend and retract the tow hitch using a button, with additional safety features such as a **hall sensor** for position detection and a **long-press emergency override**.

## Features
- **Extend/Retract Tow Hitch** with a single button press.
- **Direction Reversal**: Automatically toggles the motor direction.
- **Hall Sensor Integration**: Detects when the hitch reaches its end position.
- **Emergency Override**: Holding the button for **5 seconds** forces retraction.
- **Status LED**: Lights up when the motor is running.
- **ESP32 Compatible**: Can be extended with Wi-Fi/Bluetooth features.

## Hardware Requirements
- **ESP32** (e.g., D1 Mini ESP32 CP2104)
- **Motor Driver** (e.g., L298N or BTS7960)
- **Momentary Push Button** (for manual control)
- **Hall Sensor** (already integrated in the tow hitch motor)
- **12V Power Source** (Car battery connection)
- **Step-down Converter (12V to 5V)** (to power ESP32) (e.g., LM2596)

## Wiring Diagram
| Component        | ESP32 Pin  |
|-----------------|------------|
| Motor Driver IN1 | GPIO 25    |
| Motor Driver IN2 | GPIO 26    |
| Hall Sensor     | GPIO 34    |
| Button Input    | GPIO 14    |
| Status LED      | GPIO 2     |

## Installation
1. **Flash the ESP32** with `tow_hitch_controller.ino` using the Arduino IDE or PlatformIO.
2. **Connect the components** as per the wiring diagram.
3. **Mount the ESP32** safely in your vehicle.
4. **Test the system** by pressing the button to extend/retract the hitch.

## Usage
- **Short press (<5s)** → Extend or retract tow hitch
- **Long press (>5s)** → Force retraction (useful if stuck)
- **Status LED** → Indicates motor activity

## Future Improvements
- **Wireless Control** (e.g., Bluetooth or RF remote key fob)
- **Motor Current Sensing** (to detect blockages)
- **Mobile App Integration** (for remote operation)

## Safety Notice
- Ensure proper wiring to avoid short circuits.
- Use fuses to protect against overcurrent.
- Do not operate while driving.
