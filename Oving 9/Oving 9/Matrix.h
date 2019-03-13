#pragma once
#include <iostream>

using namespace std;


class Matrix
{
	double **matrix; // Array of pointers to pointers
	int rows, cols;

	int findLongestNumber() const;

public:
	// Constructors
	Matrix(); // default
	Matrix(const int nRows, const int nColumns); // Most common
	explicit Matrix(int nRows); // Identity matrix

	// Set-get
	double get(int row, int col) const;
	void set(int row, int col, double value);

	int getRows() const;
	int getCols() const;

	// Check if matrix is valid
	bool isValid() const;

	// Out-operator
	friend ostream& operator<<(ostream& os, const Matrix& m);

	// Copy-operators
	Matrix(const Matrix &rhs);
	Matrix &operator=(Matrix rhs);

	// Other operators
	Matrix &operator+=(const Matrix &rhs);
	friend Matrix operator+(Matrix lhs, const Matrix &rhs);
	

	// Destructor
	~Matrix();
};

