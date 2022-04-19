#pragma once
class BSTNode {
public:
	BSTNode();
	BSTNode(BSTNode* parent, BSTNode* left, BSTNode* right, int value);
	~BSTNode();

	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;
	int value;
};
