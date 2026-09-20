#include <Arduino.h>

#define POT_PIN 34

long total;
float average;

unsigned long startTime;
unsigned long endTime;

void setup() {
    Serial.begin(115200);
}

void loop() {
    int sampleCount = 100;
    total = 0;

    startTime = millis();

    for (int i = 0; i < sampleCount; i++) {
        int potValue = analogRead(POT_PIN);
        Serial.print("Raw ADC : ");
        Serial.println(potValue);
        total += potValue;
    }

    endTime = millis();
    
    float duration = (endTime - startTime) / 1000.0;
    float samplingRate = sampleCount / duration;
    
    average = total / (float)sampleCount;
    
    Serial.print("ADC Average (Filtered) : ");
    Serial.println(average);
    
    Serial.print("Duration : ");
    Serial.print(duration, 3);
    Serial.println(" s");
    
    Serial.print("Sampling Rate : ");
    Serial.print(samplingRate, 2);
    Serial.println(" Hz");
    
    delay(2000);
}