/*
* @author Mirette Amin Danial	20190570
* @author Rana Ihab Ahmed Fahmy 20190207
* Created on 2/6/2021
*/

#include<iostream>
#include "BST_AVL.h"

TreeNode::TreeNode(int v) : value(v), height(1), right(nullptr), left(nullptr) {}

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

	this->height = std::max(this->right->getHeight(), this->left->getHeight()) + 1;
	newNode->height = std::max(newNode->right->getHeight(), newNode->left->getHeight()) + 1;

	return newNode;
}

TreeNode* TreeNode::rotateLeft() {
	TreeNode* node = this->right;
	TreeNode* temp = node->left;
	node->left = this;
	this->right = temp;
	this->height = std::max(this->right->getHeight(), this->left->getHeight()) + 1;
	node->height = std::max(node->right->getHeight(), node->left->getHeight()) + 1;
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