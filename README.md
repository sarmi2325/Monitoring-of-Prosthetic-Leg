# 🦿 Real-Time Prosthetic Leg Monitoring System

## 📌 Project Overview

In the field of prosthetics, continuous monitoring of a patient's adaptation to a prosthetic limb is essential during rehabilitation. Currently, prosthetists visit rehabilitation centers daily to assess the patient's progress, which is time-consuming and lacks real-time insights.

This project aims to **build an IoT-based prosthetic leg monitoring system** that:
- Tracks patient performance in real time during exercises (walking, running, climbing stairs, etc.)
- Measures **leg movement angles** and **force pressure**
- Sends live data to **ThingSpeak cloud**
- Helps prosthetists remotely monitor and analyze patient progress through graphs and data trends

---

## 🧠 Key Features

- 📐 **Angle Monitoring** using MPU6050 (gyroscope/accelerometer)
- 💪 **Force Detection** using analog force sensor
- 📡 **Real-time Data Upload** to ThingSpeak IoT cloud
- 📊 **Graphical Data Analysis** for prosthetists
- 🌐 **Wi-Fi-enabled** using ESP32

---

## 🛠️ Hardware Required

| Component            | Quantity |
|----------------------|----------|
| ESP32 Development Board | 1        |
| MPU6050 (Gyro + Accelerometer) | 1        |
| Force Sensor (FSR)   | 1        |
| Wires         | As needed |
| Switch           | 1        |
| Power Supply (e.g. USB Cable) | 1        |

---

## 🧪 Sensor Measurements

- **MPU6050**: Provides angle of rotation (angle used for leg motion tracking)
- **Force Sensor**: Measures foot pressure during step/stance phases

---



