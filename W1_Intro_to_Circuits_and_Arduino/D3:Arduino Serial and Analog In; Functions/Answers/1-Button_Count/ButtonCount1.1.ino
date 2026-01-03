// answer may not match exactly

// setup global vars
const int pin_in = 13;

void setup(){
    Serial.begin(9600);
    pinMode(pin_in, INPUT_PULLUP);
}

void loop(){
    if(!digitaRead(pin_in)){ // tracks when button is pressed
        Serial.println("Button Pressed!"); // prints out to serial
        delay(300);                        // handle debounce
    }
}