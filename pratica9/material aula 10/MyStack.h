#ifndef MyStack_H__
#define MyStack_H__

#include "MyVecNewIterator.h"

template<class T>
class MyStack {
public:
	void push(const T&el) {vec.push_back(el);}
	const T & top() const { return vec[ vec.size()-1]; } //mostra o elemento que esta no topo - referencia p nao copiar e const para nao mudar o topo
	void pop() { vec.pop_back(); } //
	bool empty() const { return vec.empty(); }
	int size() const { return vec.size(); }
private:
	MyVec<T> vec;
};


#endif