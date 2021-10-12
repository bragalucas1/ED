#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "MyPriorityQueue.h"
#include "MyVecNewIterator.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> //PAIR esta aqui.

using namespace std;

/*Minha classe Nodo foi modificada a fim de armazenar as frequencias, e usando o pair provido pela lib do C++,
armazenamos as frequencias como ordem de prioridade e o Nodo como second, dentro de uma fila de prioridade Local no construtor.*/
class Node{ 
	public: //classe auxiliar - usaremos MyPriorityQueue de Nodos
		Node(const unsigned char elemento, int freq, Node*left, Node *right): elem(elemento), freq(freq), left(left), right(right){}
		Node *left, *right;
        unsigned char elem;
        int freq;	 
        /*bool operator >(const Node &other)const{ //Overload do operador < a fim de comparar as frequencias negativas
            if(this->freq > other.freq){            
                return true;    
            }
            else{
                return false;
            }
        }*/
};

//Anotações importantes:
//assuma que o peso de uma árvore é a frequência armazenada em sua raiz):

class HuffmanTree{
    private:
    int cursor = 0;
    string aux = " ";
    string code[256] = {""};
    Node *root; /*nodo responsável basicamente pelo funcionamento do trabalho como um todo - oriundo da ultima arvore restante
    //da fila de prioridade, será argumento de várias funçoes*/

    public:
    bool leafCheck(Node *n) const;
    //void buildTreeCode(Node *root) ;
    void buildTreeCode(Node *root, string aux);
    void auxiliar();
    void printCode();
    void printTree(Node *root) const; //função debugger
    HuffmanTree(int freqs[256]);
    void Destroy (Node *);
    
    //Funções primordiais do código.
    void comprimir(MyVec<bool> &out, const MyVec<char> &in) const;
    void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;
    
    /*Métodos inerentes á classe*/

    //Destrutor 
    ~HuffmanTree();
    //Construtor de cópia
    HuffmanTree(const HuffmanTree &other);
    //Operador de atribuição
    //HuffmanTree &operator=(const HuffmanTree &);


};


#endif