/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  History.pde

  Code changes plots points of analog read at a time based on output of arduino analog read
*/

import processing.serial.*;

Serial myPort;
float h;

void setup(){
    size(400,400); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input
}

void draw(){
    background(255);// sets bg
    fill(0); // make shapes the color 0
    rect(0,h, 10, 50); //makes rectangle with upper left at (0,h)

}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    float temp = float(inputString);
    h = map(temp, 0, 1023, 0, 255); // scales values from 0-1023 to 0-255
    println("height: ", brightness); // prints to console
}