// answer may not match exactly

// set global vars
const float R1 = 20000.0;   // known resistance to get R2 / therm resistance
float tempCelcius = 0;      // global var to store tempCelcius

const int pin_in = 13;      // pin has an ADC
const int pin_out = 12;     // digital output

void setup(){
    Serial.begin(9600);
    // don't actually need to set pinMode(pin_in, INPUT) because that is default
    pinMode(pin_out, OUTPUT);
}

void loop(){
    tempCelcius = getTemperature(analogRead(pin_in));
    Serial.println("TEMP(C): "+String(tempCelcius));

    lightIfOver(tempCelcius);
}

// function to convert voltage to temp
float getTemperature(int Vout_adc){
    float Vout = Vout_adc*(5.0/1024.0);
    float Rtherm = (Vout*R1)/(5.0-Vout);
    float tempKelvin = 1.0/((1.0/298.0)+(1.0/3950.0)*log(Rtherm/10000.0));

    return tempKelvin - 273;
}

// additional function to light LED if high enough
void lightIfOver(float tempCelcius){
    if(tempCelcius > 26.0){
        digitalWrite(pin_out, HIGH);
    }
    else{
        digitalWrite(pin_out, LOW);
    }
}