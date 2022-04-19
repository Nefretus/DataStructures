#pragma once
#include"DynamicArray.h"

class BinaryHeap {
public:
	BinaryHeap();
	~BinaryHeap();
	void printArray();
	void printTree();
	void insert(int value);
	int extractMax();

private:
	DynamicArray* root;
	int size;
	void heapifyUpwards(DynamicArray* array, int index);
	void heapifyDownwards(DynamicArray* array, int index);
	int parent(int index);
	int left(int index);
	int right(int index);
};
