#include "Huffman.h"
#include <iostream>

using namespace std;

HuffmanTree::HuffmanTree(int freqs[256]){
    MyPriorityQueue<pair<int,Node*>> PQ;
    unsigned char symbol;
    for(int i = 0; i < 256; i++){//criamos uma arvore para cada simbolo, cada nodo terá a frequencia de seu simbolo
        if(freqs[i] > 0){ //verificação a fim de não criamos nodos desnecessarios   
            symbol = i;
            Node *novo = new Node(symbol,freqs[i],NULL,NULL);
            PQ.push(pair<int,Node*>(-novo->freq,novo));//colocamos todos os nodos com as respectiva frequencias e simbolos na fila de prioridade
        }  
    } 
    
    //VERIFICAR QUANDO POSSUI APENAS 1 NODO - FALHA DE SEGMENTAÇÃO 

    /* Nessa etapa, enquanto o numero de arvores na FP não for 1, fazemos:
    Pegue (e as remova da fila) as duas árvores a,b de menor “peso” - 
    assuma que o  peso de uma árvore é a frequência armazenada em sua raiz):
    Crie uma nova árvore T onde a raiz será um nodo cujo peso é a soma do peso de a e de b. 
    O filho esquerdo de T será a e o direito será b.
    Insira T de volta em PQ*/
    /*cout << (PQ.top().second->freq)<< endl;
    PQ.pop();
    cout << (PQ.top().second->freq)<< endl;
    PQ.pop();
    cout << (PQ.top().second->freq)<< endl;
    PQ.pop();
    cout << (PQ.top().second->freq)<< endl;*/
    //PQ.print();
    //cout << PQ.size() << endl;
    do
    {  
        //cout << PQ.top()->elem << endl;
        Node *a = PQ.top().second; 
        //cout << PQ.top()->elem << endl;
        PQ.pop();
        //cout << PQ.top()->elem << endl;
        Node *b = PQ.top().second;
        //cout << PQ.top()->elem << endl;
        PQ.pop();
        Node *T = new Node('l', (a->freq + b->freq),a,b);
        //T->left = a;
        //T->right = b;
        PQ.push(pair<int,Node*>(-T->freq,T));
        //cout << PQ.top()->elem << endl;
    } while (PQ.size()!= 1);
    
    root = PQ.top().second; //aqui, recebemos a unica arvore restante na Fila de Prioridades.



    //FALTA DESTRUTOR DA ÁRVORE -- VAZAMENTO DE MEMÓRIA NO VALGRIND
    //PQ.print();
    //cout << PQ.size() << endl;
    //cout << (PQ.top()->freq)<< endl;
    //cout << PQ.top()->right << endl;
    //A árvore de Huffman será a (única) árvore restante na fila de prioridades.*/
    //cout << -(PQ.top()->freq) << endl;
    //PQ.pop();
    
}

void HuffmanTree::printTree(Node *root)const {
       if(root!=NULL){
        cout  << root->freq << "  (" << root->elem <<")" << endl;
            printTree(root->left);
            printTree(root->right);
    }


}
void HuffmanTree::auxiliar(){
   buildTreeCode(root);
   printTree(root);
   decodeTree()
}

bool HuffmanTree::isLeaf(Node *nodo) const{
    if(nodo->left == NULL && nodo->right == NULL){
        return true;
    }
    else{
        return false;
    }
}

void HuffmanTree::buildTreeCode(Node *root){
    if(root == NULL){ //caso base
        return;
    }
    string aux = " ";
    for(int i = 0; i < 256; i++){
        code[i] = "x";
    }

    buildCodeRecursivity(root, aux);
    
    for(int i = 0; i < 256; i++){
        if(code[i] != "x"){
            cout << code[i] << endl;
        }
    }
}   

void HuffmanTree::buildCodeRecursivity(Node *root, string aux){
    if(root == NULL){ //caso base
        return;
    }

    if(isLeaf(root)){
        code[root->elem] = aux;
        return;
    }
    buildCodeRecursivity(root->left, aux + "0"); //quando é feito um percurso á esquerda temos 0
    buildCodeRecursivity(root->right, aux + "1");//percuro á direita temos um '1'
}

void HuffmanTree::decodeTree(Node *root, int cursor, string aux){
    /*Por exemplo, dado um arquivo contendo os bits “1000110”, começamos na raiz e processamos
    cada bit do arquivo fazendo o seguinte:
    1: vá para a direita na árvore (a partir da raiz)
    0: vá para a esquerda. Como chegamos em uma folha (contendo A), grave A na saída e volte a
    raiz.
    0: vá para a esquerda a partir da raiz. Como chegamos na folha B, grave B e volte a raiz.
    0: vá para a esquerda a partir da raiz. Como chegamos na folha B, grave B e volte a raiz.
    1: vá para a direita a partir da raiz.
    1: vá para a direita.
    0: vá para a esquerda. Como chegamos na folha 0, grave C.*/
    string receiver = " ";
    if(root = NULL){
        return;
    }
    if(isLeaf(root)){
        receiver = root->elem;
        return;
    }
    cursor++;
    if(code[cursor] != "0"){
        decodeTree(root->right,cursor,aux);
    }
    else{
        decodeTree(root->left,cursor,aux);
    }
    
}
//void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<char> &in) const{}

//void HuffmanTree::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const{}



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
    