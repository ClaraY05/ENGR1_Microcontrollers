// example may not match answer exactly
// use arduino code as input for ALL EXAMPLES OF PROCESSING CODE EXCEPT MULTIPLE INPUTS

const int pin_in = 13;

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println(analogRead(pin_in));
}