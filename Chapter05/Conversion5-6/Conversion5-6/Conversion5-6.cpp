// Code in the book is good enough

#include <iostream>
using namespace std;

int bitSwapRequired1(int a, int b)
{
	int count = 0;
	for (int c = a ^ b; c != 0; c = c >> 1)
	{
		count += c & 1;
	}

	return count;
}

int bitSwapRequired2(int a, int b)
{
	int count = 0;
	for (int c = a ^ b; c != 0; c = c & (c - 1))
	{
		count++;
	}

	return count;
}


int main()
{
	int a = 29, b = 15;
	cout << "bitSwapRequired1: " << 
		bitSwapRequired1(a, b) << endl;

	cout << "bitSwapRequired2: " <<
		bitSwapRequired2(a, b) << endl;
}
