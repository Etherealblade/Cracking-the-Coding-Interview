﻿/*
https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/
C++ Code to find Smallest
Difference between two Arrays

明白思路就可以,没有sort(), 就不运行也不纠结了
*/

#include <iostream> 
#include <vector>
using namespace std;

// function to calculate Small  
// result between two arrays 
int findSmallestDifference(int A[], int B[],
	int m, int n)
{
	// Sort both arrays using 
	// sort function 
	sort(A, A + m);
	sort(B, B + n);

	int a = 0, b = 0;

	// Initialize result as max value 
	int result = INT_MAX;

	// Scan Both Arrays upto  
	// sizeof of the Arrays 
	while (a < m && b < n)
	{
		if (abs(A[a] - B[b]) < result)
			result = abs(A[a] - B[b]);

		// Move Smaller Value 
		if (A[a] < B[b])
			a++;

		else
			b++;
	}

	// return final sma result 
	return result;
}

// Driver Code 
int main()
{
	// Input given array A 
	int A[] = { 1, 2, 11, 5 };

	// Input given array B 
	int B[] = { 4, 12, 19, 23, 127, 235 };


	// Calculate size of Both arrays 
	int m = sizeof(A) / sizeof(A[0]);
	int n = sizeof(B) / sizeof(B[0]);

	// Call function to print  
	// smallest result 
	cout << findSmallestDifference(A, B, m, n);

	return 0;
}