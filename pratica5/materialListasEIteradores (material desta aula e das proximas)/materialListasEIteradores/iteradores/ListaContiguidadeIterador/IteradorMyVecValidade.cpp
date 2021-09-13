#include <iostream>
#include "MyVecNewIterator.h"
using namespace std;


void f2() {
  int i = 0;
  cout << i++ << endl; //0
  cout << i << endl; //1

  int j = 0;
  cout << ++j << endl; //1
  cout << j << endl;  //1
  return ;



    MyVec<int> v;
    for(int i=0;i<3;i++) v.push_back(i);
    MyVec<int>::iterator it  = v.begin();
    for(int i=0;i<3;i++) cout << *(it+i) << " "; cout << endl;

    for(int i=4;i<10;i++) v.push_back(i);
    for(int i=0;i<3;i++) cout << *(it+i) << " "; cout << endl;

    for(int i=0;i<v.size();i++) v[i] = 0;
    for(int i=0;i<3;i++) cout << *(it+i) << " "; cout << endl;



}

int main() {
  f2();



  MyVec<char> v;
  v.push_back('a');
  for(int i=1;i<5;i++) {
    v.push_back('a'+i);
  }

  MyVec<char>::iterator it = v.begin();


  cout << "Valor de it antes de modificar valores: " <<  *it << endl;

 // for(int i=0;i<v.size();i++)
  //  v[i]++;

  cout << "Valor apontado por it antes de inserir: " << *it << endl;

  for(int i=5;i<7;i++) { //insere mais 2 elementos... 
    v.push_back('a'+i);
  }

  cout << "Apos inserir mais 2 elementos" << endl;
  cout << "Valor apontado por it apos inserir: " << *it << endl;
  cout << "Valor apontado por begin apos inserir: " << *(v.begin()) << endl;

  /*for(int i=0;i<v.size();i++)
    v[i] = '-';

  cout << "Valor apontado por it apos modificar valores novamente: " << *it << endl;
  cout << "Valor apontado por begin() apos modificar valores novamente: " << *(v.begin()) << endl; 
*/


  for(int i=7;i<9;i++) { //insere mais 2 elementos... 
    v.push_back('a'+i);
  }

  cout << "Apos inserir mais 2 elementos" << endl;
  cout << "Valor apontado por it apos inserir: " << *it << endl;
  cout << "Valor apontado por begin apos inserir: " << *(v.begin()) << endl;

  for(int i=0;i<v.size();i++)
    v[i] = '-';

  cout << "Valor apontado por it apos modificar valores novamente: " << *it << endl;
  cout << "Valor apontado por begin() apos modificar valores novamente: " << *(v.begin()) << endl; 
  
  //Exercicio: o que houve??? it deveria continuar apontando para "begin()", que vale '-' agora...


  return 0;
  
}
