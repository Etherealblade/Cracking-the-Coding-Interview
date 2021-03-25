#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int rand5()
{
	int result;

	srand(time(NULL));
	result = rand() % 5;

	return result;
}

int rand7()
{
	while (true) {
		int num = 5 * rand5() + rand5();
		if (num < 21) 
		{
			return num % 7;
		}
	}
}

int main()
{
	cout << "test: " << rand7() << endl;
}
