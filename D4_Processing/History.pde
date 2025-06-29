/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  History.pde

  Code changes plots points of analog read at a time based on output of arduino analog read
*/

import processing.serial.*;

Serial myPort;

void setup(){
    size(400,400); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input

    // settings for point
    strokeWeight(10);
    stroke(255,0,0);
    background(255);
}

int xpos = 0;
float y;
void draw(){
    point(xpos, y);
    if(xpos > 1000){
        xpos = 0;
        background(255);
    }
    xpos += 1;
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    float temp = float(inputString);
    y = map(temp, 0, 1023, 0, 255); // scales values from 0-1023 to 0-255
    println("ypos: ", y); // prints to console
}