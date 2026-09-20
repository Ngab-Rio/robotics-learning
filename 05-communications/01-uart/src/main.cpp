#include <Arduino.h>

#define LED_PIN 2

String message;
bool ledState = false;

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    Serial.print("LED Controller ");
}

void loop() {
    if (Serial.available() > 0) {
        message = Serial.readStringUntil('\n');
        message.trim();
        message.toLowerCase();
        if (message == "on" || message == "ON") {
            digitalWrite(LED_PIN, HIGH);
            ledState = true;
            Serial.println("-> LED Menyala");
        } else if (message == "off" || message == "OFF") {
            digitalWrite(LED_PIN, LOW);
            ledState = false;
            Serial.println("-> LED Mati");
        } else if (message == "status" || message == "STATUS") {
            Serial.print("-> LED ");
            Serial.println(ledState ? "Menyala" : "Mati");
        } else {
            Serial.println("-> Perintah tidak dikenal!");
        }
    }

    delay(100);
}