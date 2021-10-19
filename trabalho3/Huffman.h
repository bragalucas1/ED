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
};

/*Struct que funciona como a função pair do c++ = aqui armazenamos um ponteiro pra Nodo, que compara as caracteristicas inerentes desse.
O acesso feito no construtor se dá de forma equivalente, porém não armazeno agora um inteiro como usava antes, visto que é um atributo
de Nodo, que pode ser facilmente acessado, visto que tudo é publico.
Exemplo de comparação:
Com struct: Node *T = new Node(' ', (a.node->freq + b.node->freq),a.node,b.node);
Com pair: Node *T = new Node(' ', (a->freq + b->freq),a,b); */
struct compairFreqs{
   Node *node; //aqui recebemos os atributo da classe Nodo, para podermos utiliza-los a fim de comparação - primordialmente as
   //frequencias
   compairFreqs(){
       node = NULL;
    }
   compairFreqs(Node *curr){
       node = curr;
   }
    
   bool operator>(const compairFreqs &other)const{ 
        //Overload do operador 
        /*Implementei o operador de modo que ele seja chamado como '>', porém 
        ele compara a menor frequencia.*/
        if(this->node->freq < other.node->freq){  
            return true;    
        }
        else{
            return false;
        }
    }
     /*Caso haja empate de frequências, isso não gera problemas visto que será tratado de forma equivalente nos metodos de compressão e 
    descompressão.*/
};


class HuffmanTree{
    private:
    /*nodo responsável basicamente pelo funcionamento do trabalho como um todo - oriundo da ultima arvore restante
    //da fila de prioridade, será argumento de várias funçoes*/
    Node *root; 
    string aux = " ";
    string code[256] = {""}; //vetor automático que funcionará como a tabela de códigos da árvore
    void buildTreeCode(Node *root, string aux); //função que cria o código da arvore, a partir da raiz
    void Destroy (Node *); //função chamada pelo destrutor que destroi a árvore recursivamente a partir da raiz
    Node* copiarNodos (const Node *root) const;
    
    public:
    HuffmanTree(int freqs[256]); //construtor da classe que recebe o vetor automático da frequencia de caracteres oriundo da main
    bool leafCheck(Node *n) const; //função que verifica se o nodo atual é uma folha
    void printCode() const;//função que printa o código de cada caracter na árvore
    void printTree(Node *root) const; //função debugger que printa a arvore atual

    
    //Funções primordiais do código.
    void comprimir(MyVec<bool> &out, const MyVec<char> &in) const;
    void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;
    
    
    /*Métodos inerentes á classe*/
    //Destrutor 
    ~HuffmanTree();
    //Construtor de cópia
    HuffmanTree(const HuffmanTree &other);
    //Operador de atribuição
    HuffmanTree &operator=(const HuffmanTree &);


};


#endif