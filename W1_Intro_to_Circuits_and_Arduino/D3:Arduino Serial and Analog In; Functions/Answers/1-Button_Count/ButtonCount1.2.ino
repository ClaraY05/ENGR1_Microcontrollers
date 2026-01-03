// answer may not match exactly

// setup global vars
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