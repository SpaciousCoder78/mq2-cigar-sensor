# mq2-cigar-sensor
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)

An Arduino Sketch for MQ2 Smoke Sensor to detect Cigarette Smoke using ATmega328P boards

## Pre-Requisities
- Arduino IDE
- Arduino UNO
- MQ2 Smoke Sensor
- Wires
- Soldering Kit

## Circuit Diagram
![Untitled](https://github.com/SpaciousCoder78/mq2-cigar-sensor/assets/88923986/83c0bd0a-ab0d-42c0-a4d0-b16bef363787)

## Theory
We can measure PPM values using MQ2 sensor and a cigarette emits Carbon Monoxide(CO) as the main output gas so we're calibrating the MQ2 sensor to detect Carbon Monoxide levels and detect cigarettes.

## Required Arduino Libraries
- ![MQUnifiedSensor](https://github.com/miguel5612/MQSensorsLib) by Miguel Califa 
