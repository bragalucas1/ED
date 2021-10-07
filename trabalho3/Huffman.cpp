#include "Huffman.h"
#include <iostream>

using namespace std;

HuffmanTree::HuffmanTree(int freqs[256]){
    unsigned char symbol;
    for(int i = 0; i < 256; i++){//criamos uma arvore para cada simbolo, cada nodo terá a frequencia de seu simbolo
        if(freqs[i] > 0){ //verificação a fim de não criamos nodos desnecessarios   
            symbol = i;
            Node *novo = new Node(symbol,freqs[i], NULL, NULL);
            PQ.push(novo);//colocamos todos os nodos com as respectiva frequencias e simbolos na fila de prioridade
        }  
    } 
    
    /* Nessa etapa, enquanto o numero de arvores na FP não for 1, fazemos:
    Pegue (e as remova da fila) as duas árvores a,b de menor “peso” - 
    assuma que o  peso de uma árvore é a frequência armazenada em sua raiz):
    Crie uma nova árvore T onde a raiz será um nodo cujo peso é a soma do peso de a e de b. 
    O filho esquerdo de T será a e o direito será b.
    Insira T de volta em PQ*/
    /*cout << PQ.top()->elem<< endl;
    PQ.pop();
    cout << PQ.top()->elem<< endl;
    PQ.pop();
    cout << PQ.top()->elem<< endl;
    PQ.pop();
  
    cout << PQ.top()->elem << endl;*/
    PQ.print();
    cout << PQ.size() << endl;
    do
    {  
        //cout << PQ.top()->elem << endl;
        Node *a = PQ.top(); 
        //cout << PQ.top()->elem << endl;
        PQ.pop();
        //cout << PQ.top()->elem << endl;
        Node *b = PQ.top();
        //cout << PQ.top()->elem << endl;
        PQ.pop();
        Node *T = new Node('l', -(a->freq + b->freq), a, b);
        PQ.push(T);
        //cout << PQ.top()->elem << endl;
    } while (PQ.size()!= 1);
    PQ.print();
    //cout << PQ.size() << endl;
    //cout << PQ.top()->left->elem << endl;
    //cout << PQ.top()->right << endl;
    //A árvore de Huffman será a (única) árvore restante na fila de prioridades.*/
    //cout << -(PQ.top()->freq) << endl;
    //PQ.pop();
    
}
/*bool HuffmanTree::isLeaf(Node *nodo){
    if(nodo->left == NULL && nodo->right == NULL){
        return true;
    }
    else{
        return false;
    }
}

string HuffmanTree::buildCode(Node *root){
    string code[256] = {};
    return buildCode(code, root, " ");
   
}
string HuffmanTree::buildCode(string code[], Node *x, string aux){
    if(isLeaf(x)){
        code[x->elem] = aux;
        return;
    }
    buildCode(code, x->left, aux + '0');
    buildCode(code, x->right, aux + '1');
}*/

void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<char> &in) const{}

void HuffmanTree::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const{}



/*HuffmanTree::~HuffmanTree(){
    Destroy(root);
}

void HuffmanTree::Destroy(Node *n){
    if(!n){
        return;
    }
    Destroy(n->left);
    Destroy(n->right);
    delete n;
    //delete []root;
}*/
    