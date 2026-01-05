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
float y;      // make y position global var
void draw(){
    point(count, y) // draw point at count
    if(count > 1000) { // reset when screen is filled
        count = 0;       // reset count
        background(255); // clear background
    }
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    y = float(inputString);
    y = map(temp, 0, 1023, 0, 1000); // scales values from 0-1023 to 0-1000 aka screen height
    println("ypos: ", y); // prints to console
}