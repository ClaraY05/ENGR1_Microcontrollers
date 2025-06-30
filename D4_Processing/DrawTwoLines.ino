/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  DrawTwoLines.ino
*/

const int pin_in = A0;
const int pin_in2 = A1;

void setup(){
    Serial.begin(9600);
}

void loop(){
    // print two values at once
    Serial.print(analogRead(pin_in));
    Serial.print(" ");
    Serial.println(analogRead(pin_in2));
}