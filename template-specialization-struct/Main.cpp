//https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };


template <typename T> struct Traits {
	static string name(int index);
};

string Traits<Fruit>::name(int index) {
	Fruit f = static_cast<Fruit>(index);
	switch (f) {
		case Fruit::apple: return "apple";
		case Fruit::orange: return "orange";
		case Fruit::pear: return "pear";
		default: return "unknown";
	}
}

string Traits<Color>::name(int index) {
	Color c = static_cast<Color>(index);
	switch (c) {
		case Color::red: return "red";
		case Color::green: return "green";
		case Color::orange: return "orange";
		default: return "unknown";
	}
}




// Define specializations for the Traits class template here.


int main()
{
	int t = 0; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int index1; std::cin >> index1;
		int index2; std::cin >> index2;
		std::cout << Traits<Color>::name(index1) << " ";
		std::cout << Traits<Fruit>::name(index2) << "\n";
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
