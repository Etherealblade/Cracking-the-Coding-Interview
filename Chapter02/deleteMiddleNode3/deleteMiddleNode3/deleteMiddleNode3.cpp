// https://github.com/Etherealblade/cracking-the-coding-interview/blob/master/cpp_solutions/chapter_02_linked_lists/problem_02_03_deleteMiddleNode.h
// So far, i learn that there is no need to focus on DS

#include <iostream>
#include "Node.h"
using namespace std;

namespace chapter_02 {
	template <typename T>
	void deleteMiddleNode(SinglyLinkedNode<T>* middle) {
		if (middle == nullptr || middle->getNext() == nullptr) 
		{
			return; // given node is not in the middle. do nothing.
		}
		SinglyLinkedNode<T>* next = middle->getNext();
		middle->setValue(next->getValue());
		middle->setNext(next->getNext());
		delete next;
	}
}

int main()
{

}

