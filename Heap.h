#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <new>
#pragma once
using namespace std;

template<typename Input>
struct linkedListNode 
{
    Input data;
    linkedListNode* Next;
    linkedListNode() 
    {
        data = Input{};
        Next = NULL;
    }
};
template<typename Input>
class linkedList 
{
    linkedListNode<Input>* Header;
public:
    linkedList() 
    {
        Header = NULL;
    }
    ~linkedList() 
    {
        if (Header == NULL)
            return;
        linkedListNode<Input>* it = Header;
        while (Header != NULL) 
        {
            Header = Header->Next;
            delete it;
            it = Header;
        }
    }
    void DeleteLinkedListNode(Input data)
    {
        if (Header == NULL)
            return;
        if (Header->Next == NULL)
            if (Header->data == data)
            {
                delete Header;
                Header = NULL;
                return;
            }
            else if (Header->data != data) 
            {
                return;
            }

        linkedListNode<Input>* it = Header;
        while (it->Next != NULL && it->Next->                                   data != data)
        {
            if (it->Next == NULL && it->data != data)
                return;
            else if (it->Next == NULL && it->data == data)
                break;
            it = it->Next;
        }
        linkedListNode<Input>* temp = it->Next;
        it->Next = it->Next->Next;
        delete temp;
        temp = NULL;
        return;
    }
    void Insert(Input data)
    {
        linkedListNode<Input>* temp = new linkedListNode<Input>();
        temp->data = data;
        if (Header == NULL)
        {
            Header = temp;
            return;
        }
        temp->Next = Header;
        Header = temp;
        SortLinkedList();
        return;

    }
    void SortLinkedList()
    {
        if (Header == NULL || Header->Next == NULL)
            return;

    }
};

template<typename Input>
struct TreeNode
{
    Input data;
    TreeNode* Next;
    int BitFreq;
    Node()
    {
        data = Input{};
        TreeNext = NULL;
        BitFreq = 0;
    }
};

enum ErrorCodes
{
    HEAP_OVERFLOW = -2,
    HEAP_NOT_INITIALIZED = -1,
    HEAP_UNDERFLOW = 0
};
template<typename Input>
class Heap
{
private:
    int* arr;
    int count; // number of elements in the heap
    int size;
public:
    Heap()
    {
        arr = nullptr;
        count = 0;
        size = 0;
    }
    ~Heap()
    {
        delete[] arr;
    }
    bool initialize(int sz)
    {
        if (sz <= 0)
            return false;
        if (arr != nullptr)
            delete[] arr;
        arr = new(nothrow)int[sz];

        if (arr == nullptr)
            return false;
        else
            size = sz;
        return true;
    }
    void HeapifyUp(int index)
    {
        int parentIndex = (index - 1) / 2;
        while (index > 0)
        {
            if (arr[parentIndex] > arr[index])
            {
                int temp = arr[index];
                arr[index] = arr[parentIndex];
                arr[parentIndex] = temp;
                index = parentIndex;
                parentIndex = (index - 1) / 2;
            }
            else
                break;
        }
    }
    bool isFull()
    {
        return count == size;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    int insert(int num)
    {
        if (arr == nullptr)
            return HEAP_NOT_INITIALIZED; // heap is not initialized
        if (isFull())
            return HEAP_OVERFLOW; // heap overflow
        arr[count] = num;
        HeapifyUp(count);
        count++;
    }
    void HeapifyDown()
    {
        int parentIndex = 0;
        int leftChildIndex;
        int rightChildIndex;
        int smallestChildIndex;
        while (true)
        {
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
            if (leftChildIndex >= count)
                break;

            if (rightChildIndex < count && arr[rightChildIndex] < arr[leftChildIndex])
                smallestChildIndex = rightChildIndex;
            else
                smallestChildIndex = leftChildIndex;


            if (arr[parentIndex] <= arr[smallestChildIndex])
                break;
            int temp = arr[smallestChildIndex];
            arr[smallestChildIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = smallestChildIndex;
        }
    }
    int DeleteValue(int* d = nullptr)
    {
        if (arr == nullptr)
            return HEAP_NOT_INITIALIZED; // heap is not initialized
        if (isEmpty())
            return HEAP_UNDERFLOW; // heap overflow
        if (d == nullptr)
            return;
        *d = arr[0];
        arr[0] = arr[count - 1];
        HeapifyDown();
        count--;
    }
    void MakeItTree()
    {
    
    
    }
    void PrintHeap()
    {
        printf("\n\n");
        for (int i = 0;i < count;i++)
            printf("%d , ", arr[i]);
        printf("\n\n");
    }
};

