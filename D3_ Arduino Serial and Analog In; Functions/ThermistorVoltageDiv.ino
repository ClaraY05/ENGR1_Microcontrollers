/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  ThermistorVoltageDiv.ino // slide 45

  Make a voltage divider with R1 = 10k and R2 = Rtherm and write a program to read Vout and print it to the serial monitor
With the formulas you used previously, use Vout to find Rth, and use Rth to find the temperature in Celsius. 
Print it to Serial.
Look at the numbers on the Serial Monitor as well as the Serial Plotter.

Make a program that measures the temperature and lights an LED if the temperature exceeds 26C


*/

const float R1 = 20000.0;
float tempCelcius = 0;

const int pin_in = 13;
const int pin_out = 12;

void setup(){
    Serial.begin(9600);
    pinMode(pin_out, OUTPUT);
}

void loop(){
    tempCelcius = getTemperature(digitalRead(pin_in));
    Serial.println("TEMP(C): "+String(tempCelcius));

    lightIfOver(tempCelcius);
}

float getTemperature(int Vout_adc){
    float Vout = Vout_adc*(5.0/1024.0);
    float Rtherm = (Vout*R1)/(5.0-Vout);
    float tempKelvin = 1.0/((1.0/298.0)+(1.0/3950.0)*log(Rtherm/10000.0));

    return tempKelvin - 273;
}

void lightIfOver(float tempCelcius){
    if(tempCelcius > 26.0){
        digitalWrite(pin_out, HIGH);
    }
    else{
        digitalWrite(pin_out, LOW);
    }
}