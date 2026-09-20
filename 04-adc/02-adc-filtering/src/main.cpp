#include <Arduino.h>

#define POT_PIN 34

long total;
float average;

void setup() {
    Serial.begin(115200);
}

void loop() {
    total = 0;
    
    for (int i = 0; i < 10; i++) {
        int potValue = analogRead(POT_PIN);
        Serial.print("Raw ADC : ");
        Serial.println(potValue);
        total += potValue;
        delay(10);
    }

    average = total / 10.0;

    Serial.print("ADC Average (Filtered) : ");
    Serial.print(average);

    delay(2000);
}