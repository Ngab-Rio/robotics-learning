#include <Arduino.h>
#include <Wire.h>
#include "scanner.h"
#include "readRegister.h"
#include "readMultiByte.h"

#define SCL_PIN 22
#define SDA_PIN 21

#define MPU_6050_ADDR 0x69
#define WHO_AM_I_REG 0x75

void setup() {
    Wire.begin(SDA_PIN, SCL_PIN);
    Wire.beginTransmission(MPU_6050_ADDR);
    Wire.write(0x6B); // Alamat PWR_MGMT_1
    Wire.write(0x00); // Bangunkan dari sleep mode
    Wire.endTransmission(true);
    Serial.begin(115200);
    // Serial.println("I2C Scanner");
}

void loop() {

    // SCANNER
    runScanner();

    // READ WHO_AM_I REGISTER
    readRegister(MPU_6050_ADDR, WHO_AM_I_REG);

    // READ ACCELEROMETER DATA ADN MULTIPLE BYTE
    byte buffer[6];
    readMultiByte(MPU_6050_ADDR, 0x3B, buffer, 6);

    int16_t accelX = (int16_t)((buffer[0] << 8) | buffer[1]);
    int16_t accelY = (int16_t)((buffer[2] << 8) | buffer[3]);
    int16_t accelZ = (int16_t)((buffer[4] << 8) | buffer[5]);

    float ax = accelX / 16384.0;
    float ay = accelY / 16384.0;
    float az = accelZ / 16384.0;

    Serial.print("X: ");
    Serial.print(ax);

    Serial.print(" | Y: ");
    Serial.print(ay);

    Serial.print(" | Z: ");
    Serial.println(az);

    delay(500);
}
