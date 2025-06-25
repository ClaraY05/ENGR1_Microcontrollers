/*
  Adapted Blink Code from
  https://docs.arduino.cc/hardware/

  Adjusted for UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
*/
// set up constants
const int pin_red = 13;     // set up pin values for easier reference in code
const int pin_green = 12;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin_red, OUTPUT);
  pinMode(pin_green, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  /*
  Program uses delays to hold Writes for certain chunks of time, alternating
   when each pin is written HIGH vs. LOW results in different periods
  */
  digitalWrite(pin_red, HIGH);  // turn the LED off (LOW is the voltage level)
  digitalWrite(pin_green, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a half a second / hold these settings for half a second
  digitalWrite(pin_red, LOW); 
  digitalWrite(pin_green, HIGH);  
  delay(500);
  digitalWrite(pin_red, LOW); 
  digitalWrite(pin_green, LOW); 
  delay(500);
  digitalWrite(pin_red, HIGH); 
  digitalWrite(pin_green, LOW); 
  delay(500);
  digitalWrite(pin_red, HIGH); 
  digitalWrite(pin_green, HIGH); 
  delay(500);                  
  digitalWrite(pin_red, LOW); 
  digitalWrite(pin_green, HIGH);  
  delay(500);
  digitalWrite(pin_red, LOW); 
  digitalWrite(pin_green, LOW); 
  delay(500);
}

