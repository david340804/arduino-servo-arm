#include "Arduino.h"
#include "ServoArm.h"


#include <Joint.h>

ServoArm::ServoArm(){

}

void ServoArm::addJoint(Joint _joint){
	if(numJoints < max_joints){
		joints[numJoints] = _joint;
		numJoints = numJoints + 1;
	}
}

int ServoArm::getJointPos(int _joint){
	return joints[0].getPos();
}
void ServoArm::setJointPos(int _joint, int _pos){
	joints[_joint].setPos(_pos);
}