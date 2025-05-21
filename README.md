# Accident Detection System

## 📌 About the Project

The **Accident Detection System** is an IoT-based safety solution built using Arduino, vibration sensors, and GPS modules, integrated with the Blynk IoT platform. This system is designed to detect potential vehicle collisions or accidents and immediately notify emergency contacts with the vehicle's GPS location. To minimize false alerts, a buzzer button is included that allows the driver to cancel the alert within a 10-second window after an impact is detected. This project is ideal for real-time emergency response and road safety enhancement.

---

## ⚙️ Features

- 🚨 **Accident Detection**: Identifies sudden impacts using a vibration sensor.
- 📍 **GPS Location Sharing**: Sends real-time location data to emergency contacts via the Blynk app.
- 🔕 **False Alarm Control**: Includes a buzzer button to cancel alerts if the driver is safe.
- 📲 **IoT Integration**: Uses the Blynk platform for mobile notifications and monitoring.
- 🔧 **Arduino-Based**: Simple and cost-effective hardware implementation.

---

## 🚀 How to Run the Project

To set up and run the project on your hardware, follow these steps:

1. **Clone the Repository**:
   - Open your terminal and run:
     ```
     git clone https://github.com/harshith046/Accident-Detection-System.git
     cd Accident-Detection-System
     ```

2. **Set Up the Hardware**:
   - Components required:
     - Arduino Uno (or compatible)
     - Vibration sensor
     - GPS module
     - ESP8266 Wi-Fi module (if using Blynk over Wi-Fi)
     - Buzzer
     - Push button
     - Jumper wires, breadboard

   - Connect the components as per your circuit plan:
     - Vibration sensor to digital input
     - GPS module via TX/RX serial pins
     - Buzzer and push button to separate digital pins
     - Common ground for all components

3. **Install Required Software and Libraries**:
   - Download and install the Arduino IDE
   - Open the project file `ConfigCode.cpp` in the IDE
   - Install libraries required i.e., Blynk, TinyGPS++, SoftwareSerial

4. **Configure Wi-Fi and Blynk Token**:
   - In `ConfigCode.cpp`, update the following values:
     ```
     char auth[] = "YourBlynkAuthToken";
     char ssid[] = "YourWiFiSSID";
     char pass[] = "YourWiFiPassword";
     ```

5. **Set Up the Blynk App**:
   - Install the **Blynk** app, create a new project by selecting your hardware board and add the necessary widgets.
   - Use the authentication token provided in the app within your code

6. **Test the System**:
   - Trigger the vibration sensor manually to simulate an impact
   - If the buzzer button is not pressed within 10 seconds, the system will send a notification with GPS location to the Blynk app

---

## 🧠 Technologies Used

- **Microcontroller**: Arduino Uno
- **Sensors**: Vibration Sensor, GPS Module
- **Communication**: ESP8266 Wi-Fi Module
- **Platform**: Blynk IoT App
- **Libraries**: TinyGPS++, Blynk, SoftwareSerial (for serial communication)

---

## 🤝 Contributions

Feel free to contribute by opening issues, submitting pull requests, or suggesting new features. All contributions that enhance functionality, usability, or accuracy are welcome!
