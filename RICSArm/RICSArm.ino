// MeArmMeCon-A04.ino
//Use With MeCon.exe Ver0.4 Windows Software for MeArm Motion Control
#include <Servo.h>

/* UltrasonicSensor will be installed to detect distance to objects
 * in front of the claw.
  */
struct UltrasonicSensor {
  int trigPin = 7;
  int echoPin = 8;
  int distance;

  void configureSensor();
  void checkSensorDistance();
};

//MeArm HAS 4 SERVOS
UltrasonicSensor sensor;
Servo xServo;  // create servo object, arm base servo - left right motion
Servo yServo;  // create servo object, left side servo - forward backwards motion
Servo zServo;  // create servo object, right side servo - forward backwards motion
Servo clawServo;  // create servo object, end of arm srevo - open,close the claw hand

//servo positions values, expects 1-180 deg.
int xPos;
int yPos;
int zPos;
int clawPos;
bool moving = false;

//*************** INIT AT STARTUP *******************************************************************

void configureServoPins() {
  // assign servo to pin numbers
  xServo.attach(11);  // attaches the servo on pin 11 to the servo object
  yServo.attach(10);  // attaches the servo on pin 10 to the servo object
  zServo.attach(9);  // attaches the servo on pin 9 to the servo object
  clawServo.attach(6);  // attaches the servo on pin 6 to the servo object
}

void UltrasonicSensor::configureSensor() {
  pinMode(sensor.trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(sensor.echoPin, INPUT); // Sets the echoPin as an Input
}

void UltrasonicSensor::checkSensorDistance() {
  // Clears the trigPin
  digitalWrite(sensor.trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(sensor.trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor.trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  int duration = pulseIn(sensor.echoPin, HIGH);
  
  // Calculating the distance
  sensor.distance = duration*0.034/2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);  
}

// the setup function runs once when you press reset or power the board
void setup() {
  //configureServoPins();
  //sensor.configureSensor();
  clawServo.attach(6);
  Serial.begin(9600); // initialize serial port
  // Debug only send serial message to host com port terminal window in Arduino IDE
  Serial.print("*** MeCom Test V04 ***.");   // send program name, uncomment for debug connection test
}

void loop() {

    clawServo.write(0);
    delay(10000);
//  int startPt = 0;
//  int endPt = 160;
//  int moveDelay = 5000;
//  
//  clawServo.write(startPt);
//  delay(moveDelay);
//  clawServo.write(endPt);
//  delay(moveDelay);
//  clawServo.write(startPt);
//  delay(moveDelay);
//  clawServo.write(endPt);
//  delay(moveDelay);
//  clawServo.write(startPt);
//  delay(moveDelay);
//  clawServo.write(endPt);
//  delay(moveDelay);
    
    
//  for (int i = 0; i < 180; ++i) {
//    clawServo.write(i);
//    delay(100);
//  }
  
  /*
  //serial in packet patern = xVal,yVal,zVal,clawVal + end of packet char 'x'
  while (Serial.available() > 0) {
    checkSensorDistance();
    
    if (isDigit(Serial.read)) {
      
    }

    // Move the arm
    xPos = Serial.parseInt();
    yPos = Serial.parseInt();
    zPos = Serial.parseInt();
    clawPos = Serial.parseInt();
    if (Serial.read() == 'x') { // Detect end of packet char 'x', go ahead and update servo positions
      // UPDATE SERVO POSITIONS
      xServo.write(xPos);
      yServo.write(yPos);
      zServo.write(zPos);
      clawServo.write(clawPos);
    }
  }
  */
}
