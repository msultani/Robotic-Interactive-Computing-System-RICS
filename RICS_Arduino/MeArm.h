#include <Arduino.h>

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
  static const int START_X = 93;
  static const int START_Y = 40;
  static const int START_Z = 0;
  static const int START_CLAW = 17;

  void configureServoPins();
  void moveServo();
  void commandHasErrors();
  void parseCommand();
  void executeCommand();
  void setMoveDelay(int delay);
  
  void configureUltrasonicSensor();

  private:
  UltrasonicSensor sensor;
  
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