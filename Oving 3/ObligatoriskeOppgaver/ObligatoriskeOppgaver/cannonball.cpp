#include "cannonball.h"
#include "std_lib_facilities.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "utilities.h"

double acclY()
{
	return -9.81;
}

double velY(double initVelocityY, double time)
{
	return initVelocityY + acclY() * time;
}

double posY(double initPosition, double initVelocity, double time)
{
	return initPosition + initVelocity * time + (acclY() *pow(time, 2)) / 2;
}

double posX(double initPosition, double initVelocity, double time)
{
	return initPosition + initVelocity * time;
}

void printTime(double time)
{
	int minSec = 60;
	int hourSec = pow(minSec, 2);
	int hours = time / hourSec;
	int timeLeft = time - hours * hourSec;
	int minutes = timeLeft / minSec;
	timeLeft = timeLeft - minutes * minSec;
	cout << hours << " hours, " << minutes << " minutes, " << timeLeft << " seconds" << "\n";
}

double flightTime(double initVelocityY)
{
	return (-2 * initVelocityY) / acclY();
}

void getUserInput(double& theta, double& absVelocity)
{
	double deg;
	cout << "Angle of velocity: ";
	cin >> deg;
	theta = degToRad(deg);
	cout << "Velocity: ";
	cin >> absVelocity;
}

double degToRad(double deg)
{
	return deg * M_PI / 180;
}

double getVelocityX(double theta, double absVelocity)
{
	return absVelocity * cos(theta);
}

double getVelocityY(double theta, double absVelocity)
{
	return absVelocity * sin(theta);
}

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY)
{
	velocityX = getVelocityX(theta, absVelocity);
	velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) 
{
	return posX(0, velocityX, flightTime(velocityY));
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
	return abs(distanceToTarget - getDistanceTraveled(velocityX, velocityY));
}

void playTargetPractice(int rounds)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	bool won = false;
	double theta, absVelocity; // Initial angle and velocity
	double initX, initY; // Initial velocities, in component-form
	double fTime;
	double distance;
	int target = randomWithLimits(100, 1000);
	for (int r = 1; r <= rounds; ++r)
	{
		getUserInput(theta, absVelocity);
		getVelocityVector(theta, absVelocity, initX, initY);
		printTime(flightTime(initY));
		cout << "The cannonball flew " << getDistanceTraveled(initX, initY) << " meters" << endl;
		distance = targetPractice(target, initX, initY);
		cout << "The cannonball is  " << distance << " meters away from target" << endl;
		if (distance <= 5)
		{
			won = true;
			break;
		}
		else
		{
			if (distance < 0)
				cout << "The shot wat too short" << endl;
			else
				cout << "The shot was to far" << endl;
		}
	}
	if (won)
		cout << "Congratulate, you have won!" << endl;
	else
		cout << "Sorry, game over!" << endl;
}
