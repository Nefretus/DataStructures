#include "DynamicArray.h"
#include<iostream>
#include<string>

DynamicArray::DynamicArray(int* head, int length) {
	head = head;
	length = length;
}

DynamicArray::DynamicArray() {
	head = NULL;
	length = 0;
}

DynamicArray::~DynamicArray() {
	delete[] head;
}

void DynamicArray::printArray() {
	std::cout << "DynamicArray = {";
	for(int i = 0; i < length; i++)
	{
		std::cout << *(head + i);
		if(i + 1 != length)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

void DynamicArray::insertAtBeginning(int value) {
	if(length == 0) {
		head = new int[1];
	}
	else {
		int* pointer = new int[length + 1];
		memcpy(pointer + 1, head, length * sizeof(int));
		delete[] head;
		head = pointer;
	}
	*head = value;
	length++;
}

void DynamicArray::insertAtEnd(int value) {
	if(length == 0) {
		head = new int[1];
		*head = value;
	}
	else {
		int* pointer = new int[length + 1];
		memcpy(pointer, head, length * sizeof(int));
		delete[] head;
		*(pointer + length) = value;
		head = pointer;
	}
	length++;
}

void DynamicArray::insertAt(int index, int value) {
	if(index < 0 || index > length) {
		//error
	}
	else if (length == 0) {
		head = new int[1];
		*head = value;
		length++;
	}
	else {
		int* pointer = new int[length + 1];
		memcpy(pointer, head, index * sizeof(int));
		*(pointer + index) = value;
		memcpy(pointer + index + 1, head + index, (length - index)*sizeof(int));
		delete[] head;
		head = pointer;
		length++;
	}
}

void DynamicArray::deleteFirstElement() {
	if(length == 0) {
		//error
	}
	else {
		int* pointer = new int[length - 1];
		memmove(pointer, head + 1, (length - 1) * sizeof(int));
		delete[] head;
		head = pointer;
		length--;
	}
}

void DynamicArray::deleteLastElement() {
	if(length == 0) {
		// error
	}
	else {
		int* pointer = new int[length - 1];
		memmove(pointer, head, (length - 1) * sizeof(int));
		delete[] head;
		head = pointer;
		length--;
	}
}

void DynamicArray::deleteElementAt(int index) {
	if(index < 0 || index >= length) {
		//error
	}
	else {
		int* pointer = new int[length - 1];
		memcpy(pointer, head, index * sizeof(int));
		memcpy(pointer + index, head + index + 1, (length - index)*sizeof(int));
		delete[] head;
		head = pointer;
		length--;
	}
}

int DynamicArray::findElementAt(int index) {
	if(index < 0 || index >= length) 
		return NULL;
	else
		return *(head + index);
	
}

void DynamicArray:: overwriteValueAt(int index, int value)
{
	if(index < 0 || index >= length) {
		//error
	}
	else {
		*(head + index) = value;
	}
}
