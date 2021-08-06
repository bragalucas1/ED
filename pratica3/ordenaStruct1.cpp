#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

void insertionSort(int *v, int n) {
    for (int i = 1; i < n; i++) {
        // o arranjo entre as posicoes [0,i) já está ordenado
        int elemInserir = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > elemInserir) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = elemInserir;
    }
}

struct Pessoa {
	string nome;
	int cpf;
	double altura;
};

void ordenaCPF(Pessoa *pessoas, int n);//declaração de uma funçao que posteriormente será utilizada
void ordenaNome(Pessoa *pessoas, int n);//declaração de uma funçao que posteriormente será utilizada


void ordenaPessoas(Pessoa *pessoas,int n){ 
	for (int i = 1; i < n; i++){
		ordenaNome(pessoas,n);
		if(pessoas[i].nome == pessoas[i+1].nome){
			ordenaCPF(pessoas,n);
		}
		
	}
	
}
			
		


void ordenaCPF(Pessoa *pessoas, int n){
	for (int i = 1; i < n; i++){        
        
		
		int aux2 = pessoas[i].cpf;
		double aux3 = pessoas[i].altura;
		int j = i+1;
		while(j >= 0 && pessoas[j].cpf < aux2){
			
			pessoas[j+1].cpf = pessoas[j].cpf;
			pessoas[j+1].altura = pessoas[j].altura;
			j--;
		}
		
		
		pessoas[j+1].cpf = aux2;
		pessoas[j+1].altura = aux3;
	}
}

void ordenaNome(Pessoa *pessoas, int n){
	for (int i = 1; i < n; i++){ //implementação do insection sort
        string aux = pessoas[i].nome;                       
        int aux2 = pessoas[i].cpf;
		double aux3 = pessoas[i].altura;
		int j = i-1;										
        while(j >= 0 && pessoas[j].nome > aux){														
            pessoas[j+1].nome = pessoas[j].nome;
			pessoas[j+1].cpf = pessoas[j].cpf;
			pessoas[j+1].altura = pessoas[j].altura;
            j--;
        }
    	pessoas[j+1].nome = aux;
		pessoas[j+1].cpf = aux2;
		pessoas[j+1].altura = aux3;
    }
}

/*
Exemplo de entrada:
5
Dbc 123 1.8
Abc 194 1.7
Abc 125 1.9
Teste 100 1.1
Alto 300 3.2

Saida esperada:
Abc 125 1.9
Abc 194 1.7
Alto 300 3.2
Dbc 123 1.8
Teste 100 1.1
*/


//Não modifique nada daqui para baixo...
int main(int argc, char **argv) {
	//O arquivo de entrada contém um numero n. 
	//A seguir, há n linhas cada uma contendo o nome, cpf e altura de uma pessoa (separados por um espaço em branco)
	//O nome eh sempre composto de um unico token
	int n;
	cin >> n;
	Pessoa *pessoas = new Pessoa[n];
	for(int i=0;i<n;i++) {
		cin >> pessoas[i].nome >> pessoas[i].cpf >> pessoas[i].altura;
	}

	ordenaPessoas(pessoas,n);

	//imprime a saída ordenada
	for(int i=0;i<n;i++) {
		cout << pessoas[i].nome << " " <<  pessoas[i].cpf << " " <<  pessoas[i].altura << '\n';
	}


	delete []pessoas;
	return 0;
}