# Siemens MindSphere Integration Tutorial

## Introduction

Welcome to the Siemens MindSphere Integration Tutorial! This blueprint demonstrates how to connect a Particle device to Siemens MindSphere, enabling real-time data transfer using the Timeseries REST API. In this tutorial, you’ll configure a Particle webhook to send temperature data from a Particle device to MindSphere, where the data can be securely stored, visualized, and analyzed.

Every 10 seconds, the Particle device captures temperature readings and publishes this data to MindSphere via the webhook. MindSphere then stores this data in its time-series database, allowing you to view historical trends and generate insights for applications like equipment monitoring and environmental analysis.

## Hardware Requirements

For this project, you’ll need:

1.  **Particle MCU Development Board** (e.g., Argon, Boron)  
    [Purchase here](https://store.particle.io/collections/all-products?filter.p.product_type=Development%20Boards)
2.  **Grove Temperature & Humidity Sensor (DHT11)**  
    [Seeed Studio Sensor Details](https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/)
3.  **Particle Grove Shield**  
    [Particle Grove Shield Details](https://docs.particle.io/reference/datasheets/accessories/gen3-accessories/)

The Particle Grove Shield is essential for connecting the Grove sensor to the Particle board without the need for soldering.

## Table of Contents

- [Siemens MindSphere Integration Tutorial](#siemens-mindsphere-integration-tutorial)
  - [Introduction](#introduction)
  - [Hardware Requirements](#hardware-requirements)
  - [Table of Contents](#table-of-contents)
  - [Tutorial - Getting Started](#tutorial---getting-started)
    - [1. Configure the Grove Shield and Sensor](#1-configure-the-grove-shield-and-sensor)
    - [2. Set Up and Flash the Firmware](#2-set-up-and-flash-the-firmware)
    - [3. Monitor the Device’s Data and Alerts](#3-monitor-the-devices-data-and-alerts)
  - [Firmware Details](#firmware-details)
  - [Cloud Functionality](#cloud-functionality)
    - [Ledger Time-Series Database](#ledger-time-series-database)
    - [Temperature Conversion and Alerts](#temperature-conversion-and-alerts)
  - [Contributions](#contributions)
    - [How to Contribute](#how-to-contribute)
  - [Change List](#change-list)
  - [Supported Hardware](#supported-hardware)
  - [License](#license)

## Tutorial - Getting Started

### 1\. Configure the Grove Shield and Sensor

Connect the **Grove Temperature & Humidity Sensor** to the Grove Shield, then attach the Grove Shield to your Particle device.

### 2\. Set Up and Flash the Firmware

Ensure your Particle device is registered and connected to your Particle account. You can do this via [setup.particle.io](https://setup.particle.io/).

Clone or download this project repository and open it in Visual Studio Code or another code editor with Particle support.

Flash the firmware to your device. You can use Visual Studio Code with the **Cloud Flash** command, or the Particle CLI with the command:

```
particle flash <device_name>
```

### 3\. Monitor the Device’s Data and Alerts

With the firmware running, the Particle device will publish temperature (in Celsius) and humidity data to the cloud every 10 seconds.

To view real-time data, open the [Particle Console](https://console.particle.io) or use the serial monitor in Visual Studio Code by running:

```
particle serial monitor --follow
```

Temperature readings exceeding the threshold (e.g., 30°C) will trigger alerts in the cloud, visible in the Console and potentially actionable through notifications.

## Firmware Details

The firmware reads temperature and humidity values from the Grove sensor every 10 seconds and publishes them to the cloud. It uses standard Particle APIs and includes basic logging for ease of troubleshooting.

*   **Temperature**: Measured in Celsius from the sensor.
*   **Humidity**: Measured as relative humidity (%) from the sensor.
*   **Interval**: Data is collected and published every 10 seconds.

## Cloud Functionality

### Ledger Time-Series Database

The **Ledger** service is used to store the published data. Each temperature and humidity reading is saved with a timestamp, allowing for easy analysis and historical review.

*   **Database**: Stores temperature and humidity readings over time.
*   **Data Format**: Includes both Celsius and converted Fahrenheit temperatures, as well as humidity.

### Temperature Conversion and Alerts

When the cloud receives temperature data, it automatically converts the value from Celsius to Fahrenheit. The system also checks the current temperature against a predefined threshold (e.g., 30°C).

*   **Temperature Alert**: Triggers if the temperature exceeds the threshold.
*   **Threshold Setting**: Configurable in the Ledger database, allowing real-time adjustment of alert sensitivity.

## Contributions

We welcome contributions to this blueprint! If you'd like to suggest changes, please open a pull request in the [Environmental Monitoring GitHub Repository](https://github.com/particle-iot/environmental-monitoring-tutorial).

### How to Contribute

1.  Fork the repository.
2.  Make your changes in a new branch.
3.  Open a pull request with a detailed description of your changes.

## Change List

*   **v1.0.0**: Initial release, with core functionality for environmental monitoring and alert system.

## Supported Hardware

This blueprint supports all **Particle MCU Development Boards** and works specifically with the **Grove Temperature & Humidity Sensor** and **Particle Grove Shield** for seamless sensor integration.

*   [Particle MCU Development Boards](https://store.particle.io/collections/all-products?filter.p.product_type=Development%20Boards)
*   [Grove Temperature & Humidity Sensor (DHT11)](https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/)
*   [Particle Grove Shield](https://docs.particle.io/reference/datasheets/accessories/gen3-accessories/)

## License

This project is licensed under the MIT License. For details, see the LICENSE file in the repository.

- - -

By following this tutorial, you can easily set up an environmental monitoring system that leverages Particle's cloud capabilities and provides actionable insights through data collection and alerting. Happy monitoring!
