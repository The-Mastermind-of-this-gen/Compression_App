#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <new>
#include "Heap.h"
#pragma once
using namespace std;

// ===== Tree Node Template =====
template<typename Input>
struct TreeNode {
    Input data; //That's just a char !
    TreeNode* left;
    TreeNode* right;
    long BitFreq;

    TreeNode() {
        data = Input{};
        left = NULL;
        right = NULL;
        BitFreq = 0;
    }


    bool operator<(const TreeNode& other) const
    {
        return BitFreq < other.BitFreq;
    }


    bool operator>(const TreeNode& other) const
    {
        return BitFreq > other.BitFreq;
    }


    bool operator==(const TreeNode& other) const
    {
        return BitFreq == other.BitFreq;
    }


    bool operator!=(const TreeNode& other) const
    {
        //this is already using the operator==
        return !(*this == other);
    }


    bool operator<=(const TreeNode& other) const
    {
        //uses the operator> which we previously defined
        return !(*this > other);
    }

    bool operator>=(const TreeNode& other) const
    {
        //use the operator< which we previously defined
        return !(*this < other);
    }
};

class Huffman
{
    //======= Properties ========
    short File_char_Freq[256] = { 0 };
    int ch;
    Heap<TreeNode<char>>* myHeap = new Heap<TreeNode<char>>();
    FILE* file;
    //========= private methods =========
    void CalculateFrequency()
    {
        while ((ch = fgetc(file)) != EOF)
            File_char_Freq[ch]++;//to read all the file and generate calculate the frequency for each character
    }
    void HeapBuild()
    {
        for (int i = 0;i < 256;i++)
        {
            if (File_char_Freq[i] != 0)
            {
                TreeNode<char> temp;
                temp.BitFreq = File_char_Freq[i];
                temp.data = i;
                myHeap->insert(temp);
            }
        }
    }

public:
    Huffman(char* File)
    {
        file = fopen(File, "rb");

    }
    ~Huffman()
    {
        fclose(file);
        delete myHeap;
    }
    TreeNode<char>* ConstructHuffmanTree()
    {
        myHeap->initialize(16);
        if (file) {
            CalculateFrequency();  // <<< You must call it here
            HeapBuild();
        }
        while (true)
        {
            TreeNode<char>* temp1 = new TreeNode<char>();
            TreeNode<char>* temp2 = new TreeNode<char>();
            bool TF1 = myHeap->DeleteValue(temp1);
            bool TF2 = myHeap->DeleteValue(temp2);

            if (TF1 && TF2)
            {
                TreeNode<char>* parent = new TreeNode<char>();
                parent->BitFreq = temp1->BitFreq + temp2->BitFreq;
                parent->left = temp1;
                parent->right = temp2;
                myHeap->insert(*parent);
            }
            else

                return temp1;

        }
    }

};
