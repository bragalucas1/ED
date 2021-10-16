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
     

    /*Nessa etapa do código, calculamos a frequẽncia (no caso de uma entrada para comprimir) de cada caracter do arquivo 
    de entrada, e passamos para o construtor da árvore e fazemos as aritmeticas de construção do código, compressão e passagem 
    pro arquivo de saída.*/

    if(argv[1][0] == 'c'){ 
       
        /*Tratamento para verificar se o arquivo foi aberto corretamente.*/
        if(!innerfile.is_open()){
           cerr <<  "Couldn't open file.";
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

        /*passamos o vetor de frequencias lido do arquivo com a frequencia de cada caracter, afim de criar
        nossa árvore de Huffman específica para aquele arquivo.*/
        HuffmanTree arvore(freqs);

        arvore.comprimir(out,in); //aqui recebemos o vetor de saida com vários booleanos (0 ou 1).
        cout << "Size of in: " << in.size() << endl;
        cout << "Size of out: " << out.size() << endl;
        cout << "File compression suceed!" << endl;
        
        for(int i=0;i < out.size();i++){
		    cout << out[i];
	    }
        
        
        
        /*Etapa da aritmética de BITS - compactaremos o que foi comprido no vetor OUT de booleanos.*/
        if(!outfile.is_open()){
            cerr << "Couldn't open the out file.";
        }

        //Variáveis auxiliares :
        int vectorsize = out.size();
        int j = 0;
        unsigned char binary = 0;
        //////////////////////
        
        /*Guardamos o vetor de frequencia no arquivo afim 
        de recriar a árvore, e alvamos também o vetor de boleanos.*/
        outfile.write(reinterpret_cast<char*>(&vectorsize),sizeof(int)); 
        outfile.write(reinterpret_cast<char*>(&freqs),sizeof(int)*256);

        for(int i = 0; i < out.size();i++){
            if(out[i]){
                binary = binary | (out[i] << j);
                j++;  
            }   
            //j++;    
            if(i % 8 == 0){
                outfile.write(reinterpret_cast<char*>(&binary),sizeof(unsigned char)); 
                j = 0;
                binary = 0;
           }   
            //cout << out[i];
        }
        
    }

    if(argv[1][0] == 'd'){
        
        MyVec<bool> in;
        MyVec<char> out;

        int tamanhovec = 0;
        
        
        if(!innerfile.is_open()){
           cerr <<  "Couldn't open the inner file.";
        }
        
        if(!outfile.is_open()){
            cerr <<  "Couldn't open the out file.";
        }
        
       
        innerfile.read(reinterpret_cast<char*>(&tamanhovec),sizeof(int)); //le o tamanho
        innerfile.read(reinterpret_cast<char*>(&freqs),256*sizeof(int)); //le o tamanho
        //cout << "Tamanho vec: " << tamanhovec << endl;
        
        /*for(int i = 0; i < 256; i++){
            if(freqs[i] != 0){
                cout << freqs[i] << " ";
            }
        }*/
        
        HuffmanTree arvore(freqs);
        
        MyVec<char> vec;
        char aux;
        int cont = 0;
        while(innerfile.read(&aux,1)){
            vec.push_back(aux);
        }

        //cout << "Vec em 0: " << vec[0] << endl;
        int k = 0, j = 0; 
        for(int i = 0; i < tamanhovec; i++){    
            in.push_back(vec[i] & (1 << k));
            k++;
            if(i % 8 == 0){
                i++;
                k = 0;
            }
        }
        
        for(int i = 0; i < out.size(); i++) cout << out[i] << " ";
        arvore.descomprimir(out,in);
        /*for(int i = 0; i < out.size(); i++){
            outfile << out[i];
        }*/
        outfile << out;
        //outfile.write(reinterpret_cast<char *>(&out),sizeof(unsigned char)*out.size());
    
    }









    //Fechamento dos arquivos.
    innerfile.close();
    outfile.close();
    
    return 0;

}