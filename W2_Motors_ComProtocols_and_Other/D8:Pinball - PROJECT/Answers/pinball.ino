#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
int rightButton = 2;
int leftButton = 3;
int photoResIn = A0;
int servoConnect = 9;
int score = 0;

void setup() {
  myservo.attach(servoConnect);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int pastscore = score;

  // control paddles
  if(!digitalRead(rightButton)){ // if right button is pressed
    myservo.write(45);
    delay(15);
    myservo.write(0);
    delay(15);
  }
  else if(!digitalRead(leftButton)){ // if left button is pressed
    myservo.write(180-45);
    delay(15);
    myservo.write(0);
    delay(15);
  }

  // control score keeping
  float Vout = (analogRead(photoResIn)/1023.0)*5.0;
  float R = (Vout*10000)/(5-Vout);

  if(R < 300){
    delay(200);
    score += 1;
  }

  if(pastscore!= score){
    Serial.println(score);
  }
}
