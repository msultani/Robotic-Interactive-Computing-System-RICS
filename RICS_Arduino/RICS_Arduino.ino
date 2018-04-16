// MeArmMeCon-A04.ino
// Use With MeCon.exe Ver0.4 Windows Software for MeArm Motion Control
#include <Servo.h>

// #define DEBUG

#ifdef DEBUG
 #define DEBUG_PRINT(x)  Serial.println (x)
#else
 #define DEBUG_PRINT(x)
#endif

enum Commands { X, Y, Z, CLAW, DELAY };

/* UltrasonicSensor will be installed to detect distance to objects
 * in front of the claw. TODO: Separate this into another file? not sure if arduinos allow that
  */
class UltrasonicSensor {
  public:
  void configureSensor();
  void checkSensorDistance();

  private:
  int trigPin = 5;
  int echoPin = 3;
  int distance;
};

class MeArm {
  public:
  /* 
  *  Servo Ranges:
  *  xServo: 0-180
  *  yServo: 0-35
  *  zServo: 0-60
  *  clawServo: 17-140
  */
  const int START_X = 93;
  const int START_Y = 35;
  const int START_Z = 45;
  const int START_CLAW = 20;

  void configureServoPins();
  void moveServo(Servo, int, int);
  bool commandHasErrors(String);
  String parseCommand();
  void executeCommand(String);
  void resetArmToInitialPosition();
  void configureUltrasonicSensor();
  void setMoveDelay(int delay);
  int getMoveDelay();
  UltrasonicSensor sensor;

  private:
  
  Servo xServo;     // Left-right movement 
  Servo yServo;     // Up-down movement
  Servo zServo;     // Forward-backward movement
  Servo clawServo;  // Scoop rotation movement

  // Current servo angles
  int xPos = START_X;
  int yPos = START_Y;
  int zPos = START_Z;
  int clawPos = START_CLAW;

  int moveDelay = 150; 
};

MeArm meArm;

void UltrasonicSensor::configureSensor() {
  pinMode(meArm.sensor.trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(meArm.sensor.echoPin, INPUT); // Sets the echoPin as an Input
}

void UltrasonicSensor::checkSensorDistance() {
  // Clears the trigPin
  digitalWrite(meArm.sensor.trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(meArm.sensor.trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(meArm.sensor.trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  int duration = pulseIn(meArm.sensor.echoPin, HIGH);
  
  // Calculating the distance
  meArm.sensor.distance = duration*0.034/2;
}

void MeArm::configureServoPins() {
  xServo.attach(11);
  yServo.attach(10);
  zServo.attach(9);
  clawServo.attach(6);
}

void MeArm::resetArmToInitialPosition() {
  xServo.write(START_X);
  yServo.write(START_Y);
  zServo.write(START_Z);
  clawServo.write(START_CLAW);
}

void MeArm::moveServo(Servo servo, int startPt, int endPt) {
    if (endPt <= startPt) {
      DEBUG_PRINT("moveServo(): High to low");
      DEBUG_PRINT(startPt);
      DEBUG_PRINT(" to ");
      DEBUG_PRINT(endPt);
      DEBUG_PRINT('\n');

      for (; startPt >= endPt; --startPt) {
        servo.write(startPt);
        delay(moveDelay);
      }
    } else {
      DEBUG_PRINT("moveServo(): Low to high ");
      DEBUG_PRINT(startPt);
      DEBUG_PRINT(" to ");
      DEBUG_PRINT(endPt);
      DEBUG_PRINT('\n');
      
      for (; startPt <= endPt; ++startPt) {
        servo.write(startPt);
        delay(moveDelay);
      }
    }
    Serial.print("X");
}

bool MeArm::commandHasErrors(String command) {
  for (int i = 1; i < command.length(); ++i) {
    if (!isDigit(command[i])) {
      DEBUG_PRINT("commandHasErrors() found an error");
      return true;
    }
  }
  return false;
}

// Proper command format:
// * Leading number is 0-5 corresponding to Commands enum
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
      DEBUG_PRINT("Command too long");
      return "";
    }
  }

  if (commandHasErrors(command)) {
    return "";
  } else {
    DEBUG_PRINT("Complete Command: ");
    DEBUG_PRINT(command);
    DEBUG_PRINT('\n');
    return command;
  }
}

void MeArm::executeCommand(String command) {
  // Will grab the non-command digits of the command and convert to int
  int commandType = command[0] - '0';
  int angle = command.substring(1).toInt();
  
  switch(commandType){
    case X:
      DEBUG_PRINT("executeCommand() X");
      moveServo(xServo, xPos, angle);
      xPos = angle;
      break;
    case Y:
      DEBUG_PRINT("executeCommand() Y");
      moveServo(yServo, yPos, angle);
      yPos = angle;
      break;
    case Z:
      DEBUG_PRINT("executeCommand() Z");
      moveServo(zServo, zPos, angle);
      zPos = angle;
      break;
    case CLAW:
      DEBUG_PRINT("executeCommand() CLAW");
      moveServo(clawServo, clawPos, angle);
      clawPos = angle;
      break;
    case DELAY:
      DEBUG_PRINT("executeCommand(): Set move delay to ");
      DEBUG_PRINT(angle);
      DEBUG_PRINT("\n");
      moveDelay = angle;
    default:
      DEBUG_PRINT("Unidentified command character. ");
  }

}

//*************** ARDUINO MAIN FUNCTIONS ***************//

void setup() {
  meArm.resetArmToInitialPosition();
  meArm.configureServoPins();
  meArm.sensor.configureSensor();

  Serial.begin(9600);
  DEBUG_PRINT("*** MeCom Test V04 *** \n");
}

void loop() {
  String command = meArm.parseCommand();
  DEBUG_PRINT("Command entered: ");
  DEBUG_PRINT(command);
  if (command.length() > 0) {
    meArm.executeCommand(command);
  }
}
