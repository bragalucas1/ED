#include <iostream>
#include "MyListRascunho.h"
using namespace std;



int main() {
  MyList<char> v;
  //cout << v << endl;
  v.push_back('a');
  //cout << v << endl;  
  for(int i=1;i<10;i++) {
    v.push_back('a'+i);
    //cout << v << endl;
  }


  { //testando criacao e destrucao de vetor vazio..
    MyList<char> v2;
  }

  {
    //copias de vetor vazio
    MyList<char> v2;
    MyList<char> v3 = v2; //construtor de copia
    v3 = v2;

    v2 = v;
    v2 = v;
    v3 = v;

    MyList<char> v4 = v2;
  }

  cout << v << endl;
  cout << "Inserindo 0 apos o primeiro elemento da lista: " << endl;
  //qual o problema com esse "insert" ?
  v.insert('0',v.begin());
  cout << v << endl;


  //suponha que tudo seja publico na classe MyList.
  //como poderiamos imprimir todos os elementos?
  //faca isso aqui:




  //por que e' interessante que o end() nao seja o ultimo elemento da lista?
  //implemente o codigo anterior usando nossos iteradores (isso sera melhorado no futuro!):







  MyList<char>::iterator it = v.begin();
  it = v.next(it);
  it = v.next(it);
  it = v.next(it);
  v.insert('w',it);

  cout << v << endl;

  while(v.next(it)!=v.end()) it = v.next(it);
  v.insert('z',it);

  cout << v << endl; 
  

  return 0;
  
}
