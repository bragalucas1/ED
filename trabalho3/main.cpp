#include <iostream>
#include <cassert>
#include <fstream>
#include "Huffman.h"

using namespace std;

int main(/*int argc, char **argv*/){
    


    //calculamos a frequencia aquu, e passamos para o construtor da arvore
    int a;
    char v;
    char elem;
    MyVec<char> s;

    s.insert('1');
    s.insert('2');
    s.insert('3');
    s.insert('4');
    cout << s.size() << endl;
    cout << s.top() << endl;
    swap(s[s.size()-1],s[0]);

    /*for(int i = 0; i < a; i++){
        cin >> v;
        s.push(v);
    }
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    Node<T> *novo = new Node(elem);
    novo->right = s.top();
    s.pop();
    novo->left = s.top();
    s.pop();
    Node<char> *n2;
    n2->left = novo;/*
    
    /*if(argc == 'c'){
        ifstream compressfile(argv[1]);

    }


    if(argc == 'd'){
        ifstream descompressfile(argv[1]);
    }
    */
    return 0;

}