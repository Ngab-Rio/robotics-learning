#include <Arduino.h>

#define LED_PIN 2
#define BUTTON_PIN 3

#define PWM_FREQ 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, PWM_CHANNEL);

    Serial.begin(115200);
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == LOW) {
        ledcWrite(PWM_CHANNEL, 255);
    } else {
        ledcWrite(PWM_CHANNEL, 64);
    }
}