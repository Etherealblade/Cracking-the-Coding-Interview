/*
https://www.geeksforgeeks.org/converting-a-real-number-between-0-and-1-to-binary-string/
Feeling that it's hard to calculate at the very beginning
, but...
*/

#include <iostream>
#include <string>
using namespace std;

// Function to convert Binary real 
// number to String, Ugly!
string toBinary1(double n)
{
	// Check if the number is Between 0 to 1 or Not 
	if (n >= 1 || n <= 0)
		return "ERROR";

	string answer;
	double frac = 0.5;
	answer.append(".");

	// Setting a limit on length: 32 characters.          
	while (n > 0)
	{
		//Setting a limit on length: 32 characters      
		if (answer.length() >= 32)
			return "ERROR";

		// Multiply n by 2 to check it 1 or 0 
		double b = n * 2;
		if (b >= 1)
		{
			answer.append("1");
			n = b - 1;
		}
		else
		{
			answer.append("0");
			n = b;
		}

	}

	return answer;
}

string toBinary2(double n)
{
	// Check if the number is Between 0 to 1 or Not 
	if (n >= 1 || n <= 0)
		return "ERROR";

	string answer;
	double frac = 0.5;
	answer.append(".");

	// Setting a limit on length: 32 characters.          
	while (n > 0)
	{
		// 32 char max 
		if (answer.length() >= 32)
			return "ERROR";
		// compare the number to .5 
		if (n >= frac)
		{
			answer.append("1");
			n = n - frac;
		}
		else
		{
			answer.append("0");
		}

		frac /= 2;
	}

	return answer;
}


int main()
{
	// Input value  
	double n = 0.625;

	string result = toBinary2(n);
	cout << n << endl << "(0" << result << ") in base 2" << endl;

	double m = 0.72;
	result = toBinary2(m);
	cout << m << endl << "(" << result << ")" << endl;

}
