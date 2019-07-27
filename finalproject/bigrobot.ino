#include "MeMegaPi.h"
#include "SoftwareSerial.h"

// Serials
MeInfraredReceiver infraredReceiverDecode(PORT_8);
MeMegaPiDCMotor armMotor(PORT1B);
MeMegaPiDCMotor leftMotor(PORT2B);
MeMegaPiDCMotor rightMotor(PORT3B);
MeMegaPiDCMotor clawMotor(PORT4B);

MeUltrasonicSensor ultra(PORT_7);

MeGyro gyro(PORT_6);

// Motor Multipliers
int leftMotorMultiplier = 1;
int rightMotorMultiplier = -1;
float motorSpeed = 200;
float standardDelay = 600;

float walldistance = 20.00;

float distance = 0.00;

void stopMotors() {
  rightMotor.run(0);
  leftMotor.run(0);
  clawMotor.run(0);
  armMotor.run(0);
}

void forwards() {
  rightMotor.run(motorSpeed * rightMotorMultiplier);
  leftMotor.run(motorSpeed * leftMotorMultiplier);
  delay(standardDelay);
  stopMotors();
}

void backwards() {
  rightMotor.run(-1 * motorSpeed * rightMotorMultiplier);
  leftMotor.run(-1 * motorSpeed * leftMotorMultiplier);
  delay(standardDelay);
  stopMotors();
}

void clawup() {
  armMotor.run(-1 * 200 * rightMotorMultiplier);
  delay(2000);
  stopMotors();
}

void clawdown() {
  armMotor.run(1 * 200 * rightMotorMultiplier);
  delay(2000);
  stopMotors();
}

void clawOpen() {
  clawMotor.run(-200);
  delay(1600);
  stopMotors();
}

void clawClose() {
  clawMotor.run(200);
  delay(1600);
  stopMotors();
}

void turn90Right() {
  /*rightMotor.run(-1 * 200 * rightMotorMultiplier);
  leftMotor.run(1 * 200 * leftMotorMultiplier);
  delay(1625);
  stopMotors();*/
  stopMotors();
  gyro.begin();
 
  bool moving = true;
  while (moving) {
    gyro.update();
    float current = gyro.getAngleZ();
    Serial.println(current);
    if (current >= -90.25 && current <= -89.75) {
      stopMotors();
      moving = false;
    } else {
      rightMotor.run(-1 * 200 * rightMotorMultiplier);
      leftMotor.run(1 * 200 * leftMotorMultiplier);
    }
  }
}

void turn90Left() {
  /*rightMotor.run(-1 * 200 * rightMotorMultiplier);
  leftMotor.run(1 * 200 * leftMotorMultiplier);
  delay(1625);
  stopMotors();
  stopMotors();
  gyro.begin();*/
 
  bool moving = true;
  while (moving) {
    gyro.update();
    float current = gyro.getAngleZ();
    if (current >= 89.75 && current <= 90.25) {
      rightMotor.run(1 * 200 * rightMotorMultiplier);
      leftMotor.run(-1 * 200 * leftMotorMultiplier);
    } else {
      stopMotors();
      moving = false;
    }
  }
}

void turn180() {
  /*rightMotor.run(-1 * 200 * rightMotorMultiplier);
  leftMotor.run(1 * 200 * leftMotorMultiplier);
  delay(3250);
  stopMotors();*/
  stopMotors();
  gyro.begin();
 
  bool moving = true;
  while (moving) {
    gyro.update();
    float current = gyro.getAngleZ();
    Serial.println(current);
    if (current <= 179.75 && current >= -179.75) {
      rightMotor.run(-1 * 200 * rightMotorMultiplier);
      leftMotor.run(1 * 200 * leftMotorMultiplier);
    } else {
      stopMotors();
      moving = false;
    }
  }
}

void forwardToStop() {
  bool object = false;
  rightMotor.run(motorSpeed * rightMotorMultiplier);
  leftMotor.run(motorSpeed * leftMotorMultiplier);
  while (object == false) {
    float distance = ultra.distanceCm();
    if (distance <= walldistance) {
      object = true;
      stopMotors();
    }
    if (distance > 399) { findDropZone(); }
  }
}

float forwardsf = 0;
float left = 0;
float right = 0;


void checkSurroundings() {
  bool looping = true;
  while (looping) {
  distance = ultra.distanceCm();
  forwardsf = distance;
  
  turn90Right();
  
  distance = ultra.distanceCm();
  right = distance;
  
  turn180();
  
  distance = ultra.distanceCm();
  left = distance;
  
  
  if (left >= forwardsf && left >= right) {
    forwardToStop();
    looping = false;
  } else if (right > forwardsf && right > left) {
    turn180();
    forwardToStop();
    looping = false;
  } else if (forwardsf > left && forwardsf > right) {
    turn90Right();
    forwardToStop();
    looping = false;
  } else {
    continue;
  }
  }
  
}

void findDropZone() {
  bool passedZone = false;

  while (!passedZone)
  {
    bool noRightWall = false;
    bool noLeftWall = false;
    rightMotor.run(200);
    leftMotor.run(200);
    delay(3000);
    rightMotor.stop();
    leftMotor.stop();
    turn90Right();
    distance = ultra.distanceCm();
    if (distance > 100) { noRightWall = true; }
    turn180();
    distance = ultra.distanceCm();
    if (distance > 100) { noLeftWall = true; }
    turn90Right();
    if (noRightWall == true && noLeftWall == true)
    {
      rightMotor.run(-200);
      leftMotor.run(-200);
      delay(3000);
      rightMotor.stop();
      leftMotor.stop();
      dropItem();
      
    }
  }
}

void dropItem()
{
  clawdown();
  clawOpen();
  delay(123456789);
}

void setup() {
  // put your setup code here, to run once:
  gyro.begin();
  Serial.begin(9600);
}

bool waitingForCarrier = true;

void loop() {
  // put your main code here, to run repeatedly:
  float distance = ultra.distanceCm();
  
  if (waitingForCarrier == true) {
    if (distance <= 7.50) {
      delay(1000);
      // it moves
      clawOpen();
      clawdown();
      /*rightMotor.run(200 * rightMotorMultiplier);
      leftMotor.run(200 * leftMotorMultiplier);
      delay(300);
      stopMotors();*/
      clawClose();
      clawup();
      // backs up to avoid scraping other bot
      rightMotor.run(-1 * 100 * rightMotorMultiplier);
      leftMotor.run(-1 * 100 * leftMotorMultiplier);
      delay(250);
      stopMotors();
      // 3250 for 180 turn
      // 180 degree turn
      waitingForCarrier = false;
      turn180();
      bool object = false;
      delay(500);
      rightMotor.run(motorSpeed * rightMotorMultiplier);
      leftMotor.run(motorSpeed * leftMotorMultiplier);
      while (object == false) {
        float distance = ultra.distanceCm();
        if (distance <= walldistance) {
          object = true;
          stopMotors();
        }
      }
    } else {
      delay(50);
    }
  } 
  else if (waitingForCarrier == false) {
    distance = ultra.distanceCm();
    if (distance < 400) {
      checkSurroundings();
     }
    else {
      findDropZone();
    }
    delay(50); 
  }
}
