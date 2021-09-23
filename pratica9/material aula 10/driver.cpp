#include <iostream>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
#include "MyStack.h"
#include "MyQueue.h"


void etapa1(){
	MyStack<int> pilha;
	MyQueue<int> fila;

	int elem = 0;

	for(int i = 0; i < 6; i++){
			cin >> elem;
			fila.push(elem);
			pilha.push(elem);
	}

/*Ao final, ele deve imprimir o conteudo da pilha (com um espaco em branco após cada elemento), 
uma nova linha, o conteudo da fila e uma nova linha.*/
	while(!pilha.empty()){
		cout << pilha.top() << " ";
		pilha.pop();
	}
	cout << "\n";
	
	while(!fila.empty()){
		cout << fila.top() << " ";
		fila.pop();
	}
	cout << "\n";

	//A diferença entre a ordem dos numeros é que: nas pilhas o ultimo a entrar é o primeiro a sair (LIFO), 
	//e nas filas o acesso é feito da forma FIFO, o primeiro a entrar é o primeiro a sair -- a ordem é inversa uma da outra.
	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2(){
	MyStack<char> s;
	char caracter;
	while (cin >> caracter){
		if(s.empty() && (caracter == ')') || (caracter == ']') || (caracter == '}')){
			s.push(caracter);
			break;
		}
		if((caracter == '(') || (caracter == '[') || (caracter == '{')){
			s.push(caracter);
		}
		if((s.top() == '(') && (caracter == ')')){
			s.pop();
		}
		else if((s.top == '[') && (caracter == ']')){
			s.pop();
		}
		else if((s.top == '{') && (caracter == '}')){
			s.pop();
		}	
	}
	if(s.empty()){
		cout << "Consistente" << "\n";
	}
	else{
		cout << "Inconsistente" << "\n";
	}
}

	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
//#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
	/*Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;*/
}

//---------------------------------------




int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}