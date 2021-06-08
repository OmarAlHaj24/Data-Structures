/*
* @author Mirette Amin Danial	20190570
* @author Rana Ihab Ahmed Fahmy 20190207
* Created on 2/6/2021
*/

#include<iostream>
#include "BST_AVL.h"

TreeNode::TreeNode(int v) : value(v), height(0), right(nullptr), left(nullptr) {}

int TreeNode::getBalance() {
	if (this != nullptr)
		return this->left->getHeight() - this->right->getHeight();
	return 0;
}

TreeNode* TreeNode::rotateRight() {
	TreeNode* newNode = this->left;
	TreeNode* tempR = newNode->right;

	newNode->right = this;
	this->left = tempR;

	this->height = std::max(this->right->height, this->left->height) + 1;
	newNode->height = std::max(newNode->right->height, newNode->left->height) + 1;

	return newNode;
}

TreeNode* TreeNode::rotateLeft() {
	TreeNode* node = this->right;
	TreeNode* temp = node->left;
	node->left = this;
	this->right = temp;
	this->height = std::max(this->right->height, this->left->height) + 1;
	node->height = std::max(node->right->height, node->left->height) + 1;
	return node;
}

int TreeNode::getValue() {
	if (this == nullptr)
		return NULL;
	return this->value;
}

int TreeNode::getHeight() {
	if (this == nullptr)
		return 0;
	return this->height;
}

void TreeNode::setValue(int v) {
	this->value = v;
}

void TreeNode::setHeight(int h) {
	this->height = h;
}

TreeNode* TreeNode::insert(int data) {
	if (this == nullptr)
		return (new TreeNode(data));

	if (this->value > data)
		this->left = this->left->insert(data);
	else if (this->value < data)
		this->right = this->right->insert(data);
	else
		return this; //No equal nodes

	this->setHeight(std::max(this->right->getHeight(), this->left->getHeight()) + 1);
	int balance = this->getBalance();

	if (balance > 1) {
		//Left Left Case
		if (data < this->left->getValue())
			return this->rotateRight();

		//Left Right Case
		if (data > this->left->getValue()) {
			this->left = this->left->rotateLeft();
			return this->rotateRight();
		}
	}
	else if (balance < -1) {
		//Right Right Case
		if (data > this->left->getValue()) {
			return this->rotateLeft();
		}

		//Right Left Case
		if (data < this->left->getValue()) {
			this->right = this->right->rotateRight();
			return this->rotateLeft();
		}
	}

	return this;
}

TreeNode* TreeNode::deleteNode(int data)
{
	if (this == 0)
		return this;
	if (data < value)
		this->left = this->left->deleteNode(data);
	else if (data > value)
		this->right = this->right->deleteNode(data);
	else {
		TreeNode* temp;
		if (this->right == 0 || this->left == 0) {
			if (this->right == 0)
				temp = this->left;
			else
				temp = this->right;
			if (temp == 0) {
				temp = this;
				*this = 0;
				delete temp;
			}
			else {
				this->value = temp->value;
				this->right = temp->right;
				this->left = temp->left;
				delete temp;
			}
		}
		else {
			temp = this->left;
			while (temp->right != 0) {
				temp = temp->right;
			}
			this->value = temp->value;
			this->left = this->left->deleteNode(temp->value);
		}
	}

	if (this == 0)
		return this;
	this->setHeight(std::max(this->right->getHeight(), this->left->getHeight()) + 1);
	int balance = this->getBalance();
	if (balance > 1 && this->left->getBalance() >= 0) {
		return this->rotateRight();
	}
	if (balance > 1 && this->left->getBalance() < 0) {
		this->left = this->left->rotateLeft();
		return this->rotateRight();
	}
	if (balance < -1 && this->right->getBalance() <= 0) {
		return this->rotateLeft();
	}
	if (balance < -1 && this->right->getBalance() > 0) {
		this->right = this->right->rotateRight();
		return this->rotateLeft();
	}
	return this;
}


