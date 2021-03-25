// Vdestructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Person {
public:
	virtual ~Person() {	// trick is the "virtual" keyword
		cout << "Deleting a person." << endl;

	}

};

class Student : public Person {
public:
	~Student() {
		cout << "Deleting a student." << endl;

	}
};

int main() {
	Person * p = new Student();
	delete p;
}
