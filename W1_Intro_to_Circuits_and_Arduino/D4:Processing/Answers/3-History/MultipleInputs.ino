// example may not match answer exactly
Serial myPort;
int HEIGHT = 1000;
int WIDTH = 1000;

void setup(){
    size(1000,1000); // sets window size
    myPort = new Serial(this, "COM0", 9600); // use your own port

    myPort.bufferUntil('\n'); // only start running after input
}

float newdata;
float newdata1;
float [] data = new float[WIDTH];
float [] data1 = new float[WIDTH];

void draw(){
    // draw every single point in data each time loop runs
    background(255);
    data[WIDTH-1] = int(newdata);
    data1[WIDTH-1] = int(newdata1);

    for(int i = 0; i < WIDTH - 1; i++){
        stroke(0,0,255); // set different colors for each input 
        point(i, data[i]);
        data[i] = data[i+1];

        stroke(255,0,0);
        point(i, data1[i]);
        data1[i] = data1[i+1];
    }
}

void serialEvent(Serial port){
    String inputString = port.readStringUntil('\n'); // reads every line separately
    println(inputString); // prints to console
    String receiveddata[] = split(inputString, ' ');
    newdata = float(receiveddata[0]);
    newdata1 = float(receiveddata[1]);
    newdata = map(newdata, 0, 1023, 0, HEIGHT); // scales values from 0-1023 to 0-1000 aka screen height
    newdata1 = map(newdata, 0, 1023, 0, HEIGHT); 
}