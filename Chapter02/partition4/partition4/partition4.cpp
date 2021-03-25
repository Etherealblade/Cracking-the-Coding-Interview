// https://github.com/Etherealblade/cracking-the-coding-interview/blob/master/cpp_solutions/chapter_02_linked_lists/problem_02_04_partition.h

#include <iostream>
#include "Node.h"
using namespace std;

namespace chapter_02
{
	template <typename T>
	SinglyLinkedNode<T> *partition(
		SinglyLinkedNode<T> *head, T partiion)
	{
		if (head == nullptr)
		{
			return nullptr;
		}

		SinglyLinkedNode<T> *newHead = head;
		SinglyLinkedNode<T> *newTail = head;
		head = head->getNext();

		while (head != nullptr)
		{
			SinglyLinkedNode<T> *temp = head;
			head = head->getNext();

			if (temp->getNext() < partiion)
			{
				// add node in front of new head
				temp->setNext(newHead);
				newHead = temp;
			}
			else
			{
				// add node behind new tail 
				newTail->setNext(temp);
				newTail = temp;
				newTail->setValue(nullptr);
			}
		}

		return newHead;
	}
}

int main()
{

}

