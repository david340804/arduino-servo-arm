/*
  ServoArm.h - Library for controlling a Joint-based multi-axis servo arm.
  Created by David M. Gamero, Aug 29, 2018.
  Released into the public domain.
*/

#ifndef ServoArm_h
#define ServoArm_h

#include "Arduino.h"
#include <Joint.h>

static const int max_joints = 10;

class ServoArm
{
  public:
    ServoArm();

    int getJointPos(int _join);
    void setJointPos(int _joint, int pos);

    void addJoint(Joint _joint);
    
  private:
    Joint joints[max_joints];
    int numJoints = 0;
};

#endif
