#include "coppeliasim.h"
#include "simple_test.h"

CoppeliaSim mSim;
CoppeliaRobot mRobot;

int main(int argc, char* argv[]){

	coppelia_function_test();

	// Initialise robot connection
	mSim.connect(19999);
	mRobot.init("UR10");

	// Wait
	Sleep(2000);
	
	// Move robot joint position
	float configPos[6] = { 135, -15, 0, 0, 90, 0 };
	//mRobot.setJointPosition(configPos);
	
	// Test the inverse kinematic movement
	float pos1[6] = { 500, -200, 300, 180, 0, 0 };
	float pos2[6] = { 500, 200, 300, 180, 0, 0 };
	
	while (1) {
		mRobot.setPosition(pos1, true);
		mRobot.setPosition(pos2, true);
	}
	
	printf("Finish executing the movement!!! \n\n");

	getchar();
	return 0;
}