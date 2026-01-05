// answers may vary from example

int pin2 = 11;
int pin3 = 10;
int pin4 = 9;

void setup(){
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}

void loop(){
    for(int i = 0; i<256; i++){ // varies pin2
        for(int j = 0; j<256; j++){ // varies pin 3
            for(int k = 0; k<256; k++){ // varies pin4;
                analogWrite(pin2, i);
                analogWrite(pin3, j);
                analogWrite(pin4, k);
                delay(10);
            }
        }
    }
}