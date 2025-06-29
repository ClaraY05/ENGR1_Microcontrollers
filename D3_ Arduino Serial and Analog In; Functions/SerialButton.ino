/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  ForLoops.ino // slide 15

  Connect a button to one of the digital input pins on your Arduino
  Write a program that prints the button state over Serial
*/

const int pin_in = 13;
bool isOn = false;

void setup(){
    Serial.begin(9600); // baud_rate
    pinMode(pin_in, INPUT_PULLUP);
}

void loop(){
    if(!pin_in){
        isOn = true; // flips every time it is pressed and not pressed
        Serial.println("ON!");
        delay(10);   // account for button delays
    }
    if else((isOn == true)&&(pin_in)){
        isOn = false;
        Serial.println("OFF!");
    }
}