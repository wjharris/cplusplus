//https://www.hackerrank.com/challenges/operator-overloading/problem


#include "pch.h"
#include "Matrix.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int cases, k;
	cin >> cases;
	for (k = 0; k < cases; k++) {
		
		int n, m, i, j;
		cin >> n >> m;
		Matrix x;
		Matrix y;
		for (i = 0; i < n; i++) {
			vector<int> b = vector<int>();
			int num;
			for (j = 0; j < m; j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for (i = 0; i < n; i++) {
			vector<int> b = vector<int>();
			int num;
			for (j = 0; j < m; j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}
		Matrix result = x + y;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
