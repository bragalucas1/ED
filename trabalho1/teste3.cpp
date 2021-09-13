#include <iostream>
#include <sstream>
#include <fstream>
#include <string>



using namespace std;

int main(){
    stringstream lana;
    string alo;
    ifstream datainput;
    datainput.open("precos.csv");
    string armazena[500];
    string teste;
    string t2;
    int size = 0;
    int cont = 0;
    int cont2 = 0;
    /*while(!lana.eof){
        getline(cin,alo);
    }*/
    if(!datainput.is_open()){
       throw "Arquivo inexistente."; //Tratamento de exceção"
   }
    
   
    while(!datainput.eof()){
        while(getline(cin,alo)){
        for(int i = 0; i < alo.length();i++){
            if(alo[i]== ','){
                alo[i] = '\n';
                }
            }
        /*lana << alo;
        cout << alo << endl;
        cont++*/
        }
    }

    cout << cont << endl;

   /* lana >> t2;

    cout << t2 << endl;
    lana >> teste;
    cout << teste << endl;
    */
    /*while(lana){
        cont2++;
        lana >> t2;
        if(cont2 == 1){
            armazena[size] = t2;
            size++;
        }
        if(cont2 == 8){
            cont2 = 0;
        }
    }
    for(int i = 0; i < size; i++){
        cout << armazena[i] << endl;
    
    }*/
    /*lana >> t2;
    lana >> t2;
    lana >> t2;
    lana >> t2;*/
    
    /*for(int i = 0; i < size; i++){
        cout << armazena[i] << endl;
    }*/
    //cout << t2 << endl;
    



    return 0;



}