#include <Arduino.h>

#define BUTTON_PIN_1 4
#define BUTTON_PIN_2 6

#define LED_PIN_1 5
#define LED_PIN_2 7

void setup() {
    pinMode(BUTTON_PIN_1, INPUT_PULLUP);
    pinMode(BUTTON_PIN_2, INPUT_PULLUP);
    pinMode(LED_PIN_1, OUTPUT);
    pinMode(LED_PIN_2, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    int buttonState1 = digitalRead(BUTTON_PIN_1);
    int buttonState2 = digitalRead(BUTTON_PIN_2);
    Serial.print("Button 1 state: ");
    Serial.println(buttonState1);
    Serial.print("Button 2 state: ");
    Serial.println(buttonState2);

    if (buttonState1 == HIGH) {
        digitalWrite(LED_PIN_1, LOW);
    } else {
        digitalWrite(LED_PIN_1, HIGH);
    }

    if (buttonState2 == HIGH) {
        digitalWrite(LED_PIN_2, LOW);
    } else {
        digitalWrite(LED_PIN_2, HIGH);
    }
}