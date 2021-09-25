#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "MyVec.h"
#include <iostream>

using namespace std;

class HuffmanTree{
    private:
    
    

    public:
    HuffManTree(int freqs[256]);
    void comprimir(MyVec<bool> &out, const MyVec<char> &in) const;
    void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;

};


#endif