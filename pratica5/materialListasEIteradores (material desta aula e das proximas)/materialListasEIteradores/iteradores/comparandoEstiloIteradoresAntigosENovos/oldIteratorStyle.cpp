#include <iostream>
#include "MyList2.h"
using namespace std;



int main() {
  MyList2<char> v,u;
  v.push_back('a');
  for(int i=1;i<10;i++) {
    v.push_back('a'+i);
  }

    
  for(MyList2<char>::iterator it = v.begin();it!=v.end();it = v.next(it)) {
    cout << v.deref(it) << " ";    
  }
  cout << endl;



  return 0;  
}
