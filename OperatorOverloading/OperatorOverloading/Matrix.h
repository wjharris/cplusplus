#pragma once
#include <vector>
using namespace std;
class Matrix
{
public:
	vector<vector<int>> a;
	Matrix operator+(Matrix &other);
	Matrix();
	~Matrix();
};

