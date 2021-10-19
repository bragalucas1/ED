#include <iostream>
#include <cassert>
#include <fstream>
#include "Huffman.h"
#include "Huffman.cpp"
using namespace std;

int main(int argc, char **argv){
    //Declaração de variáveis.
    int freqs[256] = {0};
    //Abertura dos arquivos responsáveis pelas operações.
    ifstream innerfile(argv[2]);
    ofstream outfile(argv[3]);
    
    /*Nessa etapa, tratamos o caso de o arquivo de entrada ser vazio - não fazemos nenhuma operação e encerramos 
    o programa.*/
    innerfile.seekg(0, ios::end);  
    int filesize = innerfile.tellg();
    innerfile.seekg(0,ios::beg);
        
    if(filesize == 0){    
        innerfile.close();
        outfile.close();
        return 0;
    }
    
    /*Nessa etapa do código, calculamos a frequẽncia (no caso de uma entrada para comprimir) de cada caracter do arquivo 
    de entrada, e passamos para o construtor da árvore e fazemos as aritmeticas de construção do código, compressão e passagem 
    pro arquivo de saída.*/

    if(argv[1][0] == 'c'){ 
        /*Tratamento para verificar se os arquivos foram abertos corretamente.*/
        if(!innerfile.is_open()){
           cerr <<  "Couldn't open file.";
        }
        if(!outfile.is_open()){
            cerr << "Couldn't open the out file.";
        }

        /*Criação dos vetores responsáveis pela compressão.*/
        MyVec<bool> out;
        MyVec<char> in;
       
        char aux = 0;
        while(innerfile.read(&aux,1)) { //lemos caracter por caracter do arquivo e calculamos a respectiva frequencia
            if(innerfile.eof()){ //ŧratamento para quando o arquivo acabar - estava retornando o ultimo caracter duplicado  
                break;
            }
            in.push_back(aux); //colocamos o caracter no vetor que será passado pra função comprimir
            freqs[(unsigned char)aux]++; //calculamos sua frequencias, passando como unsigned char.
       }

        /*Passamos o vetor de frequencias lido do arquivo com a frequencia de cada caracter, afim de criar
        nossa árvore de Huffman específica para aquele arquivo.*/
        HuffmanTree arvore(freqs);
        arvore.comprimir(out,in); //aqui recebemos o vetor de saida com vários booleanos (0 ou 1).
        
        /*Etapa da aritmética de BITS - compactaremos o que foi comprido no vetor OUT de booleanos.*/
        int vectorsize = out.size(); 
        
        /*Guardamos o vetor de frequencia no arquivo afim 
        de recriar a árvore, e salvamos também o tamanho vetor de boleanos.*/
        outfile.write(reinterpret_cast<char*>(&vectorsize),sizeof(int)); 
        outfile.write(reinterpret_cast<char*>(&freqs),sizeof(int)*256);
        
        int bitProcess = 0;
        unsigned char binary = 0;
        //////////////////////
        
        /*A ideia essencial para um bom funcionamento e armazenamento da arvore de Huffman é salvarmos de 8 em 8 bits - gastamos menos
        bytes para tal, caso o vetor esteja ''incompleto'', completamos com 0.*/
        if(out.size() % 8 != 0){
            while(out.size() % 8 != 0){
               out.push_back(false);
            }
        }
        
        int newvecsize = out.size();
        outfile.write(reinterpret_cast<char*>(&newvecsize),sizeof(int));
        
        /*Nessa etapa, ligamos o bit proveniente do vetor out comprimido, por meio do operador lógico |. */
        for(int i = 0; i < out.size();i++){
            if(i % 8 == 0){ //gravamos no arquivo a cada 8 bits.
                outfile.write(reinterpret_cast<char *>(&binary),sizeof(unsigned char));
                binary = 0;
                bitProcess = 0;
            }
            if(out[i]){
                binary = binary |  (1 << (bitProcess));
            }
            bitProcess++;
            if(i == out.size()-1){
                outfile.write(reinterpret_cast<char *>(&binary),sizeof(unsigned char));
            }
        }
    }

    if(argv[1][0] == 'd'){
        /*Tratamento de exceções para abertura do arquivo.*/
        if(!innerfile.is_open()){
           cerr <<  "Couldn't open the inner file.";
        }
        
        if(!outfile.is_open()){
            cerr <<  "Couldn't open the out file.";
        }

        MyVec<bool> in;
        MyVec<char> out;

        int tamanhovec = 0;
        int newsize = 0;
        
        //Lemos o tamanho do vetor  e o vetor de frequencias oriundos da operação 'c', e o tamanho do vetor pós ser completado.
        innerfile.read(reinterpret_cast<char*>(&tamanhovec),sizeof(int));
        innerfile.read(reinterpret_cast<char*>(&freqs),256*sizeof(int)); 
        innerfile.read(reinterpret_cast<char*>(&newsize),sizeof(int));
        //Chamamos o construtor da árvore para recriar a mesma.
        HuffmanTree arvore(freqs);
        
        //Colocamos os simbolos em um MyVec de char auxiliar - 
        
        MyVec<char> vec;
        char aux = ' ';
        
        //Lemos byte por byte da parte de ''simbolos''.
        while(innerfile.read(&aux,1)){
            if(innerfile.eof()){ //ŧratamento para quando o arquivo acabar - estava retornando o ultimo caracter duplicado  
                break;
            }
            vec.push_back(aux);
        }

        int bitProcess = 0; //começamos a leitura do bit da esquerda para direita
        int index = 0; //cursor para andarmos no vetor de simbolos

        for(int i = 0; i < newsize; i++){
            if(i == tamanhovec){
                break;
            }
            if(i % 8 == 0){ //quando chegamos a 8 bytes, resetamos e andamos com o indice do vetor de simbolos,
               index++;
               bitProcess = 0; 
            }
            in.push_back(vec[index] & (1 << (bitProcess))); //colocamos no vetor de booleanos
            bitProcess++; //aumetamos 1 no fator do operador logíco & e passamos para o prox bit.
        }
        
        arvore.descomprimir(out,in);
        for(int i = 0; i < out.size(); i++){//passamos cada caracter do vetor out para o arquivo de saída.
             outfile << out[i];
        }
    }
    //Fechamento dos arquivos.
    innerfile.close();
    outfile.close();
    
    return 0;

}

