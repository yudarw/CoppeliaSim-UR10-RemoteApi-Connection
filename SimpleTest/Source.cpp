#include "coppeliasim.h"

CoppeliaSim mSim;
CoppeliaRobot mRobot;

int main(int argc, char* argv[]){
	mSim.connect(19997);

	getchar();
	return 0;
}