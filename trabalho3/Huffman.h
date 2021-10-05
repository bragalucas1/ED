#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "MyPriorityQueue.h"
#include "MyVecNewIterator.h"
#include <iostream>

using namespace std;

template <class T>
class Node{
	public: //classe auxiliar - usaremos MyPriorityQueue
		Node(const T &elem_): elem(elem_),left(NULL), right(NULL){}
		Node<T> *left, *right, *parent; //agora cada nodo armazena seu pai
		T elem;
        char ch;
        int freq;
		 
};
//assuma que o peso de uma árvore é a frequência armazenada em sua raiz):


template<class T>
class HuffmanTree{
    private:
    MyPriorityQueue<T> PQ;      //fila de prioridade que armazenara a arvore criada no construtor
    void buildcode(Node<T> raiz);
    
    public:
    //HuffmanTree();
    HuffmanTree(int freqs[256]);
    void comprimir(MyVec<bool> &out, const MyVec<char> &in) const;
    void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;

};


#endif