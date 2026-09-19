#include <Arduino.h>

#define POT_PIN 34

void setup() {
    Serial.begin(115200);
}

void loop() {
    int potValue = analogRead(POT_PIN);

    float voltage = potValue * 3.3 / 4095;

    float percentage = potValue * 100.0 / 4095;

    Serial.print("ADC: ");
    Serial.print(potValue);

    Serial.print(" | Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");

    Serial.print(" | Percentage: ");
    Serial.print(percentage);
    Serial.println(" %");

    delay(100);
}