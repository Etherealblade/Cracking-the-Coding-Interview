/*
https://www.geeksforgeeks.org/find-a-pair-swapping-which-makes-sum-of-two-arrays-same/
分析得非常清晰,不运行了
*/

#include <iostream>
using namespace std;

// Function to calculate sum of elements of array 
int getSum(int X[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += X[i];
	return sum;
}

// Function to calculate : a - b = (sumA - sumB) / 2 
int getTarget(int A[], int n, int B[], int m)
{
	// Calculation of sums from both arrays 
	int sum1 = getSum(A, n);
	int sum2 = getSum(B, m);

	// because that the target must be an integer 
	//if ((sum1 - sum2) % 2 != 0)
	//	return 0;
	return ((sum1 - sum2) / 2);
}

// Naive
void findSwapValues1(int A[], int n, int B[], int m)
{
	// Calculation of sums from both arrays 
	int sum1 = getSum(A, n);
	int sum2 = getSum(B, m);

	// Look for val1 and val2, such that 
	// sumA - val1 + val2 = sumB - val2 + val1 
	int newsum1, newsum2, val1, val2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			newsum1 = sum1 - A[i] + B[j];
			newsum2 = sum2 - B[j] + A[i];
			if (newsum1 == newsum2) {
				val1 = A[i];
				val2 = B[j];
			}
		}
	}

	cout << val1 << "  " << val2;
}

// 还是那句话, 万事先排序
void findSwapValues(int A[], int n, int B[], int m)
{
	// Call for sorting the arrays 
	sort(A, A + n);
	sort(B, B + m);

	// Note that target can be negative 
	int target = getTarget(A, n, B, m);

	// target 0 means, answer is not possible 
	if (target == 0)
		return;

	int i = 0, j = 0;
	while (i < n && j < m) {
		int diff = A[i] - B[j];
		if (diff == target) {
			cout << A[i] << " " << B[j];
			return;
		}

		// Look for a greater value in A[] 
		else if (diff < target)
			i++;

		// Look for a greater value in B[] 
		else
			j++;
	}
}

int main()
{
	int A[] = { 4, 1, 2, 1, 1, 2 };
	int n = sizeof(A) / sizeof(A[0]);

	int B[] = { 1, 6, 3, 3 };
	int m = sizeof(B) / sizeof(B[0]);

	findSwapValues(A, n, B, m);

	return 0;
}
