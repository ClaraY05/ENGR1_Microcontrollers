/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  Switch.ino
*/
// set up constants
const int pin_a = 13;     // set up pin values for easier reference in code
const int pin_b = 12;
const int logic = 0; // 0 = a && b, 1 = a || b, 2 = !(a||b), 3 = a && !b
const int pin_out = 10;
const bool will_light = false;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an input pullup.
  pinMode(pin_a, INPUT_PULLUP);
  pinMode(pin_b, INPUT_PULLUP);
  pinMode(pin_out, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  switch(logic){
    // set logic
    case 0: // lights the LED if button1 AND button2 are pressed
      will_light = ((!digitalRead(pin_a))&&(!digitalRead(pin_b)));
      break;
    case 1: // lights the LED if button1 OR button2 are pressed
      will_light = ((!digitalRead(pin_a))||(!digitalRead(pin_b)));
      break;
    case 2: // lights the LED if NEITHER button1 NOR button2 are pressed
      will_light = (!((!digitalRead(pin_a))||(!digitalRead(pin_b))));
      break;
    case 3: //lights the LED if button1 is pressed AND button2 is NOT pressed
      will_light = ((!digitalRead(pin_a))&&(digitalRead(pin_b)));
      break;
    default:
      will_light = false;
      break;
  }

  // set pin mode
    if(will_light){
      digitalWrite(pin_out,HIGH);
    }
    else{
      digitalWrite(pin_out,LOW);
    }
}

