#include <Arduino.h>

#define BUTTON_PIN 4
#define LED_PIN 5

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLDOWN);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);
    Serial.print("Button state: ");
    Serial.println(buttonState);

    if (buttonState == HIGH) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}