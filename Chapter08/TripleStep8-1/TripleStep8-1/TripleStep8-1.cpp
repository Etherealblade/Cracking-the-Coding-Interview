// https://www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/

#include <iostream>
using namespace std;

#define DP

class GFC
{
	// Returns count of ways to reach n-th stair using 
	// 1 or 2 or 3 steps.
public:
	int findStep(int n)
	{
		if (n == 1 || n == 0)
		{
			return 1;
		}
		else if (n == 2)
		{
			return 2;
		}
		else
		{
			return findStep(n - 3) +
				findStep(n - 2) + findStep(n - 1);
		}
	}
};


// DP
int countWays(int n)
{
	int *res = new int[n + 1];
	// 楼梯的实际层数为n, 但是int res[n]的实际下标为
	// 0..n-1, 所以会出现越界异常.

	res[0] = 1;
	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		res[i] = res[i - 1] + res[i - 2]
			+ res[i - 3];
	}

	return res[n];
}

int main()
{
	int n = 4;

#ifdef DP
	cout << "DP: " << countWays(n) << endl;
#endif

	GFC g;
	cout << "Recursion: " << g.findStep(n) << endl;

	return 0;
}