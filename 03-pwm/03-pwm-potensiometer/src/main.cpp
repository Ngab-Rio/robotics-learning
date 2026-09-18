#include <Arduino.h>

#define LED_PIN 2
#define POT_PIN 34

#define PWM_FREQ 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);

    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void loop() {
    int potValue = analogRead(POT_PIN);
    int pwmValue = map(potValue, 0, 4095, 0, 255);
    ledcWrite(PWM_CHANNEL, pwmValue);
}