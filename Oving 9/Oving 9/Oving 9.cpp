// Oving 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "Fibonacci.h"
#include "Matrix.h"
#include "Dummy.h"

using namespace std;

int main()
{
	// createFibonacci();

	/*
	Matrix m1{ 10 };

	Matrix m2{ m1 };

	Matrix m3;

	Matrix m4{ 4, 5 };

	m3 = m2;

	m1.set(0, 0, 2);

	m3.set(0, 1, 10);

	m2.set(0, 1, 42);

	cout << m1 << endl;

	cout << m2 << endl;

	cout << m3 << endl;

	m3 += m2;

	cout << m3 << endl;

	m3 += m4;

	cout << m3 << endl;

	*/

	Matrix A{ 2,2 };
	Matrix B{ 2,2 };
	Matrix C{ 2,2 };

	A.set(0, 0, 1);
	A.set(0, 1, 2);
	A.set(1, 0, 3);
	A.set(1, 1, 4);

	B.set(0, 0, 4);
	B.set(0, 1, 3);
	B.set(1, 0, 2);
	B.set(1, 1, 1);

	C.set(0, 0, 1);
	C.set(0, 1, 3);
	C.set(1, 0, 1.5);
	C.set(1, 1, 2);

	cout << A << endl;
	cout << B << endl;
	cout << C << endl;

	A += B + C;

	cout << A << endl;
	cout << B << endl;
	cout << C << endl; 

#pragma region Task 3

	/*
	Når dummy kjører vil det skrives ut:

	"a: 4"
	"b: 4"
	"c: 4"

	"a: 4"
	"b: 3"
	"c: 5"

	*/

	//dummyTest(); // Stemmer ikke overens med ovenfor

	/* Skriver ut
	"a: 4"
	"b: 4"
	"c: 4"

	"a: 5"
	"b: 5"
	"c: 5"
	*/

	/* 3c)
	Etter kopikonstruktøren fungerer Dummy b
	*/

	/* 3d)
	Etter =-operatøren fungerer programmet som forventet
	*/

#pragma endregion

	return 0;
}

