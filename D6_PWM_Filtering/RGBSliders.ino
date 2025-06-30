/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  RGBSliders.ino

  Write a for loop that loops through Red, Green, and Blue colors in nested loops so all color combos are visited
*/

int pin2 = 11; //B
int pin3 = 10; //G
int pin4 = 9; // R
int vOut = 13;

int redV, greenV, blueV;

void setup(){
    Serial.begin(9600);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}

void loop(){
   if(Serial.available()>0){
    String inputString = Serial.readStringUntil('\n');
    redV = Serial.parseInt();
    char garbage = Serial.read();
    greenV = Serial.parseInt();
    garbage = Serial.read();
    blueV = Serial.parseInt();
    garbage = Serial.read();
   }
   analogWrite(pin4, redV);
   analogWrite(pin3, greenV);
   analogWrite(pin2, blueV);
}