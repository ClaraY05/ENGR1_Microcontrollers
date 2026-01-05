void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(7, INPUT_PULLUP);
}

void loop() {
Serial.println(String(analogRead(0))+ " "+ String(analogRead(1))+ " "+String(digitalRead(7)));
delay(10);
}
