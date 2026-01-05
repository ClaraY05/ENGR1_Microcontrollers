// answers may vary from example
#include <Servo.h> // include servo library

const int servoPWM = 11;
Servo myservo;

void setup(){
    Serial.begin(9600);
    myservo.attach(servoPWM);   // attach pin to servo
    Serial.println("INPUT A DEGREE (0-180): ");
}

void loop(){
    // receive analog input and complete command
    if(Serial.available() > 0){
        int movementDeg = Serial.parseInt(); // (0-180)
        if((movementDeg >= 0) && (movementDeg <= 180)){
            moveToDeg(myservo, movementDeg);
        }
        Serial.println("INPUT A DEGREE (0-180): ");
    }
}

void moveToDeg(Servo &s, int degree){
    if(s.attached()) s.write(degree);
}