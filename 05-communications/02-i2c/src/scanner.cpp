#include <Arduino.h>
#include <Wire.h>

void runScanner() {
    byte error;
    int devices = 0;

    for (int i = 1; i < 127; i++) {
        Wire.beginTransmission(i);
        error = Wire.endTransmission();

        if (error == 0) {
            Serial.print("I2C device found at address 0x");
            if (i < 16) {
                Serial.print("0");
            }
            Serial.println(i, HEX);
            devices++;
        } else if (error == 4) {
            Serial.print("Unknown error at address 0x");
            if (i < 16) {
                Serial.print("0");
            }
            Serial.println(i, HEX);
        }
    }

    Serial.print("I2C devices found: ");
    Serial.println(devices);

    delay(1000);
}