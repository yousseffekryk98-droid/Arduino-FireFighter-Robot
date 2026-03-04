# Arduino Fire-Fighting Robot (L298N Edition)

An autonomous fire-suppression robot built using the Arduino microcontroller and the L298N Dual H-Bridge motor driver. This project features a multi-channel infrared (IR) flame sensor array to detect heat sources and an integrated water pump system for localized fire extinguishing.

## 🚀 Key Features

- **Autonomous Fire Detection**: Uses a 5-channel (or 3-channel) IR sensor array to scan and locate fire.
- **Precision Targeting**: Logic-based steering to align the water nozzle directly with the detected flame.
- **Integrated Suppression**: Onboard DC water pump triggered automatically upon flame confirmation.
- **High-Torque Drive**: Managed by the L298N motor driver for steady movement across flat surfaces.

## 🛠️ Hardware Components

- **Microcontroller**: Arduino Uno / Nano
- **Motor Driver**: L298N Dual H-Bridge
- **Sensors**: 4-Channel IR Flame Sensor Module
- **Actuators**: 2x/4x DC Gear Motors + 5V-6V Water Pump
- **Power**: 2x 18650 Li-ion batteries (recommended for 7.4V - 8.4V)
- **Switching**: Relay Module or Transistor (for the water pump)

## 🔌 Circuit Logic

### Scanning
The IR sensors constantly poll for a LOW signal (fire detected).

### Navigation
- If the Left sensor is triggered, the robot turns left.
- If the Right sensor is triggered, the robot turns right.
- If the Center sensor is triggered, the robot moves forward until it reaches the proximity threshold.

### Extinguishing
Once the fire is centered and within range, the motors stop, and the water pump digital pin is set to HIGH.

## 📁 Project Files

- **FireFighter_Robot_3Sensor.ino**: Main sketch for 3-sensor configuration with PWM speed control
- **FireFighter_Robot_L298N.ino**: Sketch optimized for L298N motor driver with 2-sensor analog configuration
- **README.md**: This documentation file

## ⚙️ Pin Configuration

### 3-Sensor Version (FireFighter_Robot_3Sensor.ino)
- **Motor Control**: ENA (11), IN1 (10), IN2 (9), IN3 (7), IN4 (6), ENB (5)
- **Flame Sensors**: Left (13), Center (12), Right (8)
- **Pump**: Pin 4

### L298N Version (FireFighter_Robot_L298N.ino)
- **Motor Control**: IN1 (2), IN2 (3), IN3 (4), IN4 (5)
- **Flame Sensors**: Left (A0), Right (A1)
- **Pump**: Pin 13

## 🔧 How It Works

1. The Arduino reads input from the flame sensors
2. Based on which sensor detects fire (LOW signal):
   - **Center detection**: Stop and activate pump
   - **Left detection**: Turn left
   - **Right detection**: Turn right
   - **No detection**: Stop all motors
3. The water pump is controlled via a digital pin, activating when fire is directly centered

## 💡 Tips for Setup

- Calibrate your flame sensors before deployment
- Adjust the `analogWrite()` values (200 in the 3-sensor version) to control motor speed
- Modify the pump `delay(500)` in the L298N version to adjust spray duration
- Use a relay module if your pump draws more than 20mA
- Test all movements (forward, left, right, stop) before activating the pump

## 🔋 Power Considerations

- Use separate power supplies for the Arduino and motors if possible
- Install a capacitor (100µF) across the motor driver power pins to reduce noise
- Ensure good battery connections with appropriate gauge wiring

---

**Developed for autonomous fire fighting applications.**
