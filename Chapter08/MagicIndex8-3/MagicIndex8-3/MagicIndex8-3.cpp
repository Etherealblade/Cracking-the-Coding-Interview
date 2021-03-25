// https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/

#include <iostream>
using namespace std;
#define LINEAR

int linearSearch(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == i)
		{
			return i;
		}
	}

	// If no fixed point present then return -1
	return -1;
}

// Recursive
int binarySearch(int arr[], int low, int high)
{
	if (high >= low)
	{
		int mid = (low + high) / 2;
		if (mid == arr[mid])
		{
			return mid;
		}

		if (mid > arr[mid])
		{
			return binarySearch(arr, mid + 1, high);
		}
		else
		{
			return binarySearch(arr, low, mid - 1);
		}

	}

	return -1;
}

int main()
{
	int arr[] = { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
	int n = sizeof(arr) / sizeof(arr[0]);

#ifdef LINEAR
	cout << "Linear, Fixed Point is " <<
		linearSearch(arr, n) << endl;
#endif

	cout << "Recursive, Fixed Point is "
		<< binarySearch(arr, 0, n - 1) << endl;

	return 0;
}

