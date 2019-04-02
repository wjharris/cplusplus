#include "pch.h"
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;


Person::Person()
{
}

int Student::cid = 0;
int Professor::cid = 0;


Person::~Person()
{
}

void Person::getData() {
	cin >> Person::name >> Person::age;
}

void Person::putData() {
	cout << Person::name << " " << Person::age << " ";
}


Student::Student() : Person() {
	cid += 1;
	thisId = cid;
}

Student::~Student() {}

Professor::Professor() : Person() {
	cid += 1;
	thisId = cid;
}

Professor::~Professor() {}

void Student::getData() {
	Person::getData();
	for (int i = 0; i < 6; i++) {
		cin >> marks[i];
	}
}

void Student::putData() {
	Person::putData();
	int total = 0;
	for (int i = 0; i < 6; i++) {
		total += marks[i];
	}

	cout << total << " " << thisId << endl;
}

void Professor::getData() {
	Person::getData();
	cin >> publications;
}

void Professor::putData() {
	Person::putData();
	cout << publications << " " << thisId << endl;
}
