/*
  Joint.h - Library for controlling a joint in a multi-axis servo arm.
  Created by David M. Gamero, Aug 29, 2018.
  Released into the public domain.
*/

#ifndef Joint_h
#define Joint_h

#include "Arduino.h"
#include <Servo.h>

static const int default_softStop_min = 10;
static const int default_softStop_max = 170;
static const int default_pos = 90;

class Joint
{
  public:
    Joint();
    Joint(int _pin);
    Joint(int _pin, int _pos, int _softStop_min, int _softStop_max);

    int getPin();
    
    void setPos(int _pos);
    int getPos();
    
    void setSoftStop_min(int _softStop_min);
    int getSoftStop_min();
    void setSoftStop_max(int _softStop_max);
    int getSoftStop_max();
    
  private:
    int softStop_min;
    int softStop_max;
    int pos;
    int pin;
    Servo servo;
};

#endif
