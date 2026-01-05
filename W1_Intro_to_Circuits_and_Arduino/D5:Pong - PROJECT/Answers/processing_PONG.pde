
import processing.serial.*;

int PADDLEWIDTH = 20;
int leftpaddlesize = 100;
int rightpaddlesize = 100;
int ballsize = 20;
float left_y= 0;
float right_y = 0;
int shouldIstart = 0;
int ballx = 0; 
int bally = 0;
int button;
int x_vel = 2;
int y_vel = 2;
Serial myPort;  // Create object from Serial class


void setup() {
  size(600,600);

  ballx = width/2;
  bally = height/2;
 
  myPort = new Serial(this, "COM21", 9600);    // Open whatever port is the one you're using (Shown in Arduino IDE).

  myPort.bufferUntil('\n');
 }

  

void draw() {
  background(0);
//  println(left_y + " " + right_y);

if (shouldIstart == 0) {
  if (button == 0) shouldIstart = 1;
}
else {
  
  if (ballx <= PADDLEWIDTH+5) { // left goal scored or left paddle reflected
    if ((bally-ballsize <= left_y) || (bally >= left_y + leftpaddlesize)) {  //got by the paddle
       rightgoalscored();
    }
    else x_vel = -1*x_vel;
  }
  if (ballx+ballsize >= width - (PADDLEWIDTH+5)) { // goal scored or right paddle reflected
    if ((bally-ballsize <= right_y) || (bally >= right_y + leftpaddlesize)) {  //got by the paddle
       leftgoalscored();
    }
    else x_vel = -1*x_vel;
  }

  if ((bally <= 0) || (bally + ballsize >= height)) { // hit the top or the bottom 
    y_vel = -1*y_vel;
  }
    // update ball position
  ballx = ballx+x_vel;
  bally = bally+y_vel;
  
  rect(ballx,bally,ballsize,ballsize);
  rect(0,left_y,PADDLEWIDTH,leftpaddlesize);
  rect(width-PADDLEWIDTH,right_y,PADDLEWIDTH,rightpaddlesize);
  

} // end else
delay(10);
}
void rightgoalscored() {
}
void leftgoalscored() {
}

void serialEvent(Serial port) {
  String inputString = port.readStringUntil('\n');
//  println(inputString);
  String receiveddata[]= split(inputString,' ');
  left_y = float(receiveddata[0]);
  right_y = float(receiveddata[1]);
  button = int(receiveddata[2]);
  left_y = map(left_y,0,1023,0,height-leftpaddlesize);
  right_y = map(right_y,0,1023,0,height-rightpaddlesize);
//  println("New Data: ",left_y,right_y,button);
}
