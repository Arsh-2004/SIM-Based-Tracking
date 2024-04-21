#include <SoftwareSerial.h>

// Define the pins used for serial communication with SIM800L module
#define SIM800_TX_PIN D1  // Connect to SIM800L RX pin
#define SIM800_RX_PIN D2  // Connect to SIM800L TX pin

// Define the baud rate for serial communication
#define SIM800_BAUDRATE 9600

// Create a SoftwareSerial object for SIM800L communication
SoftwareSerial sim800Serial(SIM800_RX_PIN, SIM800_TX_PIN);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  delay(1000); // Wait for serial monitor to initialize

  // Initialize SIM800L serial communication
  sim800Serial.begin(SIM800_BAUDRATE);
  delay(1000); // Wait for SIM800L to stabilize

  Serial.println("Ready to send AT commands to SIM800L. Type commands in the serial monitor:");
}

void loop() {
  // Check if there's any command input from the serial monitor
  if (Serial.available()) {
    // Read the command input from the serial monitor
    String command = Serial.readStringUntil('\n');

    // Send the command to the SIM800L module
    sim800Serial.println(command);

    // Print the command sent to the SIM800L module
    Serial.print("Sent command to SIM800L: ");
    Serial.println(command);

    // Wait for response from the SIM800L module
    delay(1000);

    // Check if there's any response available
    if (sim800Serial.available()) {
      // Read response from SIM800L module
      String response = sim800Serial.readString();

      // Print response from SIM800L module
      Serial.print("Response from SIM800L: ");
      Serial.println(response);
    } else {
      // No response received
      Serial.println("No response received from SIM800L.");
    }
  }
}
