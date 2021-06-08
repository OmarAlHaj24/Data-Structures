/*
* @author Mirette Amin Danial	20190570
* @author Rana Ihab Ahmed Fahmy 20190207
* Created on 2 / 6 / 2021
*/

#pragma once
#ifndef BST_AVL_H
#define	BST_AVL_H

class TreeNode
{
private:
	int value, height;
public:

	TreeNode* left;
	TreeNode* right;
	TreeNode(int v);

	int getValue();
	int getHeight();
	void setValue(int v);
	void setHeight(int h);

	int getBalance();

	TreeNode* rotateRight();
	TreeNode* rotateLeft();

};

#endif // !BST_AVL_H




