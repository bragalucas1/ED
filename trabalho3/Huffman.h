#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "MyPriorityQueue.h"
#include "MyVecNewIterator.h"
#include <iostream>
#include <algorithm> //PAIR esta aqui.

using namespace std;

/*Minha classe Nodo foi modificada a fim de armazenar as frequencias negativas,
de modo que ficasse mais fácil a manipulação dos menores resultados.*/
class Node{ 
	public: //classe auxiliar - usaremos MyPriorityQueue de Nodos
		Node(const unsigned char elemento, int freq, Node *left, Node *right): elem(elemento), freq(-freq), left(NULL), right(NULL){}
		Node *left, *right;
        unsigned char elem;
        int freq;	 
};

//Anotações importantes:
//assuma que o peso de uma árvore é a frequência armazenada em sua raiz):

class HuffmanTree{
    private:
    Node *root;
    MyPriorityQueue<Node*> PQ;  //fila de prioridade - de Nodos -  que armazenara a arvore criada no construtor
    bool isLeaf(Node *nodo);
    string buildCode(Node *root);
    string buildCode(string st[], Node *x, string aux);
    
    public:
    HuffmanTree(int freqs[256]);
    void Destroy (Node *);
    
    
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