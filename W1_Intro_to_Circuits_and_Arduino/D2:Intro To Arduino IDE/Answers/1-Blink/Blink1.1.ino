// Answer may not look exactly like example
void setup(){ 
    pinMode(LED_BUILTIN, OUTPUT); 
}

void loop(){ // loop runs over and over
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);                     
    digitalWrite(LED_BUILTIN, LOW);  
    delay(200);    // changed low time to be shorter than high
}