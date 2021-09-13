#include <iostream>
#include "MyVecNewIterator.h"
using namespace std;



int main() {
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

  // 
  cout << "Comparando usando operador <.." << endl;
  for(MyVec<char>::iterator it = v.begin(); it < v.end();it++){
    cout << *it << " ";
  }
  cout << endl;

  //Pulando elementos...
  cout << "Comparando usando operador <.." << endl;
  for(MyVec<char>::iterator it = v.begin(); it < v.end();it+=2){ //Exercicio: por que nao utilizar o operador != ?
    cout << *it << " ";
  }
  cout << endl;

  cout << "Comparando iteradores..." << endl;
  MyVec<char>::iterator it3 = v.begin()+5;
  MyVec<char>::iterator it4 = v.begin()+2;
  if (it3<it4) {
    cout << "begin+5 < begin+2" << endl;
  } else {
    cout << "begin+5 >= begin+2" << endl;
  }

  //
  cout << "Usando acesso aleatorio" << endl;
  for(int i=0;i<v.size();i++) {
    cout << *(v.begin()+i) << " " ;
  }
  cout << endl;


  cout << "Testando atribuicao elemento apontado por iterador" << endl;
  cout << "Antes: " << endl;
  for(MyVec<char>::iterator it = v.begin(); it < v.end();it+=2){ //Exercicio: por que nao utilizar o operador != ?
    cout << *it << " ";
  }
  cout << endl;

  for(MyVec<char>::iterator it = v.begin(); it < v.end();it+=2){ //Exercicio: por que nao utilizar o operador != ?
    *it = *it + 1;
  }

  cout << "Depois: " << endl;
  for(MyVec<char>::iterator it = v.begin(); it < v.end();it+=2){ //Exercicio: por que nao utilizar o operador != ?
    cout << *it << " ";
  }
  cout << endl;
 
  return 0;
  
}
