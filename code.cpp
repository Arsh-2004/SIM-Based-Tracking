#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Define the pins used for serial communication with GSM/GPRS module
#define GSM_TX_PIN 2  // Connect to GSM module RX pin
#define GSM_RX_PIN 3  // Connect to GSM module TX pin

// Define the pins used for serial communication with GPS module
#define GPS_RX_PIN 4  // Connect to GPS module TX pin
#define GPS_TX_PIN 5  // Connect to GPS module RX pin

// Define the baud rates for serial communication
#define GSM_BAUDRATE 9600
#define GPS_BAUDRATE 9600

// Define the APN (Access Point Name) provided by the mobile network operator
const char apn[] = "your_apn";

// Define variables for GSM/GPRS and GPS serial communication
SoftwareSerial gsmSerial(GSM_RX_PIN, GSM_TX_PIN);
SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

// Define variables for GPS parsing
TinyGPSPlus gps;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  gsmSerial.begin(GSM_BAUDRATE);
  gpsSerial.begin(GPS_BAUDRATE);

  // Initialize GSM/GPRS module
  delay(1000);
  gsmSerial.println("AT");
  delay(1000);
  gsmSerial.println("AT+CFUN=1");
  delay(1000);
  gsmSerial.println("AT+CGATT=1");
  delay(1000);
  gsmSerial.print("AT+CSTT=\"");
  gsmSerial.print(apn);
  gsmSerial.println("\"");
  delay(1000);
  gsmSerial.println("AT+CIICR");
  delay(5000);
}

void loop() {
  // Read GPS data
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      // Retrieve GPS data
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();
      int satellites = gps.satellites.value();
      
      // Transmit GPS data over GSM/GPRS
      gsmSerial.print("AT+CMGS=\"+1234567890\""); // Replace with destination phone number
      gsmSerial.println("AT+CMGS=\"+1234567890\"");
      gsmSerial.println("Latitude: " + String(latitude, 6));
      gsmSerial.println("Longitude: " + String(longitude, 6));
      gsmSerial.println("Satellites: " + String(satellites));
      gsmSerial.write(0x1A);
      delay(5000); // Wait for response
    }
  }
}