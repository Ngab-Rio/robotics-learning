#include <Arduino.h>
#include <Wire.h>
#include "scanner.h"
#include "readRegister.h"

#define SCL_PIN 26
#define SDA_PIN 25

#define MPU_6050_ADDR 0x68
#define WHO_AM_I_REG 0x75

void setup() {
    Wire.begin(SDA_PIN, SCL_PIN);
    Serial.begin(115200);
    // Serial.println("I2C Scanner");
}

void loop() {

    // runScanner();
    readRegister(MPU_6050_ADDR, WHO_AM_I_REG);
    delay(1000);
}
