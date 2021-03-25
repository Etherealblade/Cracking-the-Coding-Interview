/*
https://www.geeksforgeeks.org/determine-string-unique-characters/
*/

#include <iostream>
#include <string>
using namespace std;

bool uniqueCharacters(string str)
{
	// Assuming string can have characters 
	// a-z, this has 32 bits set to 0 
	int checker = 0;

	for (int i = 0; i < str.length(); i++) {

		int bitAtIndex = str[i] - 'a';

		// if that bit is already set in 
		// checker, return false 
		if ((checker & (1 << bitAtIndex)) > 0) {
			return false;
		}

		// otherwise update and continue by 
		// setting that bit in the checker 
		checker = checker | (1 << bitAtIndex);
	}

	// no duplicates encountered, return true 
	return true;
}

int main()
{
	string str = "hutg9mnd!nk9";

	if (uniqueCharacters(str)) {
		cout << "The String " << str
			<< " has all unique characters\n";
	}
	else {
		cout << "The String " << str
			<< " has duplicate characters\n";
	}
	return 0;
}

