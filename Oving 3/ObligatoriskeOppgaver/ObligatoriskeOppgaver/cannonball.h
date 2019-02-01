#pragma once

#pragma region Task 1 and 2
double acclY();

double velY(double initVelocityY, double time);

double posY(double initPosition, double initVelocity, double time);
double posX(double initPosition, double initVelocity, double time);

void printTime(double time);

double flightTime(double initVelocityY);
#pragma endregion


#pragma region Task 4
void getUserInput(double& theta, double& absVelocity);

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY);

// Takes in initial velocity in x and y and gives the traveled distance in the x-axis
double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

#pragma endregion

void playTargetPractice(int rounds);

