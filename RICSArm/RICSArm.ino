// MeArmMeCon-A04.ino
//Use With MeCon.exe Ver0.4 Windows Software for MeArm Motion Control
#include <Servo.h>

enum Commands { X, Y, Z, RETRIEVE, STOP };

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
      Serial.print(startPt);
      Serial.print(" to ");
      Serial.print(endPt);
      Serial.print('\n');

      for (; startPt > endPt; --startPt) {
        servo.write(startPt);
        Serial.print(startPt);
        Serial.print('\n');
        delay(MOVE_DELAY);
      }
    } else {
      Serial.print("moveServo(): Low to high ");
      Serial.print(startPt);
      Serial.print(" to ");
      Serial.print(endPt);
      Serial.print('\n');
      
      

      for (; startPt < endPt; ++startPt) {
        servo.write(startPt);
        Serial.print(startPt);
        Serial.print('\n');
        delay(MOVE_DELAY);
      }
    }
    
}

bool commandHasErrors(String command) {
  for (int i = 1; i < command.length(); ++i) {
    if (!isDigit(command[i])) {
      Serial.print("commandHasErrors() found an error");
      return true;
    }
  }
  return false;
}

// Proper command format:
// * Leading number is 0-5 corresponding to Commands enum
// * All commands besides RETRIEVE and STOP should have 
//   a 1-3 digit number associated with them (1-180)
String parseCommand() {
  String command = "";
  while (1) {
    // Take in leading command character
    char input = Serial.read();
    if (input == 'X' || input == 'x') {
      break;
    } else if (isDigit(input)) {
      command += input;
    }
    
    // Maximum command size: 4 characters (Command number + 3 digits of an angle)
    if (command.length() > 4) {
      Serial.print("Command too long");
      return "";
    }
  }

  if (commandHasErrors(command)) {
    return "";
  } else {
    Serial.print("Complete Command: ");
    Serial.print(command);
    Serial.print('\n');
    return command;
  }
}

void executeCommand(String command) {
  // Will grab the non-command digits of the command and convert to int
  int commandType = command[0] - '0';
  int angle = command.substring(1).toInt();
  
  switch(commandType){
    case X:
      Serial.print("executeCommand() X");
      moveServo(xServo, xPos, angle);
      xPos = angle;
      break;
    case Y:
      Serial.print("executeCommand() Y");
      moveServo(yServo, yPos, angle);
      yPos = angle;
      break;
    case Z:
      Serial.print("executeCommand() Z");
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
  if (command.length() > 0) {
    executeCommand(command);
  }
}
