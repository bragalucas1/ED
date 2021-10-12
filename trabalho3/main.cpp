#include <iostream>
#include <cassert>
#include <fstream>
#include "Huffman.h"
#include "Huffman.cpp"

using namespace std;

int main(int argc, char **argv){
    //Declaração de variáveis.
    int freqs[256] = {0};
    string line1 = "", c = "c"; 


    //Abertura dos arquivos responsáveis pelas operações.
    ifstream innerfile(argv[2]);
    ifstream outfile(argv[3]);
    /*Nessa etapa do código, calculamos a frequẽncia (no caso de uma entrada para comprimir) de cada caracter do arquivo 
    de entrada, e passamos para o construtor da árvore e fazemos as aritmeticas de construção do código, compressão e passagem 
    pro arquivo de saída.*/

    if(argv[1] == c){ 
        if(!innerfile.is_open()){
            throw "Couldn't open file.";
        }

        MyVec<bool> comprimido;
        MyVec<char> in;
        while(getline(innerfile,line1)){
            for(int i = 0; i < line1.size(); i++){
                unsigned char ch = line1[i];
                if(line1[i] == ch){
                    freqs[ch]++;
                }
            }
        }
        /*for(int i = 0; i < 256; i++){
            unsigned char ch = i;
            cout << i <<  ": " << ch << " " << freqs[ch] << endl;
        }*/
       
        HuffmanTree arvore(freqs);
        arvore.auxiliar();
        arvore.comprimir(comprimido,in);
        cout << "File compression suceed!" << endl;
        for(int i=0;i< comprimido.size();i++){
		    cout << comprimido[i];
	    }

	    //cout << endl;
        
    }

    if(argv[1] == "d"){
        
    }









    //Fechamento dos arquivos.
    innerfile.close();
    outfile.close();
    
    return 0;

}