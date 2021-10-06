#include <iostream>
#include "MyPriorityQueue.h"

void smallestChild(MyPriorityQueue<int> *s,int pos){
    while(2*pos+1 < s.size()){ //enquanto a posicao atual tiver pelo menos um filho...
		int menorFilho = 2*pos+1;
		if(2*pos+2 < s.size() && s[2*pos+2] > s[menorFilho]) //ha um segundo filho e ele eh maior do que o primeiro?
			menorFilho = 2*pos+2;
		if(s[pos] > s[menorFilho]){
			return; //nao precisamos continuar... por que?
		} else {
			swap(s[pos],s[menorFilho]); //troque o atual com o maior filho 
			pos = menorFilho; //repita o processo agora na posicao "maiorFilho"
		}
	}
}

}
using namespace std;
int main(){
    
    MyPriorityQueue<int> s;
    s.push(1);
    s.pop();
    s.push(2);
    s.push(3);
    s.push(4);
   
    s.push(5);
    s.push(6);

    s.print();
    smallestChild(s,0);
    return 0;
}