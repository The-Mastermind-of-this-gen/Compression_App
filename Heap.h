#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <new>
#pragma once
using namespace std;

// ===== Error Codes Enum =====
enum ErrorCodes {
    HEAP_OVERFLOW = -2,
    HEAP_NOT_INITIALIZED = -1,
    HEAP_UNDERFLOW = 0
};

// ===== Max Heap Template =====
template<typename Input>
class Heap {
public:
    Input* arr;
    int size;  // Array Size
    int count;
    int BlockSize;// Number of elements in the heap
    Heap() {
        arr = NULL;
        count = 0;
        size = 0;
        BlockSize = 100;
    }

    ~Heap() {
        delete[] arr;
    }

    bool initialize(int sz) {
        if (sz <= 0)
            return false;

        if (arr != NULL)
            delete[] arr;

        arr = new(nothrow) Input[sz];
        if (arr == NULL)
            return false;

        size = sz;
        BlockSize = sz;
        return true;
    }

    void HeapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && arr[parentIndex].BitFreq < arr[index].BitFreq) {
            Input temp = arr[index];
            arr[index] = arr[parentIndex];
            arr[parentIndex] = temp;
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    void HeapifyDown() {
        int parentIndex = 0;
        while (true) {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int largestChildIndex;

            if (leftChildIndex >= count)
                break;

            if (rightChildIndex < count && arr[rightChildIndex].BitFreq > arr[leftChildIndex].BitFreq)
                largestChildIndex = rightChildIndex;
            else
                largestChildIndex = leftChildIndex;

            if (arr[parentIndex].BitFreq >= arr[largestChildIndex].BitFreq)
                break;

            Input temp = arr[largestChildIndex];
            arr[largestChildIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = largestChildIndex;
        }
    }

    bool isFull() {
        return count == size;
    }

    bool isEmpty() {
        return count == 0;
    }

    int insert(Input NewTreeNode) {
        if (arr == NULL)
            return HEAP_NOT_INITIALIZED;

        if (isFull())
            Array_Resize();

        arr[count] = NewTreeNode;
        HeapifyUp(count);
        count++;
        return 1;
    }

    int DeleteValue(Input* d = NULL) {
        if (arr == NULL)
            return HEAP_NOT_INITIALIZED;

        if (isEmpty())
            return HEAP_UNDERFLOW;

        if (d != NULL)
            *d = arr[0];
            

        arr[0] = arr[count - 1];
        count--;
        HeapifyDown();
        return 1;
    }
    void Array_Resize() 
    {
        Input* temp = new(nothrow) Input[count+BlockSize];
        if (temp == NULL)
            return;
        for (int i=0;i<count;i++) 
        {
            temp[i] = arr[i];
        }
        delete[]arr;
        arr = temp;
        size = count + BlockSize;
        return;
    }
};
