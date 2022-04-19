#include"Node.h"

Node::Node()
{
	new Node(NULL, NULL, NULL);
}

Node::Node(Node* previous, Node* next, int value)
{
	this->previous = previous;
	this->next = next;
	this->value = value;
}

Node::~Node()
{
	
}
