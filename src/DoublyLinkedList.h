#pragma once
#include"Node.h"

class DoublyLinkedList {
friend class Nodes;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void printList();
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
	void insertAt(int index, int value);
	void deleteFirstElement();
	void deleteLastElement();
	void deleteElementAt(int index);
	int findElementAt(int index);
private:
	Node* head;
	int size;
};
