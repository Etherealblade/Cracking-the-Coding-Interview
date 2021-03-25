// https://github.com/Etherealblade/cracking-the-coding-interview/blob/master/cpp_solutions/chapter_02_linked_lists/problem_02_06_palindrome.h
// I want an illustration with figure as in CLRS

#include <iostream>
#include "Node.h"
using namespace std;

namespace chapter_02
{
	template <typename T>
	bool palindrome(const SinglyLinkedNode<T> *head)
	{
		const SinglyLinkedNode<T> * runner = head;
		int count = 0;
		while (runner != nullptr)
		{
			count++;
			runner = runner->getNext();
		}

		int halfLen = count / 2;
		SinglyLinkedNode<T> *revHead =
			new SinglyLinkedNode<T>(head->getValue());	
		runner = head;

		for (int i = 0; i < halfLen; i++)
		{
			// create a list that is reverse of first half of input list
			runner = runner->getNext();
			SinglyLinkedNode<T> *temp =
				new SinglyLinkedNode<T>(runner->getValue(), revHead);

		}

		runner = runner->getNext();
		if (count % 2 != 0)
		{
			runner = runner->getNext();
		}
		while (runner != nullptr &&
			revHead != nullptr)
		{
			// traverse second half of input list simultaneously with reversed list
			if (runner->getValue() != revHead->getValue())
			{
				return false;
			}

			runner = runner->getNext();
			revHead = revHead->getNext();
		}
		return true;
	}
}

int main()
{

}
