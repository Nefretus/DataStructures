#include"BinarySearchTree.h"

#include<iostream>

#include<math.h>

#define COUNT 5
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    size = 0;
}

BinarySearchTree::BinarySearchTree(BSTNode* root, int size) {
    root = root;
    size = size;
}

BinarySearchTree::~BinarySearchTree() {

}

void BinarySearchTree::printTree(BSTNode* node, int space) {
    if (node == NULL)
        return;
    space += COUNT;
    printTree(node->right, space);
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << node->value << "\n";
    printTree(node->left, space);
}

void BinarySearchTree::insert(int value) {
    if (size == 0) {
        root = new BSTNode(NULL, NULL, NULL, value);
    }
    else {
        BSTNode* pointer = root;
        while (true) {
            int cmpValue = pointer->value;
            if (value < cmpValue) {
                if (pointer->left == NULL) {
                    pointer->left = new BSTNode(pointer, NULL, NULL, value);
                    break;
                }
                else pointer = pointer->left;
            }
            else {
                if (pointer->right == NULL) {
                    pointer->right = new BSTNode(pointer, NULL, NULL, value);
                    break;
                }
                else pointer = pointer->right;
            }
        }
    }
    size++;
}

BSTNode* BinarySearchTree::findBSTNode(int value) {
    if (size == 0) return NULL;
    else {
        BSTNode* pointer = root;
        while (pointer != NULL) {
            int cmpValue = pointer->value;
            if (cmpValue == value) return pointer;
            else if (value < cmpValue)
                pointer = pointer->left;
            else
                pointer = pointer->right;
        }
        return NULL;
    }
}

BSTNode* BinarySearchTree::minimum(BSTNode* node) {
    if (size == 0) {
        //error
        return NULL;
    }
    else {
        BSTNode* pointer = node;
        while (true) {
            if (pointer->left != NULL) pointer = pointer->left;
            else {
                break;

            }
        }
        return pointer;
    }
}

BSTNode* BinarySearchTree::maximum(BSTNode* node) {
    if (size == 0) {
        //error
        return NULL;
    }
    else {
        BSTNode* pointer = node;
        while (true) {
            if (pointer->right != NULL) pointer = pointer->right;
            else {
                break;
            }
        }
        return pointer;
    }
}

BSTNode* BinarySearchTree::successor(BSTNode* node) {
    if (node->right != NULL)
        return minimum(node->right);
    BSTNode* pointerParent = node->parent;
    while (pointerParent != NULL && node == pointerParent->right) {
        node = pointerParent;
        pointerParent = pointerParent->parent;
    }
    return pointerParent;
}

void BinarySearchTree::deleteElement(int value) {
    BSTNode* pointer = findBSTNode(value);
    if (pointer != NULL) {
        BSTNode* pointerParent = pointer->parent;
        if (pointer->left == NULL && pointer->right == NULL) {
            if (pointerParent != NULL) {
                if (pointer == pointerParent->left) pointerParent->left = NULL;
                else if (pointer == pointerParent->right) pointerParent->right = NULL;
            }
            else root = NULL;
        }
        else if (pointer->left == NULL || pointer->right == NULL) {
            BSTNode* pointerSon;
            if (pointer->right == NULL) pointerSon = pointer->left;
            else pointerSon = pointer->right;
            pointerSon->parent = pointerParent;
            if (pointerParent != NULL) {
                if (pointerParent->left == pointer) pointerParent->left = pointerSon;
                else pointerParent->right = pointerSon;
            }
            else root = pointerSon;
        }
        else {
            BSTNode* toReplace = pointer;
            BSTNode* pointerSuccessor = successor(pointer);
            int pointerSuccessorValue = pointerSuccessor->value;
            if (pointerSuccessor->left != NULL)
                pointer = pointerSuccessor->left;
            else pointer = pointerSuccessor->right;
            if (pointer != NULL) pointer->parent = pointerSuccessor->parent;
            if (pointerSuccessor->parent == NULL) root = pointer;
            else if (pointerSuccessor == pointerSuccessor->parent->left) pointerSuccessor->parent->left = pointer;
            else pointerSuccessor->parent->right = pointer;
            toReplace->value = pointerSuccessorValue;
        }
    }
    size--;
    delete pointer;
}

BSTNode* BinarySearchTree::rotateRight(BSTNode* node) {
    BSTNode* pointer = node;
    BSTNode* pointerSon = pointer->left;
    BSTNode* pointerParent = pointer->parent;
    if (pointerParent != NULL) {
        if (pointerParent->left == pointer) pointerParent->left = pointerSon;
        else pointerParent->right = pointerSon;
    }
    pointerSon->parent = pointerParent;
    if (pointerSon->right != NULL) pointerSon->right->parent = pointer;
    pointer->left = pointerSon->right;
    pointerSon->right = pointer;
    pointer->parent = pointerSon;
    if (root == pointer) root = pointerSon;
    return pointerSon;
}

BSTNode* BinarySearchTree::rotateLeft(BSTNode* node) {
    BSTNode* pointer = node;
    BSTNode* pointerSon = pointer->right;
    BSTNode* pointerParent = pointer->parent;
    if (pointerParent != NULL) {
        if (pointerParent->left == pointer) pointerParent->left = pointerSon;
        else pointerParent->right = pointerSon;
    }
    pointerSon->parent = pointerParent;
    if (pointerSon->left != NULL) pointerSon->left->parent = pointer;
    pointer->right = pointerSon->left;
    pointerSon->left = pointer;
    pointer->parent = pointerSon;
    if (root == pointer) root = pointerSon;
    return pointerSon;
}

void BinarySearchTree::balanceByDSW() {
    if (size == 0) {
        //error
    }
    else {
        BSTNode* pointer = root;
        while (pointer != NULL) {
            if (pointer->left != NULL)
                pointer = rotateRight(pointer);
            else pointer = pointer->right;
        }
        int rotationsNum = (int)pow(2, (floor(log2((double)(size + 1))))) - 1;
        printTree(root, 0);
        pointer = root;
        for (int i = 0; i < size - rotationsNum; i++) {
            pointer = rotateLeft(pointer);
            pointer = pointer->right;
            printTree(root, 0);
        }
        while (rotationsNum > 1) {
            pointer = root;
            rotationsNum = floor(rotationsNum / 2);
            for (int i = 0; i < rotationsNum; i++) {
                pointer = rotateLeft(pointer);
                pointer = pointer->right;
            }
        }
    }
}