# SIM-Based Tracking System with ESP8266/ESP32

This project implements a SIM-based tracking system using the ESP8266 NodeMCU or ESP32 Dev Board. The system tracks the location of a device using a GPS module and transmits the data over the cellular network using a GSM/GPRS module.

## Features

- Real-time GPS tracking
- Cellular network communication
- Low-cost hardware components
- Easy to deploy and configure

## Hardware Requirements

- ESP8266 NodeMCU or ESP32 Dev Board
- SIM800L GSM/GPRS module
- NEO-6M GPS module
- Prepaid SIM card
- USB power bank or battery pack

## Software Requirements

- Arduino IDE
- Arduino libraries for ESP8266 or ESP32
- TinyGPS++ library for GPS parsing

## Installation

1. Install the Arduino IDE on your computer.
2. Install the necessary board support package for ESP8266 or ESP32 in the Arduino IDE.
3. Connect the hardware components according to the wiring diagram.
4. Open the Arduino sketch file (`tracking_system.ino`) in the Arduino IDE.
5. Configure the firmware settings (e.g., APN, destination phone number) in the sketch file.
6. Compile and upload the sketch to your ESP8266 or ESP32 board.

## Usage

1. Power on the tracking system using a USB power bank or battery pack.
2. Wait for the system to establish communication with the cellular network and acquire GPS fix.
3. The system will continuously track the device's location and transmit the data over the cellular network.
4. Monitor the transmitted data on the receiving end (e.g., server, mobile phone).

## Contributing

Contributions to this project are welcome! Please feel free to fork the repository, make changes, and submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
