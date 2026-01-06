import processing.serial.*;
Serial myPort;  // Create object from Serial class
float x;
float y;

void setup() {
    size(1000,1000);

    myPort = new Serial(this, "COM0", 9600);    // Open whatever port is the one you're using (Shown in Arduino IDE).
    myPort.bufferUntil('\n');
 }

void draw() {
    background(0);
    fill(255);
    rect(x,y,50,50); // rectangle with variable height
} 

void serialEvent(Serial port) {
  String inputString = port.readStringUntil('\n');
//  println(inputString);
  String receiveddata[]= split(inputString,' ');
  x = float(receiveddata[0]);
  y = float(receiveddata[1]);
  z = float(receiveddata[2]);
  x = map(x,-2,2,0,950);
  y = map(y,-2,2,0,950);
}
