/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  ForLoops.ino // slide 15
*/
int ledPinsOut[5] = {13,12,11,10,9};

// the setup function runs once when you press reset or power the board
void setup() {
    // set pin modes for all values in the array
    for(int i = 0; i<5; i++){
        pinMode(ledPinsOut[i], OUTPUT);
    }
}

// the loop function runs over and over again forever
void loop() {
    // makes each pin have a high for 500 ms at a time
    for(int i = 0; i<5; i++){
        digitalWrite(ledPins[i], HIGH);
        delay (500);
        digitalWrite(ledPins[i],LOW);
    }
}