#include <Arduino.h>

const int PIN_BUZZER = 1;
const int PIN_PIR = 1;
const int PIN_SOUND = 0;

const int SENSOR_THRESHOLD = 150;
const int DELAY = 3000;

bool detectPir = false;
bool detectSound = false;

void setup() {
    delay(1000);

    //All pins are capable of Digital output, though P5 is 3 V at HIGH instead of 5 V
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

    /*
    if (value > 0 && value < 50) {
        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(3000);
    } else if (value >= 50 && value < 100) {
        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);

        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(3000);
    } else if (value >= 100 && value < 150) {
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

        delay(3000);
    } else if (value >= 150 && value < 200) {
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

        delay(3000);

        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);

        delay(3000);
    } else if (value >= 200 && value <= 255) {
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

        delay(3000);

        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);
        digitalWrite(PIN_BUZZER, HIGH);
        delay(90);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);

        delay(3000);
    } else if (value > 255) {
        digitalWrite(PIN_BUZZER, HIGH);
        delay(1000);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);

        digitalWrite(PIN_BUZZER, HIGH);
        delay(1000);
        digitalWrite(PIN_BUZZER, LOW);
        delay(30);

        delay(3000);
    } 
    */

}

void loop() {
    // OJO LOS PINES ANALÓGICOS NO SE NOMBRAN IGUAL
    // sensorValue = digitalRead(1); //Returns HIGH or LOW (true or false / 1 or 0).
    //int value = analogRead(1);
    //analogWrite(0,255); //Turn the pin on full (100%)
    //digitalWrite(1, HIGH);
    //digitalWrite(1, LOW);

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

        detectPir = false;
        detectSound = false;
        delay(DELAY);
    }

    delay(50);
}