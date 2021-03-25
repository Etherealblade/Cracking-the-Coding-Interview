/*
https://www.geeksforgeeks.org/count-occurrences-of-a-word-in-string/
C++ program to count the number
of occurrence of a word in
the given string given string
*/
#include <iostream> 
#include <vector>
#pragma warning (disable: 4996)
using namespace std;

int countOccurences(char *str,
	string word)
{
	char *p;

	// split the string by spaces in a 
	vector<string> a;

	p = strtok(str, " ");
	while (p != NULL)
	{
		a.push_back(p);
		p = strtok(NULL, " ");
	}

	// search for pattern in a 
	int c = 0;
	for (int i = 0; i < a.size(); i++)

		// if match found increase count 
		if (word == a[i])
			c++;
	return c;
}

// Driver code 
int main()
{
	char str[] = "GeeksforGeeks A computer science portal for geeks ";
	string word = "portal";
	cout << countOccurences(str, word);
	return 0;
}

