#include <Arduino.h>

#define LED_PIN 2
#define PWM_FREQ 5000
#define PWM_RESOLUTION 8
#define LED_CHANNEL 0

void setup() {
    pinMode(LED_PIN, OUTPUT);
    ledcSetup(LED_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, LED_CHANNEL);
}

void loop() {
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        ledcWrite(LED_CHANNEL, dutyCycle);
        delay(10);
    }
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        ledcWrite(LED_CHANNEL, dutyCycle);
        delay(10);
    }
}