#include <iostream>
#include "MyVecNewIterator.h"
#include "MySet.h"
#include <string>
#include <cstring>

using namespace std;
int main(int argc, char **argv){
    string s;
    int cont = 0;
    bool auxiliar = false;

    if(strcmp(argv[1], "myvec") == 0){ //tratamos o caso de entrada como myVec
        MyVec<string> v;
        while(cin >> s){
            auxiliar = false;
            for(int i = 0; i < v.size(); i++){
                if(v[i] == s){
                    auxiliar = true;
                    break;
                }
            }   
            if(!auxiliar){
                v.push_back(s);
            }
            cont++;
            //cout << cont << " " << v.size() << endl;
        }
        cout << cont << " " << v.size() << endl;
    }
    else{//caso sobresssalente -- MYSET
        MySet<string> v;
        while(cin >> s){
            v.insert(s);  
            cont++;
        }
    cout << cont << " " << v.size() << endl;
    }
    return 0;

}