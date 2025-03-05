# SmartKitchenBlynk

This project is a smart kitchen monitoring and control system built using the ESP8266 microcontroller. It integrates temperature sensing, air quality monitoring, human detection, and appliance control through the Blynk IoT platform. The system is designed to enhance kitchen safety and convenience by automating tasks and providing real-time monitoring.

---

## Features

- **Temperature Monitoring**: Measures ambient and object temperatures using the MLX90614 infrared temperature sensor.
- **Air Quality Monitoring**: Detects air quality using the MQ135 gas sensor and triggers alerts if air quality deteriorates.
- **Human Detection**: Uses a PIR sensor to detect human presence and control lighting accordingly.
- **Appliance Control**: Allows remote control of kitchen appliances (e.g., fridge, fan, lights) via the Blynk app.
- **Alarm System**: Activates a buzzer and exhaust fan when air quality exceeds a safe threshold.
- **Blynk Integration**: Provides real-time data visualization and control through the Blynk IoT platform.

---

## Hardware Requirements

- ESP8266 Microcontroller (e.g., NodeMCU)
- MLX90614 Infrared Temperature Sensor
- MQ135 Gas Sensor
- PIR Motion Sensor
- Relay Module (for controlling appliances)
- Buzzer
- Jumper Wires
- Breadboard (optional)

---

## Software Requirements

- Arduino IDE
- Blynk Library
- Adafruit MLX90614 Library
- MQ135 Library

---

## Setup and Configuration

### Hardware Connections

1. **MLX90614 Sensor**:
   - Connect SDA to D2 (GPIO 4).
   - Connect SCL to D1 (GPIO 5).

2. **MQ135 Sensor**:
   - Connect VCC to 3.3V.
   - Connect GND to GND.
   - Connect A0 to the analog input pin (A0).

3. **PIR Sensor**:
   - Connect VCC to 3.3V.
   - Connect GND to GND.
   - Connect OUT to D3 (GPIO 0).

4. **Relay Module**:
   - Connect IN1 to D5 (GPIO 14) for the fan.
   - Connect IN2 to D0 (GPIO 16) for the light.
   - Connect IN3 to D7 (GPIO 13) for the fridge.

5. **Buzzer**:
   - Connect the positive terminal to D6 (GPIO 12).
   - Connect the negative terminal to GND.

### Software Configuration

1. **Install Libraries**:
   - Install the Blynk, Adafruit MLX90614, and MQ135 libraries via the Arduino Library Manager.

2. **Blynk Setup**:
   - Create a new project in the Blynk app.
   - Use the provided `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `BLYNK_AUTH_TOKEN` in the code.
   - Add widgets in the Blynk app for temperature, air quality, alarm status, and human detection.

3. **Upload Code**:
   - Upload the provided code to the ESP8266 using the Arduino IDE.

---

## Code Overview

### Key Components

1. **Blynk Integration**:
   - The system connects to the Blynk cloud using Wi-Fi credentials and the Blynk authentication token.
   - Virtual pins (V0-V5) are used to send and receive data between the ESP8266 and the Blynk app.

2. **Temperature Monitoring**:
   - The MLX90614 sensor measures ambient and object temperatures.
   - Temperature data is sent to the Blynk app via virtual pin V1.

3. **Air Quality Monitoring**:
   - The MQ135 sensor detects air quality in PPM (parts per million).
   - If air quality exceeds 150 PPM, the buzzer and exhaust fan are activated.

4. **Human Detection**:
   - The PIR sensor detects human presence.
   - If a person is detected, the kitchen light is turned on.

5. **Appliance Control**:
   - Relays are used to control the fridge, fan, and lights.
   - The fridge can be controlled remotely via the Blynk app using virtual pin V0.

6. **Alarm System**:
   - The buzzer and exhaust fan are activated when air quality is poor.

---

## Usage

1. **Power On**:
   - The system initializes and connects to the Blynk app.

2. **Real-Time Monitoring**:
   - Monitor temperature, air quality, and human presence in real-time via the Blynk app.

3. **Appliance Control**:
   - Use the Blynk app to control the fridge, fan, and lights.

4. **Alerts**:
   - The system triggers alerts (buzzer and exhaust fan) if air quality deteriorates.

---

## Example Workflow

1. The system starts and connects to Wi-Fi and Blynk.
2. Temperature and air quality data are sent to the Blynk app.
3. If a person is detected, the kitchen light turns on.
4. If air quality exceeds 150 PPM, the buzzer and exhaust fan activate.
5. The user can control the fridge remotely via the Blynk app.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- Thanks to the Blynk team for the IoT platform.
- Thanks to Adafruit for the MLX90614 library.
- Thanks to the developers of the MQ135 library.

---

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

---

## Contact

For any questions or support, please contact [Your Name] at [your.email@example.com].

---

This README provides a comprehensive overview of the project, including setup instructions, usage, and a description of the code. Feel free to customize it further to suit your needs!