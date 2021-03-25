// https://github.com/Etherealblade/cracking-the-coding-interview/blob/master/cpp_solutions/chapter_02_linked_lists/problem_02_07_intersection.h

#include <iostream>
#include "Node.h"
using namespace std;

namespace chapter_02
{
	template <typename T>
	const SinglyLinkedNode<T> *intersection(
		const SinglyLinkedNode<T> *head1,
		const SinglyLinkedNode<T> *head2)
	{
		const SinglyLinkedNode<T> *runner1 = head1;
		const SinglyLinkedNode<T>* runner2 = head2;
		int length1 = 0;
		int length2 = 0;

		while (runner1 != nullptr)
		{
			// advance pointer 1 to end and compute list size
			runner1 = runner1->getNext();
			length1++;

		}

		while (runner2 != nullptr)
		{
			// advance pointer 2 to end and compute list size
			runner2 = runner2->getNext();
			length2++;
		}

		if (runner1 != runner2)
		{
			// if the lists don't intersect at all
			return nullptr;
		}

		int sizeDiff = length1 - length2;
		const SinglyLinkedNode<T> *larger = nullptr;
		const SinglyLinkedNode<T> *smaller = nullptr;
		if (sizeDiff > 0)
		{
			larger = head1;
			smaller = head2;
		}
		else
		{
			larger = head2;
			smaller = head1;
			sizeDiff = sizeDiff * (-1);
		}

		while (sizeDiff > 0)
		{
			// advance pointer for larger list to be "equal" to smaller list
			larger = larger->getNext();
			sizeDiff--;
		}
		while (larger != smaller)
		{
			larger = larger->getNext();
			smaller = smaller->getNext();
		}

		return smaller;
	}
}

int main()
{

}

