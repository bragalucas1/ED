#include <iostream>
#include "MyVec.h"
using namespace std;





void exemplosAula() {
  MyVec<int> v;
  for(int i=0;i<5;i++) v.push_back(10*i);
  for(int i=0;i<5;i++) cout << v[i] << " " ; cout << endl;
  cout << v << endl;

  v.pop_back();
  cout << v << endl;
  v.insert(500,2);
  cout << v << endl;

  MyVec<int> v2(5,1);
  cout << v2 << endl;


  MyVec<MyVec<int> > matriz(15,MyVec<int>(10,0));
  for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++)
      cout << matriz[i][j] << " ";
    cout << endl;
  }

  for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++)
      matriz[i][j] = i*10+j;
  }
  cout << endl;
  for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++)
      cout << matriz[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  cout << matriz << endl;

  //Exercicio: como poderiamos utilizar essa classe para resolver a questao
  //1 da prova?
  //precisariamos de construtores, destrutores, operador de atribuicao, etc?
}

int main() {
  exemplosAula(); 


  MyVec<char> v;
  cout << v << endl;
  v.push_back('a');
  cout << v << endl;  
  for(int i=1;i<10;i++) {
    v.push_back('a'+i);
    cout << v << endl;
  }


  { //testando criacao e destrucao de vetor vazio..
    MyVec<char> v2;
  }

  {
    //copias de vetor vazio
    MyVec<char> v2;
    MyVec<char> v3 = v2; //construtor de copia
    v3 = v2;

    v2 = v;
    v2 = v;
    v3 = v;

    MyVec<char> v4 = v2;
  }

  v.insert('0',0);
  cout << v << endl;
  v.insert('z',v.size());
  cout << v << endl;

  try {
    v.insert('-', -1);
  } catch (const MyVecException & e) {
    cout << e.what() << endl;
  }



  try {
    v.insert('-', 1000);
  } catch (const MyVecException & e) {
    cout << e.what() << endl;
  }

  v.insert('+',3);
  cout << v << endl;

  MyVec<char> v2;
  v2 = v;

  v.push_back('z');
  cout << v << endl;
  cout << v2 << endl;

  v2.push_back('w');
  cout << v << endl;
  cout << v2 << endl;

  v.resize(1);
  cout << v << endl;

  v.resize(0);
  cout << v << endl;

  v.push_back('q');
  cout << v << endl;


  v.resize(5);
  cout << v << endl;

  for(int i=0;i<5;i++)
    v[i] = 'x';

  cout << v << endl;

  v.resize(6);
  v[5] = 'y';
  cout << v << endl;

  v.resize(3);
  cout << v << endl;


  


  return 0;
  
}
