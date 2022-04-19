#pragma once
#include "BSTNode.h"

class BinarySearchTree {
	friend class BSTNode;

public:
	BSTNode* root;
	BinarySearchTree();
	BinarySearchTree(BSTNode* root, int size);
	~BinarySearchTree();
	void printTree(BSTNode* node, int space);
	void insert(int value);
	void deleteElement(int value);
	BSTNode* minimum(BSTNode* node);
	BSTNode* maximum(BSTNode* node);
	BSTNode* successor(BSTNode* node);
	BSTNode* findBSTNode(int value);
	BSTNode* rotateRight(BSTNode* node);
	BSTNode* rotateLeft(BSTNode* node);
	void balanceByDSW();

private:
	int size;
};


