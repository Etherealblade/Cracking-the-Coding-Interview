/* 
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/\

The above solution prints duplicate permutations if
there are repeating characters in input string: "AABC"

The solution of printing only distinct permutations even 
if there are duplicates in input, watch 8-8
*/
#include <iostream>
#include <string>
using namespace std;

void permute(string a, int l, int r)
{
	if (l == r)
	{
		cout << a << endl;
	}

	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);

			// Recursive call
			permute(a, l + 1, r);

			// backtrack
			swap(a[l], a[i]);
		}
	}
}

int main()
{
	string str = "AABC";
	int n = str.size();
	permute(str, 0, n - 1);
	return 0;
}

