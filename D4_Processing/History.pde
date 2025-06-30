/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  History.pde

  Code changes plots points of analog read at a time based on output of arduino analog read
  screen scrolls with plotting using an array to store values and shift values
*/

import processing.serial.*;

Serial myPort;

void setup(){
    size(1000,1000); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input

    // settings for point
    strokeWeight(10);
    stroke(255,0,0);
}

float[] data = new float[1000];
float y;
void draw(){
    background(255);
    data[1000-1] = y;
    for(int i = 0; i < 1000 - 1; i++){
        point(i, data[i]);
        data[i] = data[i+1];
    }
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    float temp = float(inputString);
    y = map(temp, 0, 1023, 0, 1000); // scales values from 0-1023 to 0-255
    println("ypos: ", y); // prints to console
}