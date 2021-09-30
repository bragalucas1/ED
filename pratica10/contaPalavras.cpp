#include <iostream>
#include "MyVecNewIterator.h"
#include "MySet.h"
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char **argv){
    string new;
    int cont = 0;
    bool auxiliar = false;

    if(strcmp(argv[1], "myvec") == 0){
        MyVec<string> v;
        while(cin >> new){
            for(int i = 0; i < v.size(); i++){
                if(v[i] == new){
                    auxiliar = true;
                    break;
                }
            }   
            if(!auxiliar){
                v.push_back(new);
                cont++;
            }
            cout << cont << " " << v.size() << endl;
        }
    }
    else{
        
    }


}