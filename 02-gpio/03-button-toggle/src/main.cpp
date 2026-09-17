#include <Arduino.h>

#define BUTTON_PIN 4
#define LED_PIN 5

bool ledState = false;
int lastButtonState = HIGH;

void validateButtonState(int buttonState, bool &ledState, int &lastButtonState) {
    if (buttonState == LOW && lastButtonState == HIGH) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
    } 
    lastButtonState = buttonState;
}

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);
    Serial.print("Button state: ");
    Serial.println(buttonState);

    Serial.print("LED state: ");
    Serial.println(ledState);

    validateButtonState(buttonState, ledState, lastButtonState);

    delay(500);
}