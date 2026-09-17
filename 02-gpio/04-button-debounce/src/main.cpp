// #include <Arduino.h>

#define BUTTON_PIN 4
#define LED_PIN 5

bool ledState = false;
int lastButtonState = HIGH;
int stableButtonState = HIGH;
unsigned long previousTime = 0;
int debounceDelay = 50;


void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    unsigned long currentTime = millis(); 
    int buttonState = digitalRead(BUTTON_PIN);
    
    Serial.print("Button state: ");
    Serial.println(buttonState);
    
    if (buttonState != lastButtonState) {
        previousTime = currentTime;
    }

    unsigned long elapsedTime = currentTime - previousTime;

    if (elapsedTime >= debounceDelay) {
        if (buttonState == LOW && stableButtonState == HIGH) {
            Serial.println("Button pressed");
            ledState = !ledState;
            digitalWrite(LED_PIN, ledState);
        }

        stableButtonState = buttonState;
    }

    lastButtonState = buttonState;
}