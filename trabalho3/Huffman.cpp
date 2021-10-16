#include "Huffman.h"
#include <iostream>

using namespace std;

/*Construtor padrão que recebe o vetor de frequências preenchido da main, cria a árvore de Huffman que será usada em 
todo desenvolvimento do trabalho. */
HuffmanTree::HuffmanTree(int freqs[256]){
    /*Aqui, usamos uma fila de prioridade que recebe a frequencia e o Nodo - a implementação foi pensada armazenando as 
    menores frequências de modo que fique mais fácil para criarmos as subárvores.*/
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
    //cout << "PQ tamanho: " << PQ.size() << endl;
    /*Realizamos o bloco de comandos a baixo enquanto não existir uma única arvore(HuffmanTree) na fila de prioridades.*/
    while (PQ.size()!= 1){
        //cout << PQ.top()->elem << endl;
        Node *a = PQ.top().second; 
        //cout << PQ.top()->elem << endl;
        PQ.pop();
        //cout << PQ.top()->elem << endl;
        Node *b = PQ.top().second;
        //cout << PQ.top()->elem << endl;
        PQ.pop();
        Node *T = new Node(' ', (a->freq + b->freq),a,b);
        //T->left = a;
        //T->right = b;
        PQ.push(pair<int,Node*>(-T->freq,T));
        //cout << PQ.top()->elem << endl;
    }
    
    root = PQ.top().second; //aqui, recebemos a unica arvore restante na Fila de Prioridades.
    buildTreeCode(root,aux);//construimos o código em cima da arvore resultante.
    

    //FALTA DESTRUTOR DA ÁRVORE -- VAZAMENTO DE MEMÓRIA NO VALGRIND
    //PQ.print();
    //cout << PQ.size() << endl;
    //cout << (PQ.top()->freq)<< endl;
    //cout << PQ.top()->right << endl;
    //A árvore de Huffman será a (única) árvore restante na fila de prioridades.*/
    //cout << -(PQ.top()->freq) << endl;
    //PQ.pop();
    
}
/*Função que imprime a árvore de Huffman. */
void HuffmanTree::printTree(Node *root) const{
       if(root!=NULL){
        cout  << root->freq << "[" << root->elem <<"]" <<  endl;
        printTree(root->left);
        printTree(root->right);
    }
}
void HuffmanTree::printCode(){
    for(int i = 0; i < 256; i++){
       unsigned char c = i;
       if(code[i] !=  ""){
           cout << c << ":" << code[i] << endl;
       }
    }
}
/*Função debugger */
void HuffmanTree::auxiliar(){
   //buildTreeCode(root,aux);//Abertura dos arquivos responsáveis pelas operações.
   //printTree(root);
   //   ecodeTree()
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

//Função recursiva responsável por criar o código da nossa árvore, percorrendo cada nodo. 
//Está muito reduntante - MODIFICAR DEPOIS
/*void HuffmanTree::buildTreeCode(Node *root){
    /*Basta andar na árvore e pré-calcular a codificação de cada símbolo (exemplo acima: o símbolo
    C teria codificação “110”). A seguir, para cada símbolo, grave sua codificação no arquivo de
    saída.
    Observe que considerar que o lado direito vale 1 e o esquerdo vale 0 não é importante (poderia
    ser o contrário). O que importa é que a mesma estratégia usada na compressão será utilizada
    na descompressão.
    buildTreeCode2(root,aux);
}   */

void HuffmanTree::buildTreeCode(Node *root, string aux){   
    if(root == NULL){ //caso base
        return;
    }
    //cout << aux << " aqui " << endl;
    if(leafCheck(root)){
        if(aux == " "){ //aqui verificamos se a arvore em questão possui apenas um Nodo
            //cout << "aqui" << endl;
            code[root->elem] = "0";
            return;
        }
        code[root->elem] = aux;
        //cout << root->elem << " = " << code[root->elem] << endl;
        /*for(int i = 0; i < 256; i++){
            code[i] = aux;
        }*/
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
    
    Node *auxiliar2 = root; //aqui criamos esse Nodo auxiliar que recebe a raiz de onde começaremos o processamento -
    //porém, ao gravarmos o valor de uma folha, devemos retornar a raiz - esse nodo receberá essa inrormação.
    
    for(int i = 0; i < in.size(); i++){
        if(in[i]){
            auxiliar2 = auxiliar2->right;
        }
        else{
            if(leafCheck(auxiliar2)){
                out.push_back(auxiliar2->elem);
                auxiliar2 = root;
            }
            auxiliar2 = auxiliar2->left;
        }
        if(leafCheck(auxiliar2)){
            out.push_back(auxiliar2->elem);
            auxiliar2 = root;
        }
    }   
}
HuffmanTree::HuffmanTree(const HuffmanTree &other){
    root = NULL;

    *this = other;
}
HuffmanTree::~HuffmanTree(){
    Destroy(root);
}

void HuffmanTree::Destroy(Node *n){
    if(!n){
        return;
    }
    Destroy(n->left);
    Destroy(n->right);
    delete n;
}


    