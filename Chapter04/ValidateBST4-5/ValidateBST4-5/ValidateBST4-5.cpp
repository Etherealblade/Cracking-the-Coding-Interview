/*
https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
Mind the incorrect method.
Method 2 is very easy to understand.
But I left question in method 3 at line 54
*/

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	/* Constructor that allocates
	a new node with the given data
	and NULL left and right pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. 

Method 3
*/
int isBSTUtil1(node *node, int min, int max)
{
	// An empty tree is BST
	if (node == NULL)
	{
		return 1;
	}

	/* false if this node violates
	the min/max constraint */
	if (node->data < min || node->data > max)
		return 0;

	/* otherwise check the subtrees recursively,
	tightening the min or max constraint */
	return isBSTUtil1(node->left,
		min, node->data - 1) && // Allow only distinct values  
		isBSTUtil1(node->right,
			node->data + 1, max); // Allow only distinct values  
	// 此处为何要＋1, 或-1?
	// min 和 max 又是在何处更新?
}


int main()
{
	node *root = new node(4);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(3);

	if (isBSTUtil1(root, INT_MIN, INT_MAX))
		cout << "Is BST";
	else
		cout << "Not a BST";
}
