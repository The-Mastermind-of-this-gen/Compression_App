#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <new>
#include "Heap.h"//We made this class
#include "HuffmanTree.h"// We also made this class

template<typename Input>
int main() 
{
	HuffmanTree<Input>* ashaf = new HuffmanTree<Input>();
	ashaf->FileScan();
	ashaf->HuffmanTreeBuild();
	return 0;
}
