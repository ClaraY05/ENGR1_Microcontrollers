// answer may not match exactly

// setup global vars
const int redPin = 3;
const int greenPin = 5;
int period1 = 0;
int period2 = 0;

void setup(){
    Serial.begin(9600);

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void loop(){
    // take in values
    if(Serial.available()>0){ // need to handle all submitted chars to exit
        period1 = Serial.parseInt();
        char garbage = Serial.read(); // deal with space in between nums
        period2 = Serial.parseInt();
        garbage = Serial.read();      // deal with end line char
    }

    // set pins based on values
    uint_32t timeNow = millis();
    if(timeNow % period1 == 0){
        // can actually read pins you set as OUTPUT 
        digitalWrite(redPin, !digitalRead(redPin)); // flip value to opposite of current
    }
    if(timeNow % period2 == 0){
        digitalWrite(greenPin, !digitalRead(greenPin));
    }
}