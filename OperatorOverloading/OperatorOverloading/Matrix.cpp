#include "pch.h"
#include "Matrix.h"


Matrix::Matrix()
{
	a = vector<vector<int>>();
}


Matrix::~Matrix()
{
}

Matrix Matrix::operator+(Matrix &other) 
{
	Matrix newMatrix = Matrix();

	for (int i = 0; i < a.size(); i++) {
		vector<int> row = a[i];
		vector<int> otherRow = other.a[i];
		vector<int> newRow = vector<int>();
		for (int j = 0; j < row.size(); j++) {
			newRow.push_back(row[j] + otherRow[j]);
		}
		newMatrix.a.push_back(newRow);
	}
	return newMatrix;
}
