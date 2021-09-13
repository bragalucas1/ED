#include <iostream>
#include "MyList2NewIterator.h"
#include "MyVecNewIterator.h"
using namespace std;

template <class CONTAINER>
void testaContainer() {
  CONTAINER v;
  v.push_back('a');
  for(int i=1;i<10;i++) {
    v.push_back('a'+i);
  }

  //usando iteradores...
  cout << "Imprimindo usando iteradores.." << endl;
  for(const char &c:v){ //e' uma boa pratica usar const aqui, visto que nao vamos alterar c
    cout << c << " ";
  }
  cout << endl;

  for(char &c:v){ 
    c++;
  }

  for(const char &c:v){
    cout << c << " ";
  }
  cout << endl;
}



void testaMyList2() {
  MyList2<char> v;
  v.push_back('a');
  for(int i=1;i<10;i++) {
    v.push_back('a'+i);
  }

  //usando iteradores...
  cout << "Imprimindo usando iteradores.." << endl;
  for(const char &c:v){ //e' uma boa pratica usar const aqui, visto que nao vamos alterar c
    cout << c << " ";
  }
  cout << endl;

  for(char &c:v){ //exercicio: o que aconteceria se c nao fosse por referencia aqui?
    c = c + 1;
  }

  for(const char &c:v){ //exercicio: o que aconteceria se c nao fosse por referencia aqui?
    cout << c << " ";
  }
  cout << endl;
}

void testaMyVec() {
  MyVec<char> v;
  v.push_back('a');
  for(int i=1;i<10;i++) {
    v.push_back('a'+i);
  }

  //usando iteradores...
  cout << "Imprimindo usando iteradores.." << endl;
  for(const char &c:v){ //e' uma boa pratica usar const aqui, visto que nao vamos alterar c
    cout << c << " ";
  }
  cout << endl;

  for(char &c:v){ 
    c = c + 1;
  }

  for(const char &c:v){
    cout << c << " ";
  }
  cout << endl;
}

int main() {
  cout << "Chamando testa my list 2" << endl;
  testaMyList2();
  cout << endl;

  cout << "Chamando testa my vector" << endl;
  testaMyVec();
  cout << endl;

  
  //descomente para ver os testes usando templates
  //como as duas funcoes sao basicamente identicas, podemos usar templates para gerar
  //codigo para elas automaticamente!

  cout << "Usando templates para my list 2" << endl;
  testaContainer<MyList2<char> >();
  cout << endl;

  cout << "Usando templates para my vec" << endl;
  testaContainer<MyVec<char> >();
  cout << endl;
  

  return 0;  
}
