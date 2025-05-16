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
private:
    HuffmanNode<T>* root;
    string codes[256]; // Huffman codes for all byte values
    int frequencies[256] = { 0 };

    void buildFrequencyTable(const char* filePath) {
        FILE* file = fopen(filePath, "rb");  // Binary mode
        if (!file) {
            printf("Error: Could not open file: %s\n", filePath);
            return;
        }
        int ch;
        while ((ch = fgetc(file)) != EOF) {
            frequencies[(unsigned char)ch]++;
        }
        fclose(file);
    }
};

