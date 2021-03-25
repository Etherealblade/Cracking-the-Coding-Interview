/*
https://www.geeksforgeeks.org/inserting-m-into-n-such-that-m-starts-at-bit-j-and-ends-at-bit-i-set-2/
位数对齐很要命
*/

#include <iostream>
using namespace std;

// print binary representation of n 
void bin(unsigned n)
{
	if (n > 1)
		bin(n / 2);
	printf("%d", n % 2);
}

// Insert m into n
int insertion(int n, int m, int i, int j)
{
	int clear_mask = -1 << (j + 1);
	int capture_mask = (1 << i) - 1;

	// capturing bits from i-1 to 0
	int captured_bits = n & capture_mask;

	// clearing bits from j to 0
	n &= clear_mask;

	// shift m to align with n
	m = m << i;

	// Insert m into n 
	n |= m;

	// Insert captured bits
	n |= captured_bits;

	return n;
}

int main()
{
	// print original bitset 
	int N = 1201, M = 8, i = 3, j = 6;
	cout << "N = " << N << "(";
	bin(N);
	cout << ")" << "\n";

	// print original bitset 
	cout << "M = " << M << "(";
	bin(M);
	cout << ")"
		<< "\n";

	// Call function to insert M to N 
	N = insertion(N, M, i, j);
	cout << "After inserting M into N from 3 to 6"
		<< "\n";
	// Print the inserted bitset 
	cout << "N = " << N << "(";
	bin(N);
	cout << ")"
		<< "\n";
	return 0;


}

