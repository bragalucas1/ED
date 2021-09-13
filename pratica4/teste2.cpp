#include <fstream>
#include <iostream>
#include <string>
#include <cstring>  

using namespace std;

int main(){
    ifstream entrada;
    string teste[5];
    entrada.open("precos.csv");
    
    if(!datainput.is_open()){
       throw "Arquivo inexistente."; //Tratamento de exceção"
    }

    while(!entrada.eof()){
        getline(entrada, teste);
    }
    cout << teste << endl;
}