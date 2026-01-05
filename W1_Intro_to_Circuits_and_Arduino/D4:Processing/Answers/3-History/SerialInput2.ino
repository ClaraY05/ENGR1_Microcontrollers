// example may not match answer exactly
// use arduino code as input for MULTIPLE INPUTS

const int pin_in1 = 13;
const int pin_in2 = 11;

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println(String(analogRead(pin_in1)) + " " + String(analogRead(pin_in2)));
}