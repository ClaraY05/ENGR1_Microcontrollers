#include <SPI.h>

#define CHIPSELECT 10

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(CHIPSELECT, OUTPUT);
SPI.begin();
  digitalWrite(CHIPSELECT,LOW);
  SPI.transfer(0b00100000);  //CTRL_REG1
  SPI.transfer(0b01110111);  //400Hz XYZ axes enabled
  digitalWrite(CHIPSELECT,HIGH);

  digitalWrite(CHIPSELECT,LOW);
  SPI.transfer(0b00100011);  //CTRL_REG4
  SPI.transfer(0b10001000);  //Block Data Update, +/-2g, High Res
  digitalWrite(CHIPSELECT,HIGH);

}

void loop() {
  float accelData[3];

  getAllAccel(accelData);
  
  Serial.print(accelData[0]);
  Serial.print(" ");
  Serial.print(accelData[1]);
  Serial.print(" ");
  Serial.print(accelData[2]);
  Serial.print(" ");
  Serial.println(sqrt(accelData[0]*accelData[0]+accelData[1]*accelData[1]+accelData[2]*accelData[2]));
  delay(100);
}

void getAllAccel(float *addressPointer) {
    digitalWrite(CHIPSELECT,LOW);
  SPI.transfer(0b11101000);
  
  byte xAccelByte1 = SPI.transfer(0b00000000);
  byte xAccelByte2 = SPI.transfer(0b00000000);
  byte yAccelByte1 = SPI.transfer(0b00000000);
  byte yAccelByte2 = SPI.transfer(0b00000000);
  byte zAccelByte1 = SPI.transfer(0b00000000);
  byte zAccelByte2 = SPI.transfer(0b00000000);
  digitalWrite(CHIPSELECT,HIGH);

  int16_t twoByteXAccel = xAccelByte1 + (xAccelByte2 << 8);
  *addressPointer = twoByteXAccel*2.0/32768.0; 
  addressPointer++;
  int16_t twoByteYAccel = yAccelByte1 + (yAccelByte2 << 8); 
  *addressPointer = twoByteYAccel*2.0/32768.0; 
  addressPointer++;
  int16_t twoByteZAccel = zAccelByte1 + (zAccelByte2 << 8); 
  *addressPointer = twoByteZAccel*2.0/32768.0; 
}
