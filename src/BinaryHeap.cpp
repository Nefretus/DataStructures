#include"BinaryHeap.h"
#include<iostream>
#include<math.h>

BinaryHeap::BinaryHeap() {
    root = new DynamicArray();
    size = 0;
}

BinaryHeap::~BinaryHeap() {
    delete root;
}

int BinaryHeap::parent(int index) {
    return floor((index - 1) / 2);
}

int BinaryHeap::right(int index) {
    return 2 * (index + 1);
}

int BinaryHeap::left(int index) {
    return 2 * (index + 1) - 1;
}

void BinaryHeap::printArray() {
    for (int i = 0; i < size; i++) {
        std::cout << root->findElementAt(i) << " ";
    }
    std::cout << std::endl;
}

void BinaryHeap::printTree() {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            for (int j = 0; j < 5; j++) std::cout << " ";
            std::cout << root->findElementAt(i);
            std::cout << std::endl;
        }
        else if (i <= 2) {
            for (int j = 0; j < 3; j++) std::cout << " ";
            std::cout << root->findElementAt(i);
            if (i == 2) std::cout << std::endl;
        }
        else if (i <= 6) {
            for (int j = 0; j < 1; j++) std::cout << " ";
            std::cout << root->findElementAt(i);
            if (i == 6) std::cout << std::endl;
        }
    }
}

void BinaryHeap::heapifyUpwards(DynamicArray* array, int index) {
    if (index > 0) {
        int parentValue = array->findElementAt(parent(index));
        int value = array->findElementAt(index);
        if (parentValue < value) {
            array->overwriteValueAt(parent(index), value);
            array->overwriteValueAt(index, parentValue);
            this->heapifyUpwards(root, parent(index));
        }
    }
}

void BinaryHeap::heapifyDownwards(DynamicArray* array, int index) {
    int largest = index, largestValue = array->findElementAt(index);
    if (left(index) < size) {
        int leftValue = array->findElementAt(left(index));
        if (leftValue > largestValue) {
            largest = left(index);
            largestValue = leftValue;
        }
    }
    if (right(index) < size) {
        int rightValue = array->findElementAt(right(index));
        if (rightValue > largestValue) {
            largest = right(index);
            largestValue = rightValue;
        }
    }
    if (largest != index) {
        array->overwriteValueAt(largest, array->findElementAt(index));
        array->overwriteValueAt(index, largestValue);
        heapifyDownwards(array, largest);
    }
}

void BinaryHeap::insert(int value) {
    root->insertAtEnd(value);
    heapifyUpwards(root, size);
    size++;
}

int BinaryHeap::extractMax() {
    if (size == 0) {
        //error
        return NULL;
    }
    else {
        int max = root->findElementAt(0);
        if (size == 1) {
            root->deleteFirstElement();
            size--;
            return max;
        }
        else {
            int lastElementValue = root->findElementAt(size - 1);
            root->overwriteValueAt(0, lastElementValue);
            root->deleteLastElement();
            size--;
            heapifyDownwards(root, 0);
            return max;
        }
    }
}