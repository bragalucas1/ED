#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "MyPriorityQueue.h"
#include "MyVecNewIterator.h"
#include <iostream>
#include <algorithm> //PAIR esta aqui.

using namespace std;

/*Minha classe Nodo que anteriormente ficava aqui, foi passada para a classe MyPriorityQueue, a fim de armazenar as frequencias negatias,
de modo que ficasse mais fácil a manipulação dos menores resultados*/


//assuma que o peso de uma árvore é a frequência armazenada em sua raiz):



class HuffmanTree{
    private:
    Node *root;
    MyPriorityQueue<Node *> PQ;  //fila de prioridade que armazenara a arvore criada no construtor
    
    void buildcode(Node *root);
    
    public:
    HuffmanTree(int freqs[256]);
    //HuffmanTree();
    void smallestChild(Node *root,int pos);
    //void removesmallest();
    void comprimir(MyVec<bool> &out, const MyVec<char> &in) const;
    void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;
    
    /*Métodos inerentes á classe*/

    //Destrutor 
    //~HuffmanTree();
    //Construtor de cópia
    //HuffmanTree(const HuffmanTree&);
    //Operador de atribuição
    //HuffmanTree &operator=(const HuffmanTree &);


};


#endif