#include <Arduino.h>

const int PIN_BUZZER = 1;
const int PIN_PIR = 3;
const int PIN_SOUND = 2;

const int SENSOR_THRESHOLD = 150;
const int DELAY = 1000;

bool detectPir = false;
bool detectSound = false;

void setup() {
    delay(1000);

    // All pins are capable of Digital output, though P5 is 3 V at HIGH instead of 5 V
    pinMode(PIN_BUZZER, OUTPUT);

    delay(100);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(100);
    digitalWrite(PIN_BUZZER, LOW);

    delay(10000);
}

void readPir() {
    int value = analogRead(PIN_PIR);
    detectPir = value <= SENSOR_THRESHOLD;
}

void readSound() {
    int value = analogRead(PIN_SOUND);
    detectSound = value <= SENSOR_THRESHOLD;
}

void loop() {
    // The analog pins are not named the same:
    // A0 → P5
    // A1 → P2
    // A2 → P4
    // A3 → P3

    // int value = digitalRead(1); //Returns HIGH or LOW (true or false / 1 or 0).
    // int value = analogRead(1); // Return analog value in range 0-255
    // analogWrite(0,255); //Turn the pin on full (100%)
    // digitalWrite(1, HIGH); // Set digital output to max value
    // digitalWrite(1, LOW); // Set digital output to min value

    readSound();
    readPir();

    if (detectPir || detectSound) {
        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);
        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);
        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);
        digitalWrite(PIN_BUZZER, HIGH);
        delay(300);
        digitalWrite(PIN_BUZZER, LOW);

        detectPir = false;
        detectSound = false;
        delay(DELAY);
    }
}