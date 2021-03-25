/*
https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
refer to 
.\Competitive Programming\Chapter02\PartialSum214\PartialSum214
This one is NP-complete
*/


#include <iostream>
#include <vector>
using namespace std;

// binary tree node 
struct Node
{
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

void printVector(const vector<int>& v, int i)
{
	for (int j = i; j < v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}

// This function prints all paths that have sum k 
void printKPath(Node *root, vector<int>& path,
	int k)
{
	// empty node 
	if (!root)
		return;

	// add current node to the path 
	path.push_back(root->data);

	// check if there's any k sum path 
	// in the left sub-tree. 
	printKPath(root->left, path, k);

	// check if there's any k sum path 
	// in the right sub-tree. 
	printKPath(root->right, path, k);

	// check if there's any k sum path that 
	// terminates at this node 
	// Traverse the entire path as 
	// there can be negative elements too 
	int f = 0;
	for (int j = path.size() - 1; j >= 0; j--)
	{
		f += path[j];

		// If path sum is k, print the path 
		if (f == k)
			printVector(path, j);
	}

	// Remove the current element from the path 
	path.pop_back();
}



int main()
{
	Node *root = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(1);
	root->left->right->left = new Node(1);
	root->right = new Node(-1);
	root->right->left = new Node(4);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(2);

	int k = 5;
	vector<int> path;
	printKPath(root, path, k);

	return 0;
}

