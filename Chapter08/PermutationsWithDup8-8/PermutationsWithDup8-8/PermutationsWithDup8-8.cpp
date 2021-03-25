/* https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/
This project refer to 8-7
hard to understand, because no analyzing figure.
*/

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

/*
Following function is needed for library
function qsort().
*/
int compare(const void* a, const void* b)
{
	return (*(char*)a - *(char*)b);
}

// A utility function two swap two characters 
// a and b 
void swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

/*
This function finds the index of the
smallest character which is greater
than 'first' and is present in str[l..h]
*/
int findCeil(char str[], char first, int l, int h)
{
	// initialize index of ceiling element
	int ceilIndex = l;

	/*
	Now iterate through rest of the
	elements and find the smallest
	character greater than 'first'
	*/
	for (int i = l + 1; i <= h; i++)
	{
		if (str[i] > first && str[i] < str[ceilIndex])
		{
			ceilIndex = i;
		}
	}

	return ceilIndex;
}

// Print all permutations of str in sorted order 
void sortedPermutations(char str[])
{
	int size = strlen(str);

	qsort(str, size, sizeof(str[0]), compare);

	// Print permutations one by one 
	bool isFinished = false;
	while (!isFinished)
	{

		// print this permutation
		static int x = 1;
		printf("%d %s \n", x++, str);

		/*
		Find the rightmost character
		which is smaller than its next
		character. Let us call it 'first
		char'
		*/
		int i;
		for (i = size - 2; i >= 0; --i)
		{
			if (str[i] < str[i + 1])
			{
				break;
			}
		}

		// If there is no such character, all 
		// are sorted in decreasing order, 
		// means we just printed the last 
		// permutation and we are done. 
		if (i == -1)
			isFinished = true;
		else
		{
			// Find the ceil of 'first char' 
			// in right of first character. 
			// Ceil of a character is the 
			// smallest character greater 
			// than it 
			int ceilIndex = findCeil(str, str[i],
				i + 1, size - 1);

			// Swap first and second characters 
			swap(&str[i], &str[ceilIndex]);

			// Sort the string on right of 'first char' 
			qsort(str + i + 1, size - i - 1,
				sizeof(str[0]), compare);
		}
	}
}

// Driver program to test above function 
int main()
{
	char str[] = "ACBC";
	sortedPermutations(str);
	return 0;
}
