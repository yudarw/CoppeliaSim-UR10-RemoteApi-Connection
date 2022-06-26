#include "simple_test.h"
#include "coppeliasim.h"
#include <iostream>

using namespace std;

CoppeliaSim sim;

void coppelia_function_test() {
	cout << ">>> Execute the function test program" << endl;
	sim.connect(19997);
	int id = sim.clientID;

	// Get object handles:
	int simCuboid;
	simxGetObjectHandle(id, "/Cuboid", &simCuboid, simx_opmode_oneshot_wait);
	cout << "Cuboid handle: " << simCuboid << endl;

	for (int i = 0; i < 10; i++) {
		// Copy paste object:
		int* simNewObject;
		int newObjCount;
		int newObjHandle;
		simxCopyPasteObjects(id, &simCuboid, 1, &simNewObject, &newObjCount, simx_opmode_blocking);
		newObjHandle = simNewObject[0];

		printf("New object count = %d \n", newObjCount);
		printf("New object handle = %d \n", newObjHandle);

		// Set the object properties to dynamic:
		//Sleep(1);
		float newPos[3] = { 0.25, 0.5, 1.0 };
		simxSetObjectPosition(id, newObjHandle, -1, newPos, simx_opmode_blocking);
		simxSetObjectInt32Param(id, newObjHandle, sim_shapeintparam_static, 0, simx_opmode_blocking);
		Sleep(3000);
	}
		while (1);
}