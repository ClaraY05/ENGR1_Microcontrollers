// example may not match answer exactly
Serial myPort;
int WIDTH = 1000;

void setup(){
    size(1000,1000); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input

    // set stroke and initial background
    strokeWeight(10);
    stroke(255, 0, 0);
    background(255);
}

float y;
float [] data = new float[WIDTH];   // make array to store value

void draw(){
    // draw every single point in data each time loop runs
    background(255);
    data[WIDTH - 1] = y;
    for(int i = 0; i < WIDTH-1; i++){
        point(i,data[i]);
        data[i] = data[i+1];
    }
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    y = float(inputString);
    y = map(temp, 0, 1023, 0, 1000); // scales values from 0-1023 to 0-1000 aka screen height
    println("ypos: ", y); // prints to console
}