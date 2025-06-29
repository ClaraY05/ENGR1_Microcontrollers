/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  ForLoops.ino // slide 26

  Write a program that increments a counter every time you press the button and prints the count to Serial.
    Run this program and look at Serial Plotter

*/

const int pin_in = 13;
int counter = 0;

void setup(){
    Serial.begin(9600);
    pinMode(pin_in, INPUT_PULLUP);
}

void loop(){
    if(!digitaRead(pin_in)){ // tracks when button is pressed
        counter += 1;
        delay(300);
    }
    Serial.println(counter); // prints out to serial
}