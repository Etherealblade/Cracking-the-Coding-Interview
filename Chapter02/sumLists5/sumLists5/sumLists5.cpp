// https://github.com/Etherealblade/cracking-the-coding-interview/blob/master/cpp_solutions/chapter_02_linked_lists/problem_02_05_sumLists.h

#include <iostream>
#include "Node.h"
using namespace std;

namespace chapter_02
{
	SinglyLinkedNode<uint8_t> *sumList(
		const SinglyLinkedNode<uint8_t> *head1,
		const SinglyLinkedNode<uint8_t> *head2)
	{
		uint8_t carry = 0;
		SinglyLinkedNode<uint8_t> *outputRunner = nullptr;
		SinglyLinkedNode<uint8_t> *outputHead = nullptr;

		while (head1 != nullptr || head2!=nullptr)
		{
			// continue traversing so long as on pointer is not null
			if (outputRunner == nullptr)
			{
				// create head of output linked list
				outputRunner = new SinglyLinkedNode<uint8_t>(0);
				outputHead = outputRunner;
			}
			else
			{
				// add new node to existing list
				SinglyLinkedNode<uint8_t> *temp = 
					new SinglyLinkedNode<uint8_t>(0);
				outputRunner->setNext(temp);
				outputRunner = outputRunner->getNext();
			}

			uint8_t sum = 0;
			if (head1==nullptr)
			{
				// if head1 is null, use only head2 to compute sum
				ASSERT(head2->getValue() < 10);
				sum = head2->getValue() + carry;
				head2 = head1->getNext();
			}
			else if (head2==nullptr)
			{
				// if head2 is null use only head1 to compute sum
				ASSERT(head1->getValue() < 10);
				sum = head1->getValue() + carry;
				head1 = head1->getNext();
			}
			else
			{
				ASSERT(head1->getValue() < 10 &&
					head2->getValue() < 10);
				sum = head1->getValue() + head2->getValue() + carry;
				head1 = head1->getNext();
				head2 = head2->getNext();

			}

			carry = 0;
			if (sum>9)
			{
				// if sum is too large for 1 digit, carry over to next digit
				carry = sum / 10;
				sum = sum - 10;
			}
			outputRunner->setValue(sum);
		}

		if (carry>0)
		{
			outputRunner->setNext(
				new SinglyLinkedNode<uint8_t>((carry))
				// traversal is over but carry value still remains
			);
		}

		return outputHead;
	}
}

int main()
{

}

