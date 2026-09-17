#include <Arduino.h>

#define BUTTON_PIN 4

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);
    Serial.print("Button state: ");
    Serial.println(buttonState);

    delay(500);
}