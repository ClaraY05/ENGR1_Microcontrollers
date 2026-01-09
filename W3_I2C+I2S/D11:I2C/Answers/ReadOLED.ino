#include<Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// connect both AHT20 and OLED to these lines
const int SDApin = 16;
const int SCLpin = 17;

// global values for OLED
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){
    Wire.setSDA(SDApin);
    Wire.setSCL(SCLpin);

    Serial.begin(9600);
    Wire.begin();

    // refresh display
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
        while (1);
    }
    display.clearDisplay();
    display.display();

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
        float cTemp = parseTemp(bytefour, bytefive, bytesix);
        float cHum = parseHumidity(bytetwo, bytethree, bytefour);
        displayData(cTemp, cHum);
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

void displayData(float temp, float hum){
    display.clearDisplay();

    display.setTextSize(1);      // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text

    display.setCursor(0, 0);     // Start at top-left corner
    display.print(F("TEMPERATURE(C): "));
    display.println(temp,2);
    display.print(F("HUMIDITY(%): "));
    display.println(hum,2);
    display.display();
}