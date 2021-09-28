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
	while(!pilha.empty()){ //enquanto há algo para ser processado
		cout << pilha.top() << " ";
		pilha.pop();
	}
	cout << "\n";
	
	while(!fila.empty()){ //enquanto há algo para ser processado
		cout << fila.front() << " ";
		fila.pop();
	}
	cout << "\n";

	//A diferença entre a ordem dos numeros é que: nas pilhas o ultimo a entrar é o primeiro a sair (LIFO), 
	//e nas filas o acesso é feito da forma FIFO, o primeiro a entrar é o primeiro a sair -- a ordem é inversa uma da outra.
	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2(){
//Para ser consistente, deve haver o mesmo numero de simbolos, e na ordem correta: abre --> fecha;
	MyStack<char> pilha;

	char c;


	while (cin >> c){
		if(c == '(' || c == '[' || c == '{' ){ //caso vejamos algo que ''abre'' colocamos na pilha
			pilha.push(c);
		}
		else if(c == ')'){
			if(pilha.empty() || pilha.top() != '('){ //se a pilha estiver vazia ou se o topo não for o que fecha o caracter
				cout << "Inconsistente" << endl; //está errado e retorna
				return; 
			}
			else{
				pilha.pop(); //©aso for igual, apenas remove.
			}
		}
		else if(c == '}'){
			if(pilha.empty() || pilha.top() != '{'){//se a pilha estiver vazia ou se o topo não for o que fecha o caracter
				cout << "Inconsistente" << endl;  //está errado e retorna
				return;
			}
			else{
				pilha.pop();//©aso for igual, apenas remove.
			}
		}
		else if(c == ']'){//se a pilha estiver vazia ou se o topo não for o que fecha o caracter
			if(pilha.empty() || pilha.top() != '['){
				cout << "Inconsistente" << endl; 
				return;
			}
			else{
				pilha.pop();
			}
		}

	}

	if(pilha.empty()){ //se a pilha estiver vazia = removemos todos os pares - tudo ok.
		cout << "Consistente" << endl;
	}
	else{ //pilha não vazia - sobrou algo que abre ou fecha. 
		cout << "Inconsistente" << endl;
	}
	
}

	

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
	Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;
}

//---------------------------------------
//O método que usa pilha visita todos os elementos mais próximos
//ao último visitado, já o método que usa fila visita todo um caminho até acabar, 
//caso não ache a saída ele volta e tenta outro caminho



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