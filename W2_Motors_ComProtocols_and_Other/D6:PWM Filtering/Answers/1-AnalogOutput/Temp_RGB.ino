// answers may vary from example

int pin2 = 11;
int pin3 = 10;
int pin4 = 9;
int vOut = 13;

void setup(){
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}

void loop(){
    float cTemp = getTemperature(analogRead(vOut));
    if(cTemp < 23.0){ // blue
        analogWrite(pin4, 255);
        analogWrite(pin3, 255);
        analogWrite(pin2, 0);
    }
    else if(cTemp < 25.0){ // green
        analogWrite(pin4, 255);
        analogWrite(pin3, 0);
        analogWrite(pin2, 255);
    }
    else{ // red
        analogWrite(pin4, 0);
        analogWrite(pin3, 255);
        analogWrite(pin2, 255);
    }
}

float getTemperature(int Vout_adc){
    float Vout = Vout_adc*(5.0/1024.0);
    float Rtherm = (Vout*10000)/(5.0-Vout);
    float tempKelvin = 1.0/((1.0/298.0)+(1.0/3950.0)*log(Rtherm/10000.0));

    return tempKelvin - 273;
}