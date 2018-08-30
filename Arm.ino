/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

const int MAX_JOINTS = 10;

// joint
struct joint
{
  int softStop_min;
  int softStop_max;
  int pos;
  int pin;
  Servo servo;
};

typedef struct joint Joint;

struct arm
{
  int numJoints;
  Joint joints[MAX_JOINTS];
};

typedef struct arm Arm;

Arm mainArm;

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  
  mainArm.joints[0].softStop_min = 20;
  mainArm.joints[0].softStop_max = 180;
  mainArm.joints[0].pos = 9;
  mainArm.joints[0].pin = 2;
  
  mainArm.joints[1].softStop_min = 20;
  mainArm.joints[1].softStop_max = 180;
  mainArm.joints[1].pos = 9;
  mainArm.joints[1].pin = 6;

  mainArm.joints[2].softStop_min = 20;
  mainArm.joints[2].softStop_max = 180;
  mainArm.joints[2].pos = 90;
  mainArm.joints[2].pin = 7;
  
  // count joints by finding first zero pin
  for(int i = 0; i < MAX_JOINTS; i++){
    
    if(mainArm.joints[i].pin == 0){
     
      mainArm.numJoints = i;
      break;
    
    } else {
    
      // for non-zero pinned joints, attach the Servo objects
      int jointServoPin = mainArm.joints[i].pin;
      mainArm.joints[i].servo.attach(jointServoPin);
      
    }
  }
}

void loop() {
    
    
    // update joint positions
    writePositions();
    delay(10);
}


void writePositions(){
  for(int i = 0; i < mainArm.numJoints; i++){
    int jointPos = mainArm.joints[i].pos;

    // Hardstop max and min limits
    jointPos = (jointPos <  mainArm.joints[i].softStop_min) ?  mainArm.joints[i].softStop_min : jointPos;
    jointPos = (jointPos >  mainArm.joints[i].softStop_max) ?  mainArm.joints[i].softStop_max : jointPos;
    
    // Serial.println("Joint " + String(i) + " set to " + String(jointPos) + " on pin " + String(mainArm.joints[i].pin));

    // Write position to joint servo
    mainArm.joints[i].servo.write(jointPos);
    
  }
}
