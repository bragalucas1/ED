#include "Huffman.h"
#include <iostream>

using namespace std;

/*Construtor padrão que recebe o vetor de frequências preenchido da main, cria a árvore de Huffman que será usada em 
todo desenvolvimento do trabalho. */
HuffmanTree::HuffmanTree(int freqs[256]){
    /*Aqui, usamos o struct como ponteiro pra nodos - a implementação foi pensada armazenando as 
    menores frequências de modo que fique mais fácil para criarmos as subárvores.*/
    
    MyPriorityQueue<compairFreqs> PQ;
    unsigned char symbol;
    for(int i = 0; i < 256; i++){//criamos uma arvore para cada simbolo, cada nodo terá a frequencia de seu simbolo
        if(freqs[i] > 0){ //verificação a fim de não criamos nodos desnecessarios   
            symbol = i;
            Node *novo = new Node(symbol,freqs[i],NULL,NULL);
            PQ.push(compairFreqs(novo));//colocamos todos os nodos com as respectiva frequencias e simbolos na fila de prioridade
        }  
    } 

    /* Nessa etapa, enquanto o numero de arvores na FP não for 1, fazemos:
    Pegue (e as remova da fila) as duas árvores a,b de menor “peso” - 
    assuma que o  peso de uma árvore é a frequência armazenada em sua raiz):
    Crie uma nova árvore T onde a raiz será um nodo cujo peso é a soma do peso de a e de b. 
    O filho esquerdo de T será a e o direito será b.
    Insira T de volta em PQ*/
    /*Realizamos o bloco de comandos a baixo enquanto não existir uma única arvore(HuffmanTree) na fila de prioridades.*/
    
    while (PQ.size()!= 1){
        compairFreqs a = PQ.top();
        PQ.pop();
        compairFreqs b = PQ.top();
        PQ.pop();
        Node *T = new Node(' ', (a.node->freq + b.node->freq),a.node,b.node);
        PQ.push(compairFreqs(T));
    }
    root = PQ.top().node; //aqui, recebemos a unica arvore restante na Fila de Prioridades.
    buildTreeCode(root,aux);//construimos o código em cima da arvore resultante.
}

/*Função que imprime a árvore de Huffman. */
void HuffmanTree::printTree(Node *root) const{
       if(!root){
        cout  << "A frequencia é: " << root->freq << "e o elem é : " << root->elem << endl;
        printTree(root->left);
        printTree(root->right);
    }
}

/*Função debuger que imprimi o código de cada caracter do arquivo, usei para comparar durante a compressão e descompressão.*/
void HuffmanTree::printCode() const{
    for(int i = 0; i < 256; i++){
       unsigned char c = i;
       if(code[i] !=  ""){
           cout << c << ":" << code[i] << endl;
       }
    }
}

  
/*Função responsável por verificar se o Nodo local é uma folha, ou seja, não possui filhos - utilidade
acentuada nas funçoes de construir o código, e decodificar o mesmo*/
bool HuffmanTree::leafCheck(Node *nodo) const{
    if(nodo->left == NULL && nodo->right == NULL){
        return true;
    }
    else{
        return false;
    }
}

void HuffmanTree::buildTreeCode(Node *root, string aux){   
    if(root == NULL){ //caso base
        return;
    }
    if(leafCheck(root)){
        if(aux == " "){ //aqui verificamos se a arvore em questão possui apenas um Nodo
            code[root->elem] = "0"; //ætribuimos um código e retornamos
            return;
        }
       
        code[root->elem] = aux;
        return;
    }
    buildTreeCode(root->left, aux + "0"); //quando é feito um percurso á esquerda temos 0
    buildTreeCode(root->right, aux + "1");//percuro á direita temos um '1'   
}   
/**********************************************************************************/

void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<char> &in) const{
/*Essa função deverá le r o vetor de bytes (chars) “in”, comprimi-lo e gravar os bits
representando o arquivo comprimido em “out” (cada bool de out representará um
bit , sendo 1 representado por true e 0 por false)*/
  for(int i = 0; i < in.size(); i++){
        unsigned char k = in[i];
        const string &caracterCode = code[k];
        for(int j = 0; j < caracterCode.length(); j++){
            if(caracterCode[j] == '1'){
                out.push_back(true);
            }
            else if(caracterCode[j]  == '0'){
                out.push_back(false);
            }
        }
    }
}


void HuffmanTree::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const{
/*  Por exemplo, dado um arquivo contendo os bits “1000110”, começamos na raiz e processamos
    cada bit do arquivo fazendo o seguinte:
    1: vá para a direita na árvore (a partir da raiz)
    0: vá para a esquerda. Como chegamos em uma folha (contendo A), grave A na saída e volte a
    raiz.
    0: vá para a esquerda a partir da raiz. Como chegamos na folha B, grave B e volte a raiz.
    0: vá para a esquerda a partir da raiz. Como chegamos na folha B, grave B e volte a raiz.
    1: vá para a direita a partir da raiz.
    1: vá para a direita.
    0: vá para a esquerda. Como chegamos na folha 0, grave C.*/
    
    Node *auxiliar2 = root; //aqui criamos esse Nodo auxiliar que recebe a raiz de onde começaremos o processamento -
    //porém, ao gravarmos o valor de uma folha, devemos retornar a raiz - esse nodo receberá essa inrormação.

    /*Aqui, testamos o caso de ser apenas um caracter, seja único ou repetido.*/
    if(leafCheck(auxiliar2)){
        for(int i = 0; i < in.size(); i++){ //caso seja repetido, percorremos o tamanho do vetor os colocando no vetor
            out.push_back(auxiliar2->elem);
        }
        return;
    }

    //Caso árvore ''completa''
    for(int i = 0; i < in.size(); i++){
        if(in[i]){
            auxiliar2 = auxiliar2->right;
        }
        else{
            auxiliar2 = auxiliar2->left;
        }
        if(leafCheck(auxiliar2)){
            out.push_back(auxiliar2->elem);
            auxiliar2 = root;
        }
    }   
}


/************** Métodos inerentes a classe *************/
//Construtor de cópia
HuffmanTree::HuffmanTree(const HuffmanTree &other){
    root = NULL;
    code[256] = {""};
    
    *this=  other;
}
//Destrutor padrão
HuffmanTree::~HuffmanTree(){
    Destroy(root);
}
//Função auxiliar do destrutor - percurso DFS pós ordem em árvores binarias
void HuffmanTree::Destroy(Node *n){
    if(!n){
        return;
    }
    Destroy(n->left);
    Destroy(n->right);
    delete n;
}
//Operador de atribuição
HuffmanTree & HuffmanTree::operator=(const HuffmanTree &other){
    if(this == &other){ //teste de auto atribuição
        return *this;
    }
    Destroy(root);
    root = copiarNodos(root);
    for(int i = 0; i < 256; i++){
        code[i] = other.code[i];
    }
    return *this;
}
//Funçãp auxiliar recursiva que copia os nodos;=.
Node* HuffmanTree::copiarNodos(const Node *root) const{
    if(root == NULL){
        return NULL;
    }
    Node *copy = new Node(root->elem,root->freq,root->left,root->right);
    copy->left = copiarNodos(root->left);
    copy->right = copiarNodos(root->right);
    return copy;
}
    