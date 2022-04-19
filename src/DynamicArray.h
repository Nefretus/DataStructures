#pragma once
class DynamicArray {
public:
	DynamicArray(int* head, int length);
	DynamicArray();
	~DynamicArray();

	void printArray();
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
	void insertAt(int index, int value);
	void deleteFirstElement();
	void deleteLastElement();
	void deleteElementAt(int index);
	int findElementAt(int index);
	void overwriteValueAt(int index, int value);
	int findValueIndex(int value);
private:
	int* head;
	int length;
};
