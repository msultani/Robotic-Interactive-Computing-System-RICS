// MeArmMeCon-A04.ino
//Use With MeCon.exe Ver0.4 Windows Software for MeArm Motion Control
#include <Servo.h>

enum class Commands : char {
  UP = 'U', 
  DOWN = 'D', 
  LEFT = 'L', 
  RIGHT = 'R', 
  FORWARD = 'F', 
  BACKWARD = 'B', 
  RETRIEVE = 'E',  // TODO: Confusing naming, rename later
  STOP = 'S' 
};

/* UltrasonicSensor will be installed to detect distance to objects
 * in front of the claw. TODO: Separate this into another file? not sure if arduinos allow that
  */
struct UltrasonicSensor {
  int trigPin = 5;
  int echoPin = 3;
  int distance;

  void configureSensor();
  void checkSensorDistance();
};

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

//MeArm HAS 4 SERVOS
UltrasonicSensor sensor;
Servo xServo;  // create servo object, arm base servo - left right motion
Servo yServo;  // create servo object, left side servo - forward backwards motion
Servo zServo;  // create servo object, right side servo - forward backwards motion
Servo clawServo;  // create servo object, end of arm srevo - open,close the claw hand

/* 
 *  Servo Ranges:
 *  xServo: 0-180
 *  yServo: 0-35
 *  zServo: 0-60
 */

const int START_X = 90;
const int START_Y = 45;
const int START_Z = 60;
const int START_CLAW = 0;

//servo positions values, expects 1-180 deg.
int xPos = START_X;
int yPos = START_Y;
int zPos = START_Z;
int clawPos = START_CLAW;

void configureServoPins() {
  // assign servo to pin numbers
  xServo.attach(11);  // attaches the servo on pin 11 to the servo object
  yServo.attach(10);  // attaches the servo on pin 10 to the servo object
  zServo.attach(9);  // attaches the servo on pin 9 to the servo object
  clawServo.attach(6);  // attaches the servo on pin 6 to the servo object
}

void moveServo(Servo servo, int startPt, int endPt, int moveDelay) {
    for (; startPt < endPt; ++startPt) {
      servo.write(startPt);
      Serial.print(startPt);
      Serial.print('\n');
      delay(moveDelay);
    }
}

void resetArmToInitialPosition() {
  xServo.write(START_X);
  yServo.write(START_Y);
  zServo.write(START_Z);
  clawServo.write(START_CLAW);
}

//*************** ARDUINO MAIN FUNCTIONS ***************//

void setup() {
  configureServoPins();
  sensor.configureSensor();
  resetArmToInitialPosition();

  Serial.begin(9600);
  Serial.print("*** MeCom Test V04 ***  ");
}

void moveServo(Servo servo, int angle, )

void loop() {
  while (Serial.available() > 0) {
    // Take in leading command character
    int input = Serial.read();
    Serial.print("Read in: ");
    Serial.print(input);
    serial.print('\n');
    
    switch(input){
      case UP:
        break;
      case DOWN:
        break;
      case LEFT:
        break;
      case RIGHT:
        break;
      case FORWARD:
        break;
      case BACKWARD:
        break;
      case RETRIEVE:
        break;
      case STOP:
        Serial.print("Attempted to stop while not moving. ");
        break;
      default:
        Serial.print("Unidentified command character. ");
    }
    delay(500);
  }
}
