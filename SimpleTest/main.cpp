#include "coppeliasim.h"
#include "simple_test.h"
#include <iostream>

using namespace std;

CoppeliaSim mSim;
CoppeliaRobot mRobot;

CoppeliaRobotMobile omni(omniplatform, "/OmniPlatform");
CoppeliaRobotMobile mPioneer(pioneer, "/PioneerP3DX");
CoppeliaSensor camera(vision_sensor, "/Vision_sensor");

int main(int argc, char* argv[]){

	// Initialise coppeliasim connection
	if (mSim.connect(19997)) {
		mSim.startSimulation();
	}

	camera.init();
	getchar();

	mRobot.init("UR10");

	// Test the inverse kinematic movement
	float pos1[6] = { 500, -200, 300, 180, 0, 0 };
	float pos2[6] = { 500, 200, 300, 180, 0, 0 };
	
	mRobot.setSpeed(30);

	while (1) {
		mRobot.setPosition(pos1, true);
		mRobot.setPosition(pos2, true);
	}
	
	printf("Finish executing the movement!!! \n\n");

	getchar();
	return 0;
}