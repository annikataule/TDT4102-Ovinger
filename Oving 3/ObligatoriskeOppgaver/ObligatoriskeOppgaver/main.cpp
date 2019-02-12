#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

bool testDeviation(double compareOperant, double toOperand, double maxError, string name);

int main(){

#pragma region Testing - Task 3
	/*
	int space = 8;
	for (double i = 0; i <= 5; i += 2.5) {
		cout << setw(space) << acclY() << setw(space) << velY(25, i) << setw(space) <<
			posY(0, 25, i) << setw(space) << posX(0, 50, i) << endl;
	}
	*/
#pragma endregion

#pragma region Task 4d
	/*
	double theta;
	double absVelocity;
	getUserInput(theta, absVelocity);
	double initX, initY;
	getVelocityVector(theta, absVelocity, initX, initY);
	cout << "Distance traveled: " << getDistanceTraveled(initX, initY) << endl;
	cout << "Distance from target: " << targetPractice(10, initX, initY) << endl;
	*/
#pragma endregion

#pragma region Game - Task 5d

	int rounds = 10;

	playTargetPractice(rounds);

	

#pragma endregion

	return 0;
}

bool testDeviation(double compareOperant, double toOperand, double maxError, string name)
{
	if (abs(compareOperant - toOperand) < maxError)
		return true;
	return false;
}
