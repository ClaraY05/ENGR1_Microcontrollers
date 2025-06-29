/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  ForLoops.ino // slide 32

  Write a program that will turn on an LED if you type “ON”
 and will turn it off if you type “OFF”

*/
int pin_out = 13;

void setup(){
    Serial.begin(9600);
    pinMode(pin_out, OUTPUT); // make an output pin to send to LED
}

void loop(){
    if(Serial.available() > 0){ // if char typed in bar
        // read value
        String input_string = Serial.readStringUntil('\n'); // reads every newline char
        if(input_string == "ON"){
            digitalWrite(pin_out, HIGH);
        }
        if(input_string == "OFF"){
            digitalWrite(pin_out, LOW);
        }
    }
}