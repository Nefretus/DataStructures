#include"BSTNode.h"
#include<iostream>


BSTNode::BSTNode() {
	new BSTNode(NULL, NULL, NULL, NULL);
}

BSTNode::BSTNode(BSTNode* parent, BSTNode* left, BSTNode* right, int value) {
	this->parent = parent;
	this->left = left;
	this->right = right;
	this->value = value;
}

BSTNode::~BSTNode() {
	
}

