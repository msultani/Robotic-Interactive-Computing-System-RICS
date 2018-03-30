// MeArmMeCon-A04.ino
//Use With MeCon.exe Ver0.4 Windows Software for MeArm Motion Control
#include <Arduino.h>
#include <Servo.h>
#include "MeArm.h"

enum Commands { X, Y, Z, CLAW, RETRIEVE, STOP, MOVE_DELAY };

void UltrasonicSensor::configureUltrasonicSensor() {
  pinMode(sensor.trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(sensor.echoPin, INPUT); // Sets the echoPin as an Input
}

void UltrasonicSensor::checkUltrasonicSensorDistance() {
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

void MeArm::configureServoPins() {
  xServo.attach(11);
  yServo.attach(10);
  zServo.attach(9);
  clawServo.attach(6);
}

void MeArm::resetArmToInitialPosition() {
  xServo.write(MeArm::START_X);
  yServo.write(MeArm::START_Y);
  zServo.write(MeArm::START_Z);
  clawServo.write(MeArm::START_CLAW);
}

void MeArm::moveServo(Servo servo, int startPt, int endPt) {
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
        delay(moveDelay);
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
        delay(moveDelay);
      }
    }
    
}

bool MeArm::commandHasErrors(String command) {
  for (int i = 1; i < command.length(); ++i) {
    if (!isDigit(command[i])) {
      Serial.print("commandHasErrors() found an error");
      return true;
    }
  }
  return false;
}

// Proper command format:
// * Leading number corresponds to Commands enum
// * All commands besides RETRIEVE and STOP should have 
//   a 1-3 digit number associated with them (1-180)
String MeArm::parseCommand() {
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

void MeArm::executeCommand(String command) {
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
    case CLAW:
      Serial.print("executeCommand() CLAW");
      moveServo(clawServo, clawPos, angle);
      clawPos = angle;
      break;
    case RETRIEVE:
      resetArmToInitialPosition();
      break;
    case STOP:
      // TODO: Figure out if we are still trying to implement this command.
      //Serial.print("Attempted to stop while not moving. ");
      break;
    case MOVE_DELAY:
      arm.
    default:
      Serial.print("Unidentified command character. ");
  }

}

void MeArm::setMoveDelay(int delay) {
    moveDelay = delay;
}

//*************** ARDUINO MAIN FUNCTIONS ***************//

MeArm arm;

void setup() {
  arm.configureServoPins();
  arm.configureUltrasonicSensor();
  arm.resetArmToInitialPosition();

  Serial.begin(9600);
  Serial.print("*** MeCom Test V04 ***  ");
}

void loop() {
  String command = parseCommand();
  if (command.length() > 0) {
    executeCommand(command);
  }
}
