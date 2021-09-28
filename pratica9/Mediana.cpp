#include "Mediana.h"

void Mediana::insere(int x) {
    if(f1.size() == 0){
        f1.push(x); //inserimos o elemento na fila 1
    }
    else if(f1.size() == 1 && f2.size() == 0){//caso a fila 1 já possua algum elemento e a fila 2 estiver vazia
        if(x > f1.top()){//se o elemento for maior que o maior elemento do heap
            f2.push(-x); //coloca-se o negativo do elemento na fila 2
        }
        else{ //caso não seja maior, colocamos o maior elemento da fila 1 na fila 2, só que negativo
            f2.push(-f1.top());
            f1.pop();//removemos o primeiro elemento inserido da fila 1
            f1.push(x);//colocamos x na fila 1
        }
    }
    else{ //caso haja algum elemento na fila 1
        if(x < f1.top()){ // se x for menor que o maior elemento da fila 1
            f1.push(x); //colocamos x
        }
        else{
            f2.push(-x);//caso contrario, colocamos o negativo na fila 2
        }
    }

    if(f1.size() - f2.size() > 1){ //se o tamanho da fila 1 menos o tam de f2 for maior que 1
        f2.push(-f1.top()); //colocamos o maior elemento de f1, só que negativo em f2, e removes de f1
        f1.pop();//retiramos o maior elemento de f1
    } 
    else if(f2.size() - f1.size() > 1) {//caso o tam de 2 - 1 for maior que 1
            f1.push(-f2.top()); //fazemos o contrario das operações acima
            f2.pop();
    }
}

int Mediana::getMediana() {
    if (f1.size() == f2.size()){
         return ((f1.top() - f2.top())/2);
    }
    else if(f1.size() > f2.size()){ 
        return f1.top();
    }
    else{
        return -f2.top();
    }
}