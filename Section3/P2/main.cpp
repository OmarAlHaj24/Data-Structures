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
		if (root != nullptr) {
			cout << root->getValue() << ' ';
			displayTree(InOrder, root->left);
			displayTree(InOrder, root->right);
		}

	}
	else if (t == PostOrder) {
		if (root != nullptr) {
			displayTree(InOrder, root->left);
			displayTree(InOrder, root->right);
			cout << root->getValue() << ' ';
		}

	}
}

TreeNode* insert(TreeNode* node, int data) {
	if (node == nullptr)
		return (new TreeNode(data));

	if (node->getValue() > data)
		node->left = insert(node->left, data);
	else if (node->getValue() < data)
		node->right = insert(node->right, data);
	else
		return node; //No equal nodes

	node->setHeight(std::max(node->right->getHeight(), node->left->getHeight()) + 1);
	int balance = node->getBalance();

	if (balance > 1) {
		//Left Left Case
		if (data < node->left->getValue())
			return node->rotateRight();

		//Left Right Case
		if (data > node->left->getValue()) {
			node->left = node->left->rotateLeft();
			return node->rotateRight();
		}
	}
	else if (balance < -1) {
		//Right Right Case
		if (data > node->right->getValue()) {
			return node->rotateLeft();
		}

		//Right Left Case
		if (data < node->right->getValue()) {
			node->right = node->right->rotateRight();
			return node->rotateLeft();
		}
	}

	return node;
}

TreeNode* deleteNode(TreeNode* node, int data)
{
	if (node == nullptr)
		return node;
	if (data < node->getValue())
		node->left = deleteNode(node->left, data);
	else if (data > node->getValue())
		node->right = deleteNode(node->right, data);
	else
	{
		if ((node->left == nullptr) && (node->right == nullptr)) {
			delete node;
			node = nullptr;
		}

		else if (node->left == nullptr) {
			node = node->right;
		}
		else if (node->right == nullptr) {
			node = node->left;
		}
		else
		{
			TreeNode* temp = node->left;
			while (temp->right != nullptr)
				temp = temp->right;

			node->setValue(temp->getValue());
			node->left = deleteNode(node->left, temp->getValue());
		}
	}

	if (node == nullptr)
		return node;

	node->setHeight(std::max(node->right->getHeight(), node->left->getHeight()) + 1);
	int balance = node->getBalance();

	//Rotation Cases
	if (balance > 1) {
		//Left Left Case
		if (node->left->getBalance() >= 0)
			return node->rotateRight();

		//Left Right Case
		if (node->left->getBalance() < 0) {
			node->left = node->left->rotateLeft();
			return node->rotateRight();
		}
	}
	else if (balance < -1) {
		//Right Right Case
		if (node->right->getBalance() <= 0) {
			return node->rotateLeft();
		}

		//Right Left Case
		if (node->right->getBalance() > 0) {
			node->right = node->right->rotateRight();
			return node->rotateLeft();
		}

	}
	return node;
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();

	TreeNode* root = nullptr;

	root = insert(root, 15);
	root = insert(root, 20);
	root = insert(root, 24);
	root = insert(root, 10);
	root = insert(root, 13);
	root = insert(root, 7);
	root = insert(root, 30);
	root = insert(root, 36);
	root = insert(root, 25);
	root = deleteNode(root, 24);
	root = deleteNode(root, 20);
	displayTree(PreOrder, root);
	return 0;
}