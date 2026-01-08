#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// global values for OLED
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// constants for SPI w/ Accelerometer
int MOSIpin = 3; 
int CLKpin = 2; 
int CSpin = 1; 
int MISOpin = 0; 

SPISettings spisettings(1000000, MSBFIRST, SPI_MODE0);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    pinMode(CSpin, OUTPUT);
    SPI.setRX(MISOpin);
    SPI.setTX(MOSIpin);
    SPI.setSCK(CLKpin);
    SPI.begin();

    Wire.setSDA(16);
    Wire.setSCL(17);
    Wire.begin();

    digitalWrite(CSpin,LOW);
    SPI.transfer(0b00100000);  //CTRL_REG1
    SPI.transfer(0b01110111);  //400Hz XYZ axes enabled
    digitalWrite(CSpin,HIGH);

    digitalWrite(CSpin,LOW);
    SPI.transfer(0b00100011);  //CTRL_REG4
    SPI.transfer(0b10001000);  //Block Data Update, +/-2g, High Res
    digitalWrite(CSpin,HIGH);

    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
        while (1);
    }
    display.clearDisplay();
    display.display();
}

void loop() {
    float accelData[3];

    getAllAccel(accelData);

    displayData(accelData[0], accelData[1], accelData[2]);
    delay(100);
}

void getAllAccel(float *addressPointer) {
    digitalWrite(CSpin,LOW);
    SPI.transfer(0b11101000);

    byte xAccelByte1 = SPI.transfer(0b00000000);
    byte xAccelByte2 = SPI.transfer(0b00000000);
    byte yAccelByte1 = SPI.transfer(0b00000000);
    byte yAccelByte2 = SPI.transfer(0b00000000);
    byte zAccelByte1 = SPI.transfer(0b00000000);
    byte zAccelByte2 = SPI.transfer(0b00000000);
    digitalWrite(CSpin,HIGH);

    int16_t twoByteXAccel = xAccelByte1 + (xAccelByte2 << 8);
    *addressPointer = twoByteXAccel*2.0/32768.0; 
    addressPointer++;
    int16_t twoByteYAccel = yAccelByte1 + (yAccelByte2 << 8); 
    *addressPointer = twoByteYAccel*2.0/32768.0; 
    addressPointer++;
    int16_t twoByteZAccel = zAccelByte1 + (zAccelByte2 << 8); 
    *addressPointer = twoByteZAccel*2.0/32768.0; 
}

void displayData(float x, float y, float z){
    display.clearDisplay();

    display.setTextSize(1);      // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text

    display.setCursor(0, 0);     // Start at top-left corner
    display.print(F("X: "));
    display.println(x,2);
    display.print(F("Y: "));
    display.println(y,2);
    display.print(F("Z: "));
    display.println(z,2);
    display.display();
}