// Answer may not look exactly like example
void setup(){ 
    pinMode(2, OUTPUT); 
    pinMode(3, OUTPUT); 
}

void loop(){ // loop runs over and over
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    delay(1000);                     
    digitalWrite(2, LOW);  
    digitalWrite(3, HIGH);
    delay(200);    // alternated times for high and low
}