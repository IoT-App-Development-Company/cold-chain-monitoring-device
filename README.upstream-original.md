# Smart IoT-Enabled Cold Chain Monitoring System with Automated Temperature Control and GPS/GSM Tracking

## Abstract

The project presents a low-cost IoT-enabled cold chain monitoring system designed to ensure the safe transportation and storage of temperature-sensitive products such as vaccines, pharmaceuticals, blood products, and food items. Built around the ESP32 microcontroller, the system continuously monitors temperature and humidity, displays live readings on an OLED display, generates local alerts through LEDs and a buzzer, and provides GSM-based notifications together with GPS tracking whenever temperature excursions occur. The solution offers a portable, scalable, and cost-effective approach for improving cold chain visibility, minimizing product spoilage, and enhancing supply chain reliability.

---

## Table of Contents

- [Abstract](#abstract)
- [Key Features](#key-features)
- [System Architecture](#system-architecture)
- [Working Principle](#working-principle)
- [Hardware Components](#hardware-components)
- [Software & Tools](#software--tools)
- [Repository Structure](#repository-structure)
- [ESP32 Prototype Firmware](#esp32-prototype-firmware)
- [Overall Block Diagram](#overall-block-diagram)
- [TinkerCAD Simulation](#tinkercad-simulation)
- [CAD Model](#cad-model)
- [PCB Schematic](#pcb-schematic)
- [Hardware Prototype](#hardware-prototype)
- [Results](#results)
- [Applications](#applications)
- [Future Scope](#future-scope)

---

## Key Features

- Real-time temperature and humidity monitoring
- GSM-based SMS alerts during temperature excursions
- GPS tracking for shipment location monitoring
- OLED display for live environmental data
- LED and buzzer for local warning indication
- Fast response time (3–5 seconds)
- Data logging and remote monitoring capability
- Low-power and portable embedded design
- Suitable for healthcare and logistics applications

---

## System Architecture

The proposed system integrates an ESP32 microcontroller with a DHT22 temperature and humidity sensor, GSM module, GPS module, OLED display, LED indicator, and passive buzzer. The ESP32 acts as the central controller by collecting sensor data, processing threshold conditions, activating local alarms, transmitting remote notifications, and displaying system status in real time to provide continuous monitoring of cold chain environments.

---

## Working Principle

The DHT22 sensor continuously measures the surrounding temperature and humidity, and the ESP32 periodically acquires these readings for processing. When the measured values remain within the predefined safe range, the OLED display updates the live environmental conditions. If the temperature exceeds the configured threshold, the controller immediately activates the LED and buzzer, sends an SMS alert through the GSM module, and provides the current shipment location using the GPS module, enabling quick response and preventive action.

---

## Hardware Components

| Component | Description |
|-----------|-------------|
| ESP32 | Main processing unit with integrated Wi-Fi and Bluetooth |
| DHT22 Sensor | Temperature and humidity sensing |
| GSM Module | SMS-based alert transmission |
| GPS Module | Live shipment location tracking |
| SSD1306 OLED Display | Real-time parameter display |
| Passive Buzzer | Audible alert indication |
| LED | Visual status indication |
| Power Supply | Portable battery/adapter source |
| Enclosure | Protective SolidWorks-designed casing |

---

## Software & Tools

| Software | Purpose |
|----------|---------|
| Arduino IDE | ESP32 firmware development |
| KiCad | PCB schematic design |
| SolidWorks | CAD enclosure design |
| TinkerCAD | Circuit simulation |
| GitHub | Version control and documentation |

---

## Repository Structure

```text
Smart-IoT-Enabled-Cold-Chain-Monitoring-System/

├── pcb/
│   └── schematic.pdf
│
├── cad/
│   └── enclosure.SLDPRT
│
├── sensor/
│   └── ColdChainMonitor.ino
│
└── README.md
```

---

## ESP32 Prototype Firmware

```text
sensor/
└── ColdChainMonitor.ino
```

The ESP32 firmware performs continuous acquisition of temperature and humidity data from the DHT22 sensor, updates the OLED display with live readings, evaluates threshold conditions, controls the LED and buzzer during abnormal situations, and communicates alert messages and location information using the GSM and GPS modules.

---

## Overall Block Diagram

<p align="center">
  <img width="1127" height="861" alt="image" src="https://github.com/user-attachments/assets/154ebbc3-1e79-4aad-94cf-37f5b0393d27" />
</p>

*Figure 1. Overall Block Diagram*

The block diagram illustrates the interaction between the ESP32 controller, sensing module, communication peripherals, display unit, and alert devices, highlighting the complete data flow from sensor acquisition to user notification.

---

## TinkerCAD Simulation

<p align="center">
  <img width="480" height="275" alt="image" src="https://github.com/user-attachments/assets/6980d300-9b36-43f0-8340-1a068df336d1" />
</p>

*Figure 2. This shows the partial circuit connections, barring the GSM and GPS module connections*

The TinkerCAD simulation was used during the initial prototyping stage to verify sensor interfacing, display functionality, threshold detection logic, and alert generation before implementing the complete ESP32-based hardware prototype.

---

## CAD Model


<img width="696" height="501" alt="image" src="https://github.com/user-attachments/assets/b38c4ab8-3e7f-4b1e-b89f-ce59d6d101e2" />


<img width="516" height="800" alt="image" src="https://github.com/user-attachments/assets/f5f2b7b1-4f0b-41e4-9d12-3216446f451e" />


*Figure 3. CAD Enclosure Model and Heat-flow results*

The enclosure was designed in SolidWorks to provide a compact and protective housing for the electronic components while allowing convenient access to sensors, communication modules, and the power supply.

---

## PCB Schematic

<p align="center">
  <img width="975" height="631" alt="image" src="https://github.com/user-attachments/assets/f3c7a6d7-cb30-49b6-9112-d15c05f86420" />
</p>

*Figure 4. PCB Schematic*

The PCB schematic presents the complete electrical connectivity between the ESP32, DHT22 sensor, OLED display, GSM module, GPS module, power circuitry, and supporting peripheral components for reliable system operation.

---

## Hardware Prototype

### Prototype Setup

<p align="center">
  <img width="480" height="267" alt="image" src="https://github.com/user-attachments/assets/97d0ff5f-4af9-4e09-a969-caf6e651280d" />
</p>

*Figure 5. Hardware Prototype – Setup*

The first hardware prototype demonstrates the practical integration of all electronic components on the development platform, validating sensor communication, display output, and embedded processing.

### Prototype Demonstration

<p align="center">
  <img width="480" height="264" alt="image" src="https://github.com/user-attachments/assets/6897a650-43fd-4a20-ab2a-58391ff031a0" />

  <img width="480" height="268" alt="image" src="https://github.com/user-attachments/assets/51d42889-9633-4881-aa6e-ad517631e8d5" />
</p>

*Figure 6. Hardware Prototype – Working Demonstration: Shows the System's operation outside the specified temperature range, i.e., in alert mode and inside the specified temperature range, i.e., in normal mode*

The completed prototype demonstrates real-time environmental monitoring together with alert generation, OLED visualization, and wireless communication under different operating conditions.

---

## Results

The developed prototype successfully monitored temperature and humidity in real time while providing immediate notification during abnormal conditions. The OLED displayed live environmental parameters, the LED and buzzer generated local alerts, and the GSM and GPS modules enabled remote notification and shipment tracking. The system achieved a rapid response time and demonstrated reliable operation during laboratory testing.

---

## Applications

- Vaccine transportation
- Pharmaceutical cold chain logistics
- Blood banks and blood transportation
- Food cold storage and distribution
- Medical laboratories
- Temperature-sensitive warehouse monitoring
