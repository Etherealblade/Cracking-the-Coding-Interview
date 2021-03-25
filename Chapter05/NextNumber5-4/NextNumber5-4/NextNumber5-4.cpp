/*
https://www.geeksforgeeks.org/closest-next-smaller-greater-numbers-number-set-bits/
C++ implementation of  getNext with
same number of bits 1's is below
*/

#include <iostream>
using namespace std;

/*
Main func to find next smallest number bigger than n
*/
int getNext(int n)
{
	// Compute c0 and c1
	int c = n;
	int c0 = 0;
	int c1 = 0;

	while (((c&1)==0)&&(c!=0))
	{
		c0++;
		c >>= 1;
	}

	while ((c&1)==1)
	{
		c1++;
		c >>= 1;
	}

	// If there is no bigger number with the
	// same no. of 1's
	if (c0+c1==31 || c0+c1==0)
	{
		return -1;
	}

	// position of rightmost non-trailing zero 
	int p = c0 + c1;

	// Flip rightmost non-trailing zero
	n |= (1 << p);

	// Clear all bits to the right of p 
	n &= ~((1 << p) - 1);

	// Insert (c1-1) ones on the right. 
	n |= (1 << (c1 - 1)) - 1;

	return n;
}

// Main Function to find next Bigger number 
// Smaller than n 
int getPrev(int n)
{
	/* Compute c0 and c1  and store N*/
	int temp = n;
	int c0 = 0;
	int c1 = 0;

	while ((temp&1)==1)
	{
		c1++;
		temp = temp >> 1;
	}

	if (temp==0)
	{
		return -1;
	}

	while (((temp & 1) == 0) && (temp != 0))
	{
		c0++;
		temp = temp >> 1;
	}

	// position of rightmost non-trailing one 
	int p = c0 + c1;

	// clears from bit p onwards 
	n = n & ((~0) << (p + 1));

	// Sequence of (c1+1) ones 
	int mask = (1 << (c1 + 1)) - 1;

	n = n | mask << (c0 - 1);

	return n;
}


int main()
{
	int n = 5;   // input 1 
	cout << getNext(n) << endl;

	n = 8;     // input 2 
	cout << getNext(n) << endl;

	n = 6;
	cout << getPrev(n) << endl;
	n = 16;
	cout << getPrev(n) << endl;

	return 0;
}
