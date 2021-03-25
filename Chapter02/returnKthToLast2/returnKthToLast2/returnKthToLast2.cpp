// https://github.com/Etherealblade/cracking-the-coding-interview/blob/master/cpp_solutions/chapter_02_linked_lists/problem_02_02_returnKthToLast.h

#include <iostream>
#include "Node.h"
using namespace std;

namespace chapter_02
{
	template <typename T>
	const SinglyLinkedNode<T>* returnKthToLast(
		const SinglyLinkedNode<T>* head, int k)
	{
		if (head == nullptr)
		{
			return nullptr;
		}

		const SinglyLinkedNode<T> *slowRunner = head;
		const SinglyLinkedNode<T> *fastRunner = head;

		while (k > 0)
		{
			if (fastRunner == nullptr)
			{
				return nullptr;
			}
			fastRunner = fastRunner->getNext();
			k--;
		}

		while (fastRunner != nullptr)
		{
			slowRunner = slowRunner->getNext();
			fastRunner = fastRunner->getNext();
		}

		return slowRunner;
	}
}

int main()
{
	// no test data
}
