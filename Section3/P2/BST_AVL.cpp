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
	return nullptr;
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

TreeNode* TreeNode::deleteNode()
{
	return nullptr;
}


