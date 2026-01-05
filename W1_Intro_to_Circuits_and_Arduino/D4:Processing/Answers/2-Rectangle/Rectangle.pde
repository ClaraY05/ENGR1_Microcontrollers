// example may not match answer exactly

import processing.serial.*;

Serial myPort;
float brightness;

void setup(){
    size(200,200); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input
}

void draw(){
    background(255); // fill entire screen white
    fill(0); // make drawn items black
    rect(0,h,10,50); // rectangle with variable height
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    float temp = float(inputString);
    h = map(temp, 0, 1023, 0, 255); // scales values from 0-1023 to 0-255
    println("height: ", h); // prints to console
}