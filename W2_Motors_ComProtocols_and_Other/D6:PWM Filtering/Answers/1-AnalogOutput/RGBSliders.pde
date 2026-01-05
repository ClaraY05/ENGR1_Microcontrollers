
// Answers may differ from Example

import processing.serial.*;
import controlP5.*;

Serial myPort;
ControlP5 cp5;
int R = 255;
int G = 255;
int B = 255;

void setup(){
    size(400,400); // sets window size
    cp5 = new ControlP5(this);

    cp5.addSlider("R").setPosition(100,50).setRange(0,255);
    cp5.addSlider("G").setPosition(100,70).setRange(0,255);
    cp5.addSlider("B").setPosition(100,90).setRange(0,255);

    String portName = Serial.list()[0];
    myPort = new Serial(this, "/dev/cu.usbmodem11301", 9600); // use your own port
    myPort.bufferUntil('\n'); // only start running after input
    background(0);
}

void draw(){
    String sentData = nf(R) + ' '+ nf(G)+ ' '+nf(B)+'\n';
    println(sentData);
    myPort.write(sentData);
    delay(200);
}