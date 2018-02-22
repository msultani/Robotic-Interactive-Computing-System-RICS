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

const int START_X = 93;
const int START_Y = 40;
const int START_Z = 0;
const int START_CLAW = 0;
const int MOVE_DELAY = 150;

//servo positions values, expects 1-180 deg.
int xPos = START_X;
int yPos = START_Y;
int zPos = START_Z;
int clawPos = START_CLAW;


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

void configureServoPins() {
  xServo.attach(11);
  yServo.attach(10);
  zServo.attach(9);
  clawServo.attach(6);
}

void resetArmToInitialPosition() {
  xServo.write(START_X);
  yServo.write(START_Y);
  zServo.write(START_Z);
  clawServo.write(START_CLAW);

  xPos = START_X;
  yPos = START_Y;
  zPos = START_Z;
  clawPos = START_CLAW;
}

void moveServo(Servo servo, int startPt, int endPt) {
    if (endPt < startPt) {
      Serial.print("moveServo(): High to low");

      for (; startPt > endPt; --startPt) {
        servo.write(startPt);
        Serial.print(startPt);
        Serial.print('\n');
        delay(MOVE_DELAY);
      }
    } else {
      Serial.print("moveServo(): Low to high");

      for (; startPt < endPt; ++startPt) {
        servo.write(startPt);
        Serial.print(startPt);
        Serial.print('\n');
        delay(MOVE_DELAY);
      }
    }
    
}

bool commandHasErrors(String command) {
  for (int i = 1; i < len; ++i) {
    if (!Digit(command[i]) {
      return false;
    }
  }
  return true;
}

// Proper command format:
// * Leading number is 1-8 corresponding to Commands enum
// * All commands besides RETRIEVE and STOP should have 
//   a 1-3 digit number associated with them (1-180)
String parseCommand() {
  String command = "";
  while (Serial.available() > 0) {
    // Take in leading command character
    char input = Serial.read();
    Serial.print("Read in: ");
    Serial.print(input);
    Serial.print('\n');

    if (input == 'X') {
      break;
    } else {
      command += input;
    }
    
    // Maximum command size: 4 characters (Command number + 3 digits of an angle)
    if (command.length() > 4) {
      return "";
    }
  }
  Serial.print("Complete Command: ");
  Serial.print(command);
  Serial.print('\n');

  if (commandHasErrors(command)) {
    return "";
  } else {
    return command;
  }
}

void executeCommand(String command) {
  // Will grab the non-command digits of the command and convert to int
  int angle = toInt(command.substring(1));

  switch(command[0]){
    case UP:
    case DOWN:
      moveServo(yServo, yPos, angle);
      yPos = angle;
      break;
    case LEFT:
    case RIGHT:
      moveServo(xServo, xPos, angle);
      xPos = angle;
      break;
    case FORWARD:
    case BACKWARD:
      moveServo(zServo, zPos, angle);
      zPos = angle;
      break;
    case RETRIEVE:
      resetArmToInitialPosition();
      break;
    case STOP:
      // TODO: Figure out if we are still trying to implement this command.
      //Serial.print("Attempted to stop while not moving. ");
      break;
    default:
      Serial.print("Unidentified command character. ");
  }

}

//*************** ARDUINO MAIN FUNCTIONS ***************//

void setup() {
  configureServoPins();
  sensor.configureSensor();
  resetArmToInitialPosition();

  Serial.begin(9600);
  Serial.print("*** MeCom Test V04 ***  ");
}

void loop() {
  String command = parseCommand();
  executeCommand(command);
}