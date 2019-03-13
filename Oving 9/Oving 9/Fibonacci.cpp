#include "pch.h"
#include "Fibonacci.h"

void fillInFibonacciNumbers(int result[], int length)
{
	int lo = 0;
	int hi = 1;

	int sum;

	for (int i = 0; i < length; ++i)
	{
		result[i] = lo;
		sum = lo + hi;
		lo = hi;
		hi = sum;
	}

}

void printArray(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << arr[i] << endl;
	}
}

void createFibonacci()
{
	int length;

	cout << "How many fibonacci numbers? ";
	cin >> length;

	int *numbers = new int[length] {};

	fillInFibonacciNumbers(numbers, length);

	printArray(numbers, length);
	
	delete[] numbers;
	numbers = nullptr;

}
