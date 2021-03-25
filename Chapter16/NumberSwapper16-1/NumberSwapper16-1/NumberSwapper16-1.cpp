// NumberSwapper16-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// swap 2 numbers using "+" and "-"
void Swapper1(int a, int b)
{
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	a = a - b;
	b = a + b;
	a = b - a;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}

// swap 2 data using xor, this spaw() not olny can
// swap int date
void Swapper2(char a, char b)
{
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	a = a ^ b;	//a 101A110 011
	b = a ^ b;	//b = 011A110 = 101
	a = a ^ b;	//a = 011A101 = 110

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}



int main()
{
	int a = 1, b = 2;
	Swapper1(a, b);

	char c = 'c', d = 'd';
	Swapper2(c, d);

}
