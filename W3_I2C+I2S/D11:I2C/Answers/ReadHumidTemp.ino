#include<Wire.h>

const int SDApin = 16;
const int SCLpin = 17;

void setup(){
    Wire.setSDA(SDApin);
    Wire.setSCL(SCLpin);

    Serial.begin(9600);
    Wire.begin();

    // load address and initialize AHT20
    Wire.beginTransmission(0x38);
    Wire.write(0xBE); 
    Wire.write(0x08); 
    Wire.write(0x00); 
    Wire.endTransmission(); 
    //or if (Wire.endTransmission()!=0) Serial.println(“I2C Write Error!”)
    delay(10);
}

void loop(){
    // Read values from register
    Wire.beginTransmission(0x38);
    Wire.write(0xAC); 
    Wire.write(0x33); 
    Wire.write(0x00); 
    Wire.endTransmission(); 
    delay(100);
    Wire.requestFrom(0x38,6);
    if (6<= Wire.available()) {
        byte byteone = Wire.read();
        byte bytetwo = Wire.read();  
        byte bytethree = Wire.read();
        byte bytefour = Wire.read();  
        byte bytefive = Wire.read();
        byte bytesix = Wire.read(); 

        // print out values
        Serial.print("TEMPERATURE(C): ");
        Serial.println(parseTemp(bytefour, bytefive, bytesix));

        Serial.print("HUMIDITY(%): ");
        Serial.println(parseHumidity(bytetwo, bytethree, bytefour));
    }
}

float parseTemp(byte b4, byte b5, byte b6){
    uint32_t tempInt = (b4 & 0b00001111) << 16;
    tempInt = tempInt + (b5 << 8);
    tempInt = tempInt + (b6);

    // convert
    float relTemp = tempInt/1048576.0*100.0 - 50.0;
    return relTemp;
}

float parseHumidity(byte b2, byte b3, byte b4){
    uint32_t humidityInt = b2 << 16;
    humidityInt = humidityInt + (b3 << 8);
    humidityInt = humidityInt + (b4 & 0b11110000) //filter bottom 4
    
    // convert
    float relHumidity = humidityInt/1048576.0*100.0;
    return relHumidity;
}