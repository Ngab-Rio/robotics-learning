#include <Arduino.h>
#include <MyServo.h>

#define SERVO_PIN 4
#define POT_PIN 34

Servo myServo;

void setup() {
    Serial.begin(115200);

    myServo.attach(SERVO_PIN);
}

void loop() {
    int potValue = analogRead(POT_PIN);

    int servoValue = map(potValue, 0, 4095, 0, 180);

    myServo.write(servoValue);

    Serial.print("ADC: ");
    Serial.print(potValue);
    Serial.print(" | Servo: ");
    Serial.println(servoValue);
}