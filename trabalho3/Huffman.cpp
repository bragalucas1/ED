#include "Huffman.h"
#include <iostream>

using namespace std;

template<class T>
HuffmanTree<T>::HuffmanTree(int freqs[256]){
    for(char ch = 0; ch < 256; ch++){//criamos uma arvore para cada simbolo, cada nodo terá a frequencia de seu simbolo
        if(freqs[ch] > 0){
            PQ.push(ch); //inserimos a árvore em uma fila de prioridades PQ
        }
    }
    do
    {
     Node<T> a = 
     Node<T> b =    
    }while (PQ.size != 1); 
    
}

template<class T>
void HuffmanTree<T>::comprimir(MyVec<bool> &out, const MyVec<char> &in) const{}

template<class T>
void HuffmanTree<T>::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const{}