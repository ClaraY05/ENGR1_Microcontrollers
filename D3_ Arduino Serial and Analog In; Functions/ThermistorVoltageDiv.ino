/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  ForLoops.ino // slide 45

  Make a voltage divider with R1 = 10k and R2 = Rtherm and write a program to read Vout and print it to the serial monitor
With the formulas you used previously, use Vout to find Rth, and use Rth to find the temperature in Celsius. 
Print it to Serial.
Look at the numbers on the Serial Monitor as well as the Serial Plotter.


*/

const float R1 = 20000.0;
float tempCelcius = 0;

const int pin_in = 13;

void setup(){
    Serial.begin(9600);
}

void loop(){
    tempCelcius = getTemperature(digitalRead(pin_in));
    

    Serial.println("TEMP(C): "+String(tempCelcius));
}

float getTemperature(int Vout_adc){
    float Vout = Vout_adc*(5.0/1024.0);
    float Rtherm = (Vout*R1)/(5.0-Vout);
    float tempKelvin = 1.0/((1.0/298.0)+(1.0/3950.0)*log(Rtherm/10000.0));

    return tempKelvin - 273;
}