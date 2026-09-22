#include <Arduino.h>
#include <Wire.h>

int16_t readMultiByte(uint8_t deviceAddress, uint8_t registerAddress, byte* buffer, uint8_t length) {
    Wire.beginTransmission(deviceAddress);
    Wire.write(registerAddress);
    Wire.endTransmission(false);

    Wire.requestFrom(deviceAddress, length);

    for (int i = 0; i < length; i++) {
        if (Wire.available()) {
            buffer[i] = Wire.read();
        } else {
            buffer[i] = 0;
        }
    }
    return 0;
}
