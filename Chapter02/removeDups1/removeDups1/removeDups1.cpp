// https://github.com/Etherealblade/cracking-the-coding-interview/blob/master/cpp_solutions/chapter_02_linked_lists/problem_02_01_removeDups.h
// I don't get the point of the question

#include <iostream>
#include <unordered_map>
#include "Node.h"
using namespace std;

namespace chapter_02
{
	template <typename T>
	void removeDups(SinglyLinkedNode<T>* head)	// had never seen code like this
	{
		SinglyLinkedNode<T> *slowRunner = head;

		if (slowRunner == nullptr ||
			slowRunner->getNext() == nullptr)
		{
			return;	// a list of length 0 or 1 cannot have dups
		}

		SinglyLinkedNode<T> *fastRunner = slowRunner->getNext();
		unordered_map<T, bool> hashTable;
		hashTable[slowRunner->getNext()] = true;

		while (fastRunner != nullptr)
		{
			if (hashTable.count(fastRunner->getNext()))
			{
				slowRunner->setNext(fastRunner->getNext());
				fastRunner->setNext(nullptr);
				delete fastRunner;
				fastRunner = slowRunner->getNext();
			}
			else
			{
				hashTable[fastRunner->getNext()] = true;
				slowRunner = fastRunner;
				fastRunner = fastRunner->getNext();
			}
		}
	}
}

int main()
{
	// no test data

}
