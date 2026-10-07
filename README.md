# 🏫 Smart Campus IoT — Classroom Environmental & Occupancy Monitoring

> **Project Classification**: Student Prototype / Academic IoT Coursework (3rd-Semester B.Tech CSE)

<div align="center">

  [![Prototype Status](https://img.shields.io/badge/Status-Student_Prototype-06B6D4?style=for-the-badge)](dashboard/)
  [![Hardware](https://img.shields.io/badge/Edge_Node-ESP32_Microcontroller-red?style=for-the-badge&logo=espressif)](https://www.espressif.com/)
  [![Sensors](https://img.shields.io/badge/Sensors-DHT22_%7C_HC--SR04_%7C_LDR-orange?style=for-the-badge)](firmware/)
  [![Frontend](https://img.shields.io/badge/Dashboard-HTML5_%2B_CSS3-10B981?style=for-the-badge)](dashboard/)
  [![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

  <br/>

  **A smart campus IoT prototype designed to monitor classroom environmental conditions (temperature, humidity, ambient lux) and doorway occupancy headcounts, reporting metrics to an OLED display and web dashboard.**

  <br/>

  [System Architecture](#-system-architecture) • [Hardware Pinout](#-hardware-pin-mapping) • [Live Dashboard](#-browser-dashboard) • [Author](#-author)

</div>

---

## 📌 Project Overview

Energy consumption in university lecture halls is frequently inefficient when lighting and air conditioning run in vacant rooms. 

This **Smart Campus IoT prototype** demonstrates how edge sensors on an **ESP32** can monitor:
1. **Classroom Occupancy**: Ultrasonic doorway threshold counter tracking students entering and exiting.
2. **Thermal Comfort**: DHT22 sensor tracking temperature and relative humidity.
3. **Ambient Lighting**: LDR photoresistor checking if natural sunlight is sufficient to dim overhead fixtures.
4. **Local & Remote Telemetry**: Real-time stats rendered on an I2C OLED screen and exposed via a REST JSON API to a browser dashboard.

---

## 🏗️ System Architecture

```text
                 +-----------------------+
                 |  Classroom Sensors    |
                 |  - DHT22 (Temp/Hum)   |
                 |  - HC-SR04 (Doorway)  |
                 |  - LDR (Light Lux)    |
                 +-----------+-----------+
                             |
                             v
                 +-----------------------+
                 | ESP32 Microcontroller |
                 | (Firmware Processing) |
                 +-----+-----------+-----+
                       |           |
             I2C Bus   |           | Wi-Fi HTTP Server
                       v           v
          +----------------+   +-----------------------+
          | SSD1306 OLED   |   | Browser Dashboard     |
          | (Door Display) |   | (GET /api/telemetry)  |
          +----------------+   +-----------------------+
```

---

## 🔌 Hardware Pin Mapping

| Peripheral | Component | ESP32 GPIO Pin | Description |
|---|---|---|---|
| **Temperature & Humidity** | DHT22 | GPIO 4 | Single-wire digital data bus |
| **Doorway Counter Trigger** | HC-SR04 | GPIO 5 | 10µs ultrasonic trigger |
| **Doorway Counter Echo** | HC-SR04 | GPIO 19 | Return pulse width (voltage divider) |
| **Ambient Lux Sensor** | LDR Photoresistor | GPIO 34 (ADC1) | Analog light intensity reading |
| **Local Status Display** | SSD1306 OLED | GPIO 21 (SDA), GPIO 22 (SCL) | I2C status screen at 0x3C |

---

## 💻 Browser Dashboard

The project includes an interactive web dashboard in the [`dashboard/`](./dashboard) folder.
- **Local Testing**: Open `dashboard/index.html` directly in any browser.
- Features a built-in **Simulated Feed Toggle** to test room occupancy transitions and automated HVAC/lighting reactions even when disconnected from the physical microcontroller.

---

## 📄 License

This repository is licensed under the [MIT License](LICENSE).

---

## 👨‍💻 Author

**Bhavishya Dewangan**  
*B.Tech Computer Science & Engineering (3rd Semester)*  
*Raipur, Chhattisgarh, India*  
GitHub: [@bhavishya0922](https://github.com/bhavishya0922) | Email: bhavish0922@gmail.com
