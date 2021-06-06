/*
* @author Mirette Amin Danial	20190570
* @author Rana Ihab Ahmed Fahmy 20190207
* Created on 2/6/2021
*/


#include <iostream>
#include "BST_AVL.h"
using namespace std;

enum Traversal {
	InOrder,
	PreOrder,
	PostOrder
};

void displayTree(Traversal t, TreeNode* root) {
	if (t == InOrder) {
		if (root != nullptr) {
			displayTree(InOrder, root->left);
			cout << root->getValue() << ' ';
			displayTree(InOrder, root->right);
		}
	}
	else if (t == PreOrder) {

	}
	else if (t == PostOrder) {

	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();

	TreeNode* root = nullptr;

	root = root->insert(13);
	root = root->insert(15);
	root = root->insert(5);
	root = root->insert(16);
	root = root->insert(10);
	root = root->insert(4);
	root = root->insert(11);
	root = root->insert(8);
	root = root->insert(3);

	displayTree(InOrder, root);
	return 0;
}