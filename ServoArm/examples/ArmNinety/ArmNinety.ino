/* ArmNinety
 by David <www.davidgamero.com>
 This example code is in the public domain.

 modified 6 Sep 2018
 by David Gamero
*/

#include <ServoArm.h>

ServoArm Arm

void setup() {
  Serial.begin(9600);

  int pin1 = 3;           // PWM supported pin to interface with Joint servo
  int pos1 = 90;          // Initial position to write to the joint
  int softStopMin = 10;   // Minimum safe position to write to the joint servo
  int softStopMax = 175;  // Maximum safe position to write to the joint servo
  
  Joint joint1(pin1, pos1, softStopMin, softStopMax); // Instantiate a new joint

  Arm.addJoint(joint1);   // Add joint to the arm at index 0
}

void loop() {
  int jointIndex = 0;     // Target Joint index
  int newJointPos = 110;  // Target Joint position
  
  Arm.setJointPos(jointIndex, newJointPos); //Write to joint in the arm
  
}
