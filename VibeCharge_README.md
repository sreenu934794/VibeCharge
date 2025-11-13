# VibeCharge – Vibration Energy Harvesting IoT System

VibeCharge is an IoT-based energy harvesting system designed to convert 
environmental vibrations (railway tracks, machines, vehicles, bridges) into usable 
electrical energy through a piezoelectric sensor. The harvested energy is stored in a 
rechargeable battery and powers the ESP8266 microcontroller, which monitors 
vibration and voltage levels using MPU6050 and analog readings.

---

## 🔋 System Features
- Piezoelectric power generation
- AC → DC rectification and voltage boosting
- BMS-based safe charging
- Rechargeable battery storage
- ESP8266 monitoring
- MPU6050 vibration sensing
- Serial dashboard for real-time tracking

---

## 📡 Data Collected
- Vibration intensity (accelerometer)
- Gyroscopic rotation data
- Piezoelectric voltage generated
- Battery charging status

---

## ⚙ Hardware Components
- ESP8266 NodeMCU
- MPU6050 Accelerometer + Gyroscope
- Piezoelectric Vibration Sensor
- Rectifier Circuit (Bridge)
- Boost Converter (5V output)
- BMS (Battery Management System)
- Rechargeable Battery (3.7V/5V)

---

## 📁 Project Structure
```
VibeCharge/
│
├── README.md
├── vibecharge_code_extended.ino
└── vibecharge_diagram.png
```

---

## ▶ Running the System
1. Upload the `.ino` file to ESP8266 using Arduino IDE.
2. Connect MPU6050 and Piezo as per pin layout inside the code.
3. Open Serial Monitor → 115200 baud.
4. Observe vibration values, piezo voltage, and system status.

---

## 🧠 Future Improvements
- Cloud dashboard (IoT analytics)
- Piezo sensor array for higher power
- Automated threshold alerts
