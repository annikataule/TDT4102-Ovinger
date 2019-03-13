#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
/////////////
// Private //
/////////////

//Finds the longest number in the matrix
int Matrix::findLongestNumber() const
{
	int longest = 0;
	if (isValid())
	{
		int word;
		ostringstream s;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				s << get(i, j);
				word = s.str().length();
				s.str("");
				s.clear();
				if (word > longest)
					longest = word;
			}
		}
	}
	return longest;
}


////////////
// Public //
////////////

// Default
Matrix::Matrix()
{
	matrix = nullptr;
	rows = 0, cols = 0; // Illegal size
}

// General
Matrix::Matrix(const int nRows, const int nColumns)
{
	// To make cleanup easier
	rows = nRows; 
	cols = nColumns;

	matrix = new double*[nRows] {}; // Create a list of pointers to array of ints
	
	for (int i = 0; i < nRows; ++i)
	{
		matrix[i] = new double[nColumns] {0}; // Fill the list with an array of ints
		for (int j = 0; j < nColumns; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

// Identity-matrix
Matrix::Matrix(int nRows) : Matrix(nRows, nRows)
{
	for (int i = 0; i < nRows; i++)
	{
		matrix[i][i] = 1; // Set the default diagonal to 1
	}
}

// Set-get-functions
double Matrix::get(int row, int col) const
{
	return matrix[row][col];
}

void Matrix::set(int row, int col, double value)
{
	matrix[row][col] = value;
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getCols() const
{
	return cols;
}

bool Matrix::isValid() const
{
	if (matrix == nullptr || rows * cols == 0)  // If the size is 0 in either direction, then the matrix is invalid
		return false;
	return true;
}

// Outsream-operator
ostream & operator<<(ostream & os, const Matrix & m)
{
	if (m.isValid())
	{
		int width = m.findLongestNumber();
		for (int i = 0; i < m.rows; i++)
		{
			for (int j = 0; j < m.cols; j++)
			{
				os << ' ' << setw(width) << m.get(i, j);
			}
			os << endl;
		}
		return os;
	}
	// If the matrix is non-valid, print this
	return os << "The matrix is in an invalid state" << endl; 
}

// Copy-constructor
Matrix::Matrix(const Matrix & rhs) : matrix{nullptr}
{
	this->rows = rhs.rows; // Copy size
	this->cols = rhs.cols; // Copy size
	this->matrix = new double*[rhs.rows] {}; // Create a list of pointers to array of ints
	for (int i = 0; i < this->rows; ++i)
	{
		matrix[i] = new double[this->cols] {0}; // Allocate the right amount of memory
		for (int j = 0; j < this->cols; j++)
		{
			this->matrix[i][j] = rhs.matrix[i][j]; // Copy all values
		}
	}
}

// Copy-operator
Matrix & Matrix::operator=(Matrix rhs)
{
	swap(rows, rhs.rows);
	swap(cols, rhs.cols);
	swap(matrix, rhs.matrix);
	return *this;
}

// Add rhs to lhs (RightHandSide and LeftHandSide)
Matrix & Matrix::operator+=(const Matrix & rhs)
{
	if (this->isValid() && rhs.isValid() && this->rows == rhs.rows && this->cols == rhs.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->matrix[i][j] += rhs.get(i, j);
			}
		}
		return *this;
	}
	this->matrix = nullptr;
	return *this;
}



// Binary-add-operator
Matrix operator+(Matrix lhs, const Matrix & rhs)
{
	lhs += rhs; 
	return lhs;
}


Matrix::~Matrix()
{
	if (isValid())
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i]; // Delete all pointers to array of ints
		}
		delete[] matrix; // Delete all pointers to array of pointers
	}

	matrix = nullptr; // Sets the matrix to an illegal state
}
