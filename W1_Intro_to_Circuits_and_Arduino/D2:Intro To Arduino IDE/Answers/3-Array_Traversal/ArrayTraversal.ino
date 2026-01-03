// Answer may not exactly match

// setup constants
int ledPins[5] = {3,4,5,6,7};  // make sure to wire with resistors!

void setup(){
    // set all pins to output
    for(int a = 0; a<5; a++>){ pinMode(ledPins[a], OUTPUT);}
}

void loop(){
    // set each pin to high for 500ms then turn off
    for (int b = 0; b<5; b++){
        digitalWrite(ledPins[b],HIGH);
        delay(500);
        digitalWrite(ledPins[b], LOW);
    }
}