#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <new>
#include <windows.h>
#include <commdlg.h>
#include "Heap.h"//We made this class
#include "HuffmanTree.h"// We also made this class

bool OpenFileDialog(char* filePath, DWORD size) {

    OPENFILENAMEA ofn;
    ZeroMemory(&ofn, sizeof(ofn));// Initialize all fields to 0
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = filePath;
    ofn.nMaxFile = size;
    ofn.lpstrFilter = "lossless Files\0*.*\0Text Files\0*.txt\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    return GetOpenFileNameA(&ofn);
}

int main()
{

    char filePath[MAX_PATH] = { 0 };
    FILE* file;
    if (OpenFileDialog(filePath, MAX_PATH)) {
        printf("Selected file: %s\n", filePath);
        file = fopen(filePath, "rb");
        if (file) {
            printf("File opened successfully!\n");
        }
        else {
            printf("Failed to open the file.\n");
        }
    }
    else {
        printf("Dialog canceled or failed.\n");
    }
    fclose(file);

    TreeNode<char>* HuffmanTreeRoot = new TreeNode<char>;
    Huffman* a = new Huffman(filePath);

    HuffmanTreeRoot = a->ConstructHuffmanTree();
    delete a;

    int BlockSize = 100;
    printf("Enter Compression BlockSize: ");
    scanf("%d", &BlockSize);



    return 0;
}
