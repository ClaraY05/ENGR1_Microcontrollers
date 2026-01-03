// answer may not match exactly
int pin_out = 13;

void setup(){
    Serial.begin(9600);
    pinMode(pin_out, OUTPUT); // make an output pin to send to LED
}

void loop(){
    if(Serial.available() > 0){ // if char typed in bar
        // read value until enter
        String input_string = Serial.readStringUntil('\n'); // reads every newline char
        if(input_string == "ON"){
            digitalWrite(pin_out, HIGH);
        }
        if(input_string == "OFF"){
            digitalWrite(pin_out, LOW);
        }
    }
}