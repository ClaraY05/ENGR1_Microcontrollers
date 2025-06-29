/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  Brightness.ino
*/

const int pin_in = 13;

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println(analogRead(pin_in));
}