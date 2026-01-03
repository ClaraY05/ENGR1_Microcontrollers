// answer may not match exactly

// setup global vars
float Vout = 0.0;
const float R1 = 20000.0;
float R2 = 0;

const int pin_in = 13;  // pin 13 has an ADC

void setup(){
    pinMode(pin_in, INPUT);
    Serial.begin(9600);
}

void loop(){
    Vout = analogRead(pin_in)*(5.0/1024.0); // voltage bin equation
    Serial.println("VOLTAGE: "+String(Vout));
}