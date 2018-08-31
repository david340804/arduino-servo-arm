#include "Arduino.h"
#include "Joint.h"
#include <Servo.h>


// --------------------------------------------------
// Constructybois
// --------------------------------------------------
Joint::Joint() : Joint(-1){}

Joint::Joint(int _pin) : Joint(_pin, default_pos, default_softStop_min, default_softStop_max){}

Joint::Joint(int _pin, int _pos, int _softStop_min, int _softStop_max){
  pin = _pin;
  servo.attach(pin);

  setPos(_pos);

  softStop_min = _softStop_min;
  softStop_max = _softStop_max;
}

// --------------------------------------------------
// Accessors and Mutators
// --------------------------------------------------
int Joint::getPin(){
  return pin;
}

void Joint::setPos(int _pos){
  // Dodge the -1 pins from the default constructor
  if(pin > 0){
    // Min/max software stops
    _pos = (_pos <  softStop_min) ?  softStop_min : _pos;
    _pos = (_pos >  softStop_max) ?  softStop_max : _pos;

    pos = _pos;
    servo.write(pos);
  }
  
}
int Joint::getPos(){
  return pos;
}

void Joint::setSoftStop_min(int _softStop_min){
  softStop_min = _softStop_min;
}
int Joint::getSoftStop_min(){
  return softStop_min;
}

void Joint::setSoftStop_max(int _softStop_max){
  softStop_max = _softStop_max;
}
int Joint::getSoftStop_max(){
  return softStop_max;
}

