#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "MyPriorityQueue.h"
#include "MyVec.h"
//#include "MySet.h"
#include <iostream>
using namespace std;

template <class T>
class Node{
	public: //classe auxiliar - usaremoMyPriorityQueue
		Node(const T &elem_) : elem(elem_),left(NULL), right(NULL) {}
		Node<T> *left, *right;
		T elem;
		Node<T> *parent; //agora cada nodo armazena seu pai
};
//assuma que o peso de uma árvore é a frequência armazenada em sua raiz):


template<class T>
class HuffmanTree{
    private:
    MyPriorityQueue<T> PQ;
    //void createTree(Node<T> *root)
    public:
    HuffManTree(int freqs[256]);    
    void comprimir(MyVec<bool> &out, const MyVec<char> &in) const;
    void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;

};


#endif