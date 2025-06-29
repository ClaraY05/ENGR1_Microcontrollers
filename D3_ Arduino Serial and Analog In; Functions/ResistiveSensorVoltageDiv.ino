/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  ForLoops.ino // slide 45

  Make a voltage divider with R1 = 20k and R2 = photocell/photoresistor 
  from your Parts Pal and write a program to read Vout and print it to 
  the serial monitor. Use your understanding of the voltage divider to
  find the resistance of the photoresistor and print that too.

*/

float Vout = 0.0;
const float R1 = 20000.0;
float R2 = 0;

const int pin_in = 13;

void setup(){
    Serial.begin(9600);
}

void loop(){
    Vout = digitalRead(pin_in)*(5.0/1024.0);
    R2 = (Vout*R1)/(5.0-Vout);
    Serial.println("VOLTAGE: "+String(Vout)+", RESISTANCE: "+String(R2));
}