#include <iostream>
#include "MySet.h"
using namespace std;

int main(){
    MySet<long long int> bd;
    char c;
    long long int n;
    while(cin >> c >> n){
        if(c == 'C'){
            bd.insert(n);
        }
         else if(c == 'S'){
            MySet<long long int>::iterator it = bd.find(n);

            if(it == bd.end()){ //aqui verificamos se esse número ja está cadastrado, visto que end retorna NULL
                cout << "FALHA" << endl;
                continue;
            }   
            it++; //andamos com o iterador por meio do pos incremento
            if(it == bd.end()){ //nao tem sucessor - ele é o maior no banco de dados
                cout << "FALHA" << endl;
                continue;
            }
            else cout << *it << endl;  
        }

    }
    return 0;
}