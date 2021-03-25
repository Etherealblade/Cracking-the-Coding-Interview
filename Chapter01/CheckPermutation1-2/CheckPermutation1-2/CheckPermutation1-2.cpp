/*
https://www.geeksforgeeks.org/check-if-two-strings-are-permutation-of-each-other/
if didn't have any idea, then sort the data first!
The idea of this project is similar to counting sort!
*/

#include <iostream>
#include <string>
using namespace std;
#define NO_OF_CHARS 256 

bool arePermutation(string str1, string str2)
{
	int count[NO_OF_CHARS] = { 0 };

	if (str1.length() != str2.length())
	{
		return false;
	}

	// For each character in input strings,  
	// increment count in the corresponding  
	// count array 
	for (int i = 0; str1[i] && str2[i]; i++)
	{
		count[str1[i]]++;
		count[str2[i]]--;
	}
	// See if there is any non-zero value in  
	// count array 
	for (int i = 0; i < NO_OF_CHARS; i++)
		if (count[i])
			return false;
	return true;
}


int main()
{
	string str1 = "geeksforgeeks";
	string str2 = "forgeeksgeeks";
	if (arePermutation(str1, str2))
		printf("Yes");
	else
		printf("No");

	return 0;
}
