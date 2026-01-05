// example may not match answer exactly
const int notEnable = 1;
const int direction = 2;
const int step = 3;

void setup(){
    pinMode(notEnable, OUTPUT);
    pinMode(direction, OUTPUT);
    pinMode(step, OUTPUT);

    Serial.begin(9600);
    Serial.println("Input a degree: ");
}

void loop(){
    if(Serial.available() > 0){
        int userDegree = Serial.parseInt();
        moveToDegree(userDegree);
        Serial.println("Input a degree: ");
    }
}

int degreeToSteps(int degree){
    return degree*(200/360);   //about 200 steps in a full 360
}

void step(){
    digitalWrite(step, HIGH);
    delay(100);
    digitalWrite(step, LOW);
    delay(100);
}

void moveToDegree(int degree){
    if(degree < 0){
        pinMode(direction, LOW);
        degree *= -1;
    }
    else{pinMode(direction, HIGH);}
    pinMode(notEnable, LOW);

    int numSteps = degreeToSteps(degree);
    for(int i = 0; i< numSteps; i++){
        step();
    }

    pinMode(notEnable, HIGH);
}