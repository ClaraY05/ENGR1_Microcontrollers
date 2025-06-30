/*
  UCLA Engineering Design Summer Institute 2025 - Microcontrollers
  Clara Yee
  DrawTwoLines.pde

  Code changes plots points of two different analog reads at a time based on output of arduino analog read
  screen scrolls with plotting using an array to store values and shift values
  Uses a ring buffer.
*/

import processing.serial.*;

Serial myPort;

void setup(){
    size(1000,1000); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input
}

float[] data = new float[1000];
float[] data2 = new float[1000];
float y, y2;
void draw(){
    background(255);
    data[1000-1] = y;
    data2[1000-1] = y2;
    for(int i = 0; i < 1000 - 1; i++){
        // change stroke color
        stroke(0,0,255);
        point(i,data[i]);
        data[i] = data[i+1];
        
        // change stroke color
        stroke(255,0,0);
        point(i, data2[i]);
        data2[i] = data2[i+1];
    }
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    String getData[] = split(inputString, ' ');
    float temp = float(getData[0]);
    y = map(temp, 0, 1023, 0, 1000); // scales values from 0-1023 to 0-1000
    float temp = float(getData[1]);
    y2 = map(temp, 0, 1023, 0, 1000); // scales values from 0-1023 to 0-255
}