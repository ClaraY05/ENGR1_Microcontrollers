/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  Switch.ino
*/
// set up constants
const int pin_red = 13;     // set up pin values for easier reference in code
const int pin_green = 12;
uint32_t timeNow = 0;       // create an unsigned long to hold millis time

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin_red, OUTPUT);
  pinMode(pin_green, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    timeNow = millis();

    // code for RED LED (holds on every 750 ms)
    if(timeNow%750 == 0){ // keep on for 1/2 of period
         digitalWrite(pin_red, HIGH);  // turn the LED off (LOW is the voltage level)
    }
    else if(timeNow%(750*2) == 0){ // turn off for other 1/2
        digitalWrite(pin_red, LOW);  // turn the LED on (HIGH is the voltage level)

    }

    // code for GREEN LED (holds on every 350 ms)
    if(timeNow%350 == 0){
         digitalWrite(pin_green, HIGH);
    }
    else if(timeNow%(350*2) == 0){
        digitalWrite(pin_green, LOW);  
    }
  
}

