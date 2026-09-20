#include <Arduino.h>
#include <Wire.h>

void readRegister(uint8_t deviceAddress, uint8_t registerAddress) {
    Wire.beginTransmission(deviceAddress);
    Wire.write(registerAddress);

    uint8_t error = Wire.endTransmission(false);

    Serial.print("endTransmission error: ");
    Serial.println(error);

    Wire.requestFrom(deviceAddress, (uint8_t)1);
    if (Wire.available()) {
        uint8_t value = Wire.read();

        Serial.print("Value read from device 0x");
        Serial.print(deviceAddress, HEX);
        Serial.print(", register 0x");
        Serial.print(registerAddress, HEX);
        Serial.print(": 0x");
        Serial.println(value, HEX);
    } else {
        Serial.println("Failed to read from device");
    }
}