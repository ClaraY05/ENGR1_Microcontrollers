/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  SineWaveGen.ino

  Write an Arduino program to try to make a sine wave output using low pass filtered PWM 
*/

int vOut = 11;
const float freq = 50.0;
uint32_t timeNow = 0;

int redV, greenV, blueV;

void setup(){
    Serial.begin(9600);
    pinMode(vOut, OUTPUT);
}

void loop(){
   timeNow = millis()/1000;
   analogWrite(vOut, 255*0.5*(1+sine(2*PI*freq*timeNow)));
}