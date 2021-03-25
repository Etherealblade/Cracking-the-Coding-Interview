/*
https://www.geeksforgeeks.org/find-longest-sequence-1s-binary-representation-one-flip/
Need to observe, and find the rule
*/

#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int flipBit(unsigned a)
{
	/* If all bits are l, binary representation
	   of 'a' has all 1s */
	if (~a == 0)
		return 8 * sizeof(int);

	int currLen = 0, prevLen = 0, maxLen = 0;
	while (a != 0)
	{
		// If Current bit is a 1 then increment currLen++ 
		if ((a & 1) == 1)
			currLen++;

		// If Current bit is a 0 then check next bit of a 
		else if ((a & 1) == 0)
		{
			/* Update prevLen to 0 (if next bit is 0)
			or currLen (if next bit is 1). */
			prevLen = (a & 2) == 0 ? 0 : currLen;

			// If two consecutively bits are 0 
			// then currLen also will be 0. 
			currLen = 0;
		}

		// Update maxLen if required 
		maxLen = max(prevLen + currLen, maxLen);

		// Remove last bit (Right shift) 
		a >>= 1;
	}

	// We can always have a sequence of 
	// at least one 1, this is flipped bit 
	return maxLen + 1;
}


int main()
{
	// input 1 
	cout << flipBit(13);
	cout << endl;

	// input 2 
	cout << flipBit(1775);
	cout << endl;

	// input 3 
	cout << flipBit(111);

	return 0;
}
