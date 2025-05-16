#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <new>
#pragma once
using namespace std;

// ===== Tree Node Template =====
template<typename Input>
struct TreeNode {
    Input data;
    TreeNode* left;
    TreeNode* right;
    int BitFreq;

    TreeNode() {
        data = Input{};
        left = NULL;
        right = NULL;
        BitFreq = 0;
    }
};

template<typename Input>
class HuffmanTree {
public:
    Heap<TreeNode<Input>>* MyHeap = new Heap<TreeNode<Input>>();
    int frequencies[256] = { 0 };//all file different values with its frequencies
    TreeNode<Input>* Huffman_Tree = new TreeNode<Input>();
    int BlockSize = 1000;
    void FileScan(const char* filePath) {
        FILE* file = fopen(filePath, "rb");  // Binary mode
        if (!file) {
            printf("Error: Could not open file: %s\n", filePath);
            return;
        }
        printf("Enter the amount of Compressing block size:");
        scanf("%d", &BlockSize);
        MyHeap->initialize(BlockSize);
        int ch;
        while ((ch = fgetc(file)) != EOF) {
            frequencies[(unsigned char)ch]++;
        }
        for (int i = 0;i < 256;i++)
        {
            //char c = frequencies[i];
            if (frequencies[i] != 0)
            {
                TreeNode<Input> temp = new TreeNode<Input>();
                temp->data = i;
                temp->BitFreq = frequencies[i];
                MyHeap->insert(temp);
            }
        }
        fclose(file);
        HuffmanTreeBuild();
    }
    void HuffmanTreeBuild()
    {
        while(MyHeap->count > 1) 
        {
            TreeNode<Input>* TempPerant = new TreeNode<Input>();

            TempPerant->left= MyHeap->arr[MyHeap->count];
            MyHeap->DeleteValue(MyHeap->arr[count]);

            TempPerant->right= MyHeap->arr[MyHeap->count];
            MyHeap->DeleteValue(MyHeap->arr[count]);

            TempPerant->BitFreq = TempPerant->left->BitFreq + TempPerant->right->BitFreq;
            TempPerant->data = "Zbady Farawla";//akeed fy 7aga 8lt eeh b2a allh a3lm

            MyHeap->insert(TempPerant);
        }
        Huffman_Tree = MyHeap->arr[0];
        return;
    }

    
};

