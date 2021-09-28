#ifndef MEDIANA_H
#define MEDIANA_H

#include <iostream>
#include "MyPriorityQueue.h"

using namespace std;

class Mediana{
    private:
    MyPriorityQueue<int> f1;
    MyPriorityQueue<int> f2;
    
    public:
    void insere(int x);
    int getMediana();
};

#endif