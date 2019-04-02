#pragma once
#include <string>
using namespace std;

class Person
{
protected:
	int thisId;
	string name;
	int age;
public:
	Person();
	~Person();
	virtual void getData() = 0;
	virtual void putData() = 0;
};

class Student : public Person {
private:
	static int cid;
	int marks[6];
public:
	Student();
	~Student();
	virtual void getData();
	virtual void putData();
};

class Professor : public Person {
private:
	static int cid;
	int publications;
public:
	Professor();
	~Professor();
	virtual void getData();
	virtual void putData();
};

