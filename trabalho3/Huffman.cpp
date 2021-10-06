#include "Huffman.h"
#include <iostream>

using namespace std;

template<class T>
HuffmanTree<T>::HuffmanTree(int freqs[256]){
    PQ = NULL;
    char symbol = " ";
    for(int i = 0; i < 256; i++){//criamos uma arvore para cada simbolo, cada nodo terá a frequencia de seu simbolo
        if(freqs[i] > 0){ //verificação a fim de não criamos nodos desnecessarios   
            symbol = i;
            Node<T> *novo = new Node<T>(symbol,freqs[i],NULL,NULL);
            PQ.push(novo);
        }  
    } 
    int pos = 0;

    do
    {   
        //LEFT - ESQUERDA RIGHT - DIREITA
        for(int i = 0; i < 256; i++){
            Node<T> *a;
            Node<T> *b;
        //Pegue (e as remova da fila) as duas árvores a,b de menor “peso”
        //Crie uma nova árvore T onde a raiz será um nodo cujo peso é a soma do peso de a e de b. O filho esquerdo de T será a e o direito será b.
            Node<T> *T = new Node<T>(symbol,a->freqs[i] + b->freqs[i],a,b);
        //Insira T de volta em PQ
            PQ.push(T);
        }  
    }while (PQ.size != 1); 
    
}

template<class T>
void HuffmanTree<T>::smallestChild(Node<T> *root, int pos){
    while(2*pos+1 < PQ.size()){ //enquanto a posicao atual tiver pelo menos um filho...
		int menorFilho = 2*pos+1;
		if(2*pos+2 < PQ.size() && PQ[2*pos+2] > PQ[menorFilho]) //ha um segundo filho e ele eh maior do que o primeiro?
			menorFilho = 2*pos+2;   
		if(PQ[pos] > PQ[menorFilho]){
			return; //nao precisamos continuar... por que?
		} else {
			swap(PQ[pos],PQ[menorFilho]); //troque o atual com o maior filho 
			pos = menorFilho; //repita o processo agora na posicao "maiorFilho"
		}
	}
}



template<class T>
void HuffmanTree<T>::comprimir(MyVec<bool> &out, const MyVec<char> &in) const{}

template<class T>
void HuffmanTree<T>::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const{}