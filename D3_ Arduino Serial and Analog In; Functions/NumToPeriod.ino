/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  ForLoops.ino // slide 34

Write a program that takes the following as input:
“number1 number2”
and blinks LED1 on and off with a period of number1
and blinks LED2 on and off with a period of number2

Wire up a circuit and show it

*/

const int redPin = 3;
const int greenPin = 5;
int period1 = 0;
int period2 = 0;

void setup(){
    Serial.begin(9600);

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void loop(){
    // take in values
    if(Serial.available()>0){
        period1 = Serial.parseInt();
        char garbage = Serial.read();
        period2 = Serial.parseInt();
        garbage = Serial.read();
    }

    // set pins based on values
    uint_32t timeNow = millis();
    if(timeNow % period1 == 0){
        digitalWrite(redPin, !digitalRead(redPin));
    }
    if(timeNow % period2 == 0){
        digitalWrite(greenPin, !digitalRead(greenPin));
    }
}