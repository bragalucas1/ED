#include <iostream>
#include "MyList2Rascunho.h"
using namespace std;

template <class T>
T& getElement(Node<T> *primeiro,int n) {
  if(n==0) return primeiro->data;
  else return getElement(primeiro->next,n-1);
}

template <class T>
void imprimeTrasFrente(Node<T> *primeiro) {
  if(primeiro==NULL) { return; }
  imprimeTrasFrente(primeiro->next);
  cout << primeiro->data << " ";
  
}

int main() {
  MyList2<char> v;
  v.push_back('a');
  for(int i=1;i<10;i++) {
    v.push_back('a'+i);
  }

  imprimeTrasFrente(v.begin());
  cout << endl;



  return 0;
  
}
