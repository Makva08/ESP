#include <BluetoothSerial.h>
#include <SPI.h>
#include <Adafruit_MAX31855.h>

#define MAXDO   4   // Data Out (DO) on MAX31855
#define MAXCS   2   // Chip Select (CS) on MAX31855
#define MAXCLK  15  // CLK on MAX31855

BluetoothSerial SerialBT;
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

void setup() {
  Serial.begin(115200); // Don't forget to change baud rate on serial monitor as well :)
  SerialBT.begin("ESP32_Thermocouple");
  Serial.println("Bluetooth Device is Ready to Pair");

  if (!thermocouple.begin()) {
    Serial.println("Could not initialize MAX31855.");
    while (1);
  }
  Serial.println("MAX31855 initialized.");
}

void loop() {
  double tempC = thermocouple.readCelsius();
  double tempF = thermocouple.readFahrenheit();

  if (isnan(tempC)) {
    Serial.println("Error: Could not read temperature");
    SerialBT.println("Error: Could not read temperature");
  } else {

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print(" °C / ");
    Serial.print(tempF);
    Serial.println(" °F");

    SerialBT.print("Temperature: ");
    SerialBT.print(tempC);
    SerialBT.print(" °C / ");
    SerialBT.print(tempF);
    SerialBT.println(" °F");
  }

  delay(30000); // I'm sending data every 30s, change that if needed.
}
