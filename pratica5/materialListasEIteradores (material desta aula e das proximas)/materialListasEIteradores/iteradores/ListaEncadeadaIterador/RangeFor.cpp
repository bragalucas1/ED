#include <iostream>
#include "MyList2NewIterator.h"
#include "MyVecNewIterator.h"
using namespace std;


int main() {
  int v[4] = {10,5,4,12};

  //acessando
  for(int i=0;i<4;i++) 
    cout << v[i] << " ";
  cout << endl;

  //pode ser escrito:
  for(const int x:v) // x nao precisa ser const, mas isso e' uma boa pratica
    cout << x << " ";
  cout << endl;

  //ou:

  //nesse caso estamos acessando os proprios elementos de v, nao copias deles
  //uma vantagem disso eh a performance (principalmente se o tipo for grande!!!)
  //isso eh algo MUITO IMPORTANTE! Sempre use referencias para tipos nao triviais (!= float, char, int, double, bool)
  for(const int &x:v) 
    cout << x << " ";
  cout << endl;

  //----------------------------

  //gravando
  for(int i=0;i<4;i++) 
    v[i] = 100;

  //pode ser escrito:
  for(int &x:v) // x precisa ser referencia, caso contrario estariamos modificando uma copia dos elementos...
    x = 100;


  return 0;  
}
