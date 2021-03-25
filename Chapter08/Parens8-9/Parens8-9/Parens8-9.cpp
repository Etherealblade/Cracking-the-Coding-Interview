/*
https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
https://github.com/careercup/CtCI-6th-Edition-cpp/blob/master/chapter-8-recursion-and-Dynamic-Programming/8-9-parens.cpp

*/
#include <iostream>
#define MAX_SIZE 100

void printParenthesis(int pos, int n, int open, int close)
{
	static char str[MAX_SIZE];

	if (close == n)
	{
		printf("%s \n", str);
		return;
	}
	else
	{
		if (open < n)
		{
			str[pos] = '(';
			printParenthesis(pos + 1, n, open + 1, close);
		}
		// 两个if 位置颠倒, 打印出来的结果会很奇特地相反
		if (open > close)
		{
			str[pos] = ')';
			printParenthesis(pos + 1, n, open, close + 1);
		}
	}
}

int main()
{
	int n = 3;
	printParenthesis(0,n,0,0);
	getchar();
	return 0;
}
