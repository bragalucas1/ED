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
  for(typename CONTAINER::iterator it = v.begin(); it!=v.end();it++){
    cout << *it << " ";
  }
  cout << endl;

  //Modificando usando iteradores
  for(typename CONTAINER::iterator it = v.begin(); it != v.end();it++){ //Exercicio: por que nao utilizar o operador != ?
    *it = *it + 1;
  }

  for(typename CONTAINER::iterator it = v.begin(); it!=v.end();it++){
    cout << *it << " ";
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
  for(MyList2<char>::iterator it = v.begin(); it!=v.end();it++){
    cout << *it << " ";
  }
  cout << endl;




  //Modificando usando iteradores
  for(MyList2<char>::iterator it = v.begin(); it != v.end();it++){ //Exercicio: por que nao utilizar o operador != ?
    *it = *it + 1;
  }

  for(MyList2<char>::iterator it = v.begin(); it!=v.end();it++){
    cout << *it << " ";
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
  for(MyVec<char>::iterator it = v.begin(); it!=v.end();it++){
    cout << *it << " ";
  }
  cout << endl;

  //Modificando usando iteradores
  for(MyVec<char>::iterator it = v.begin(); it != v.end();it++){ //Exercicio: por que nao utilizar o operador != ?
    *it = *it + 1;
  }

  for(MyVec<char>::iterator it = v.begin(); it!=v.end();it++){
    cout << *it << " ";
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

  /*
  //descomente para ver os testes usando templates
  //como as duas funcoes sao basicamente identicas, podemos usar templates para gerar
  //codigo para elas automaticamente!
  
  cout << "Usando templates para my list 2" << endl;
  testaContainer<MyList2<char> >();
  cout << endl;

  cout << "Usando templates para my vec" << endl;
  testaContainer<MyVec<char> >();
  cout << endl;
  */

  return 0;  
}
