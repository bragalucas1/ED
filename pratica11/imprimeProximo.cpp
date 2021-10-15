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

            if(it == bd.end()){ //nao possui numero maior
                cout << "FALHA" << endl;
                continue;
            }
            it++;
            if(it == bd.end()){ //nao tem sucessor
                cout << "FALHA" << endl;
                continue;
            }else cout << *it << endl;
        }

    }
    return 0;
}