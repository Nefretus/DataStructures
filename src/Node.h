#include<iostream>
#include<string.h>

using namespace std;

class Node
{
	friend class DoublyLinkedList;
private:
	Node* previous;
	Node* next;
	int value;

public:
	Node();
	Node(Node* previous, Node* next, int value);
	~Node();
};
