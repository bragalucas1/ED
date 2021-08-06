#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

void selectionSort(int *v, int n) {
    for (int i = 0; i < n-1; i++) {
        // acha a posicao do menor elemento
        // entre as posições (i) e (n-1)
        int posMenor = i;
        for (int j = i+1; j < n; j++)
            if (v[j] < v[posMenor])
                posMenor = j;

        // troca o menor elemento (que está na
        // posicao posMenor) com o elemento (i)
        int aux = v[i];
        v[i] = v[posMenor];
        v[posMenor] = aux;
    }
}



struct Pessoa {
	string nome;
	int cpf;
	double altura;
};



void ordenaPessoas(Pessoa *pessoas,int n) {
	for (int i = 0; i < n-1; i++){
		string aux;
		int cpfaux;
		double alturaaux;
		int posMenor = i;
		for (int j = i+1; j < n; j++)
            if (pessoas[j].nome < pessoas[posMenor].nome)
                posMenor = j;
				pessoas[posMenor+1].nome = pessoas[posMenor].nome;
				pessoas[posMenor+1].cpf = pessoas[posMenor].cpf;
				pessoas[posMenor+1].altura = pessoas[posMenor].altura;
		
		aux = pessoas[i].nome;
        pessoas[i].nome = pessoas[posMenor].nome;
        pessoas[posMenor].nome = aux;
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