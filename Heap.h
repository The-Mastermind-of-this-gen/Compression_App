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

// ===== Min Heap Template =====
template<typename Input>
class Heap {
private:
    Input* arr;
    int count; // number of elements in the heap
    int size;

public:
    Heap() {
        arr = NULL;
        count = 0;
        size = 0;
    }

    ~Heap() {
        delete[] arr;
    }

    bool initialize(int sz) {
        if (sz <= 0)
            return false;

        if (arr != nullptr)
            delete[] arr;

        arr = new(nothrow) Input[sz];
        if (arr == nullptr)
            return false;

        size = sz;
        return true;
    }

    void HeapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && arr[parentIndex].BitFreq > arr[index].BitFreq) {
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
            int smallestChildIndex;

            if (leftChildIndex >= count)
                break;

            if (rightChildIndex < count && arr[rightChildIndex].BitFreq < arr[leftChildIndex].BitFreq)
                smallestChildIndex = rightChildIndex;
            else
                smallestChildIndex = leftChildIndex;

            if (arr[parentIndex].BitFreq <= arr[smallestChildIndex].BitFreq)
                break;

            Input temp = arr[smallestChildIndex];
            arr[smallestChildIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = smallestChildIndex;
        }
    }

    bool isFull() {
        return count == size;
    }

    bool isEmpty() {
        return count == 0;
    }

    int insert(Input num) {
        if (arr == nullptr)
            return HEAP_NOT_INITIALIZED;

        if (isFull())
            return HEAP_OVERFLOW;

        arr[count] = num;
        HeapifyUp(count);
        count++;
        return 1;
    }

    int DeleteValue(Input* d = NULL) {
        if (arr == NULL)
            return HEAP_NOT_INITIALIZED;

        if (isEmpty())
            return HEAP_UNDERFLOW;

        if (d == Input{})
            return 0;

        *d = arr[0];
        arr[0] = arr[count - 1];
        count--;
        HeapifyDown();
        return 1;
    }
};
