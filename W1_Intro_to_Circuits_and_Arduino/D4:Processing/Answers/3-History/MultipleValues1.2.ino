// example may not match answer exactly
Serial myPort;
float brightness;

void setup(){
    size(1000,1000); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input

    // set stroke and initial background
    strokeWeight(10);
    stroke(255, 0, 0);
    background(255);
}

int count = 0; // track x position
float newdata;      // make y position global var
void draw(){
    if (count%1000 == 0) background(255); // reset once full
    point(count, newdata);
    count++; // count increases indefinitely
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    newdata = float(inputString);
    newdata = map(temp, 0, 1023, 0, 1000); // scales values from 0-1023 to 0-1000 aka screen height
    println("ypos: ", newdata); // prints to console
}