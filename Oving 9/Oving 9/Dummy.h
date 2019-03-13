#pragma once

#include <iostream>

using namespace std;

class Dummy
{
public:
	int *num;

	Dummy()
	{
		num = new int{ 0 };
	}

	Dummy(const Dummy &other);

	Dummy &operator=(Dummy rhs);

	~Dummy()
	{
		delete num;
	}
};

void dummyTest();

