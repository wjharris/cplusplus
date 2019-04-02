//https://www.hackerrank.com/challenges/virtual-functions/problem
#include "pch.h"
#include "Person.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n, val;
	cin >> n; //The number of objects that is going to be created.
	vector<Person*> per = vector<Person*>(n);

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor();

		}
		else per[i] = new Student(); // Else the current object is of type Student

		per[i]->getData();

	}

	for (int i = 0; i < n; i++)
		per[i]->putData(); // Print the required output for each object.

	return 0;

}