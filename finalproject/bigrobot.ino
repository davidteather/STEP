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
  delay(1800);
  stopMotors();
}

void clawdown() {
  armMotor.run(1 * 200 * rightMotorMultiplier);
  delay(1800);
  stopMotors();
}

void clawOpen() {
  clawMotor.run(-200);
  delay(1400);
  stopMotors();
}

void clawClose() {
  clawMotor.run(200);
  delay(1400);
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
    if (current >= -93 && current <= -88) {
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
    Serial.println(current);
    if (current >= 88 && current <= 93) {
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
    if (current <= 178 && current >= -178) {
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
  }
}

float forwardsf = 0;
float left = 0;
float right = 0;


void checkSurroundings() {
  distance = ultra.distanceCm();
  forwardsf = distance;
  
  turn90Right();
  
  distance = ultra.distanceCm();
  right = distance;
  
  turn180();
  
  distance = ultra.distanceCm();
  left = distance;

  if (left > forwardsf && left > right) {
    forwardToStop();
  } else if (right > forwardsf && right > left) {
    turn180();
    forwardToStop();
  } else if (forwardsf > left && forwardsf > right) {
    turn90Right();
    forwardToStop();
  }
  
}

void setup() {
  // put your setup code here, to run once:
  gyro.begin();
  Serial.begin(9600);
}

bool waitingForCarrier = true;
int cycles = 0;

void loop() {
  // put your main code here, to run repeatedly:
  float distance = ultra.distanceCm();
  
  if (waitingForCarrier == true) {
    if (distance <= 7.50) {
      delay(1000);
      // it moves
      clawOpen();
      clawdown();
      rightMotor.run(200 * rightMotorMultiplier);
      leftMotor.run(200 * leftMotorMultiplier);
      delay(350);
      stopMotors();
      clawClose();
      clawup();
      // backs up to avoid scraping other bot
      rightMotor.run(-1 * 100 * rightMotorMultiplier);
      leftMotor.run(-1 * 100 * leftMotorMultiplier);
      delay(400);
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
  } else if (waitingForCarrier == false) {
    if (cycles <= 5) {
      checkSurroundings();
      cycles++;
    }
    delay(50);
    
  }
  

  

}
