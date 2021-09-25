#include "Mediana.h"

void Mediana::insere(int x) {
    if (f1.size() == 0){
        f1.push(x);
    }
    else if (f1.size() == 1 && f2.size() == 0){
        if (x > f1.top()){
            f2.push(-x);
        }
        else{
            f2.push(-f1.top());
            f1.pop();
            f1.push(x);
        }
    }
    else{
        if (x < f1.top()){
            f1.push(x);
        }
        else{
            f2.push(-x);
        }
    }

    if (f1.size() - f2.size() > 1) {
        f2.push(-f1.top());
        f1.pop();
    } 
    else if (f2.size() - f1.size() > 1) {
            f1.push(-f2.top());
            f2.pop();
    }
}

int Mediana::getMediana() {
    if (f1.size() == f2.size()) return ((f1.top() - f2.top()) / 2);
    else if (f1.size() > f2.size()) return f1.top();
    else return -f2.top();
}