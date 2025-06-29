/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  Brightness.pde

  Code changes brightness based on output of arduino analog read
*/

import processing.serial.*;

Serial myPort;
float brightness;

void setup(){
    size(200,200); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input
}

void draw(){
    background(brightness);// changes brightness
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    float temp = float(inputString);
    brightness = map(temp, 0, 1023, 0, 255); // scales values from 0-1023 to 0-255
    println("Brightness: ", brightness); // prints to console
}