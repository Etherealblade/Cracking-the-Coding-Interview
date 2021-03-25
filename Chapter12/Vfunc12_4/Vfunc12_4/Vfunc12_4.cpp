// Vfunc12_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Shape 
{
public:
	int edge_length;
	virtual int circumference() {
		cout << "Circumference of Base Class\n";
		return 0;

	}

};


class Triangle : public Shape
{
public:
	int circumference() {
		cout<< "Circumference of Triangle Class\n";
		return 3 * edge_length;

	}

};

void main() {
	Shape * x = new Shape();
	x->circumference(); // "Circumference of Base Class"
	Shape *y = new Triangle();
	y->circumference(); // "Circumference of Triangle Class"

}