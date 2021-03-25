
#include <iostream>
using namespace std;

int add1(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	int sum = a ^ b;		// add without carry
	int carry = (a&b) << 1;	// carry, but don't add

	return add1(sum, carry);
}

int add2(int a, int b)
{
	while (b != 0)
	{
		int sum = a ^ b;		// add without carrying
		int carry = (a&b) << 1;	// carry, but don't add
		a = sum;
		b = carry;
	}

	return a;
}

int main()
{
	int a = 3, b = 4;
	cout << "add1: " << add1(a, b) << endl;
	cout << "add2: " << add2(a, b) << endl;
}

