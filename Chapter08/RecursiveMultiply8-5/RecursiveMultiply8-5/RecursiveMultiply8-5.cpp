// https://www.geeksforgeeks.org/multiply-two-numbers-without-using-multiply-division-bitwise-operators-and-no-loops/

#include <iostream>
using namespace std;

int multiply(int x, int y)
{
	// 0 multiplied with anything gives 0
	if (y == 0)
	{
		return 0;
	}

	if (y > 0)
	{
		return x + multiply(x, y - 1);
	}

	// the case where y is negative
	if (y < 0)
	{
		return -multiply(x, -y);
	}
}

int main()
{
	cout << multiply(5, -11) << endl;
	getchar();

	return 0;
}
