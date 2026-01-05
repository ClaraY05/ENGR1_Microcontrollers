// example may not match answer exactly 

const int pin_in = 13;

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println(analogRead(pin_in));
}