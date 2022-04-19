#include "DoublyLinkedList.h"
#include<string>
#include<iostream>

DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
	while(--size > 0) {
		Node* pointer;
		pointer = head;
		head = pointer->next;
		delete pointer;
	}
	delete head;
}

void DoublyLinkedList::printList() {
	std::cout << "DoblyLinkedList" << std::endl;
	std::cout << "{";
	Node* pointer = head;
	for(int i = 0; i < size; i++) {
		std::cout << pointer->value;
		if(i + 1 != size)
			std::cout << ", ";
		pointer = pointer->next;
	}
	std::cout << "}" << endl;
}

void DoublyLinkedList::insertAtBeginning(int value) {
	if(size == 0) {
		head = new Node(NULL, NULL, value);
	}
	else {
		head->previous = new Node(NULL, head, value);
		head = head->previous;
	}
	size++;
}

void DoublyLinkedList::insertAtEnd(int value) {
	if(size == 0) {
		head = new Node(NULL, NULL, value);
	}
	else {
		Node* pointer = head;
		for(int i = 0; i < size - 1; i++)
		{
			pointer = pointer->next;
		}
		pointer->next = new Node(pointer, NULL, value);
	}
	size++;
}

void DoublyLinkedList::insertAt(int index, int value) {
	if(index < 0 || index > size) {
		//error
	}
	else if(size == 0) {
		head = new Node(NULL, NULL, value);
		size++;
	}
	else {
		if(index == 0) {
			insertAtBeginning(value);
		}
		else {
			Node* pointer = head;
			for(int i = 0; i < index - 1; i++)
			{
				pointer = pointer->next;
			}
			Node* inserted = new Node(pointer, pointer->next, value);
			if(pointer->next != NULL) pointer->next->previous = inserted;
			pointer->next = inserted;
			size++;
		}
	}
}

void DoublyLinkedList::deleteFirstElement() {
	if(size == 0) {
		//error
	}
	else {
		Node* pointer = head;
		if(head->next != NULL) {
			head = head->next;
			head->previous = NULL;
		}
		else head = NULL;
		delete pointer;
		size--;
	}
}

void DoublyLinkedList::deleteLastElement() {
	if(size == 0) {
		//error
	}
	else {
		Node* pointer = head;
		for(int i = 0; i < size - 1; i++) {
			pointer = pointer->next;
		}
		if(pointer->previous != NULL) {
			pointer->previous->next = NULL;
		}
		else head = NULL;
		delete pointer;
		size--;
	}
}

void DoublyLinkedList::deleteElementAt(int index) {
	if(index < 0 || index >= size) {
		//error
	}
	else if(size == 0) {
		//error
	}
	else {
		if(index == 0) 
			deleteFirstElement();
		else {
			Node* pointer = head;
			for(int i = 0; i < index; i++) {
				pointer = pointer->next;
			}
			pointer->previous->next = pointer->next;
			if(pointer->next != NULL) pointer->next->previous = pointer->previous;
			delete pointer;
			size--;
		}
	}
}

int DoublyLinkedList::findElementAt(int index) {
	if(index < 0 || index >= size) {
		//error
		return NULL;
	}
	else if(size == 0) {
		//error
		return NULL;
	}
	else {
		Node* pointer = head;
		for(int i = 0; i < index; i++)
		{
			pointer = pointer->next;
		}
		return pointer->value;
	}
}


