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



void ordenaPessoas(Pessoa *pessoas,int n) { //aplicação do metódo selectionsort para ordenar struct
	for (int i = 0; i < n-1; i++){
		int ct = 0;
		string aux = pessoas[i].nome;   //passada do parametro para variaveis auxiliares
		int auxcpf = pessoas[i].cpf;
		double aux2 = pessoas[i].altura;
		int posMenor = i;
		for (int j = i+1; j < n; j++){
            if(pessoas[posMenor].nome == pessoas[j].nome){ //verifica o caso de ter nomes iguais
				string troca1 = pessoas[posMenor].nome;       //nesta etapa, funciona semelhante o algoritmo da bolha, 
				int troca2  = pessoas[posMenor].cpf;		 //realizando a troca das variáveis de nome igual
				double troca3 = pessoas[posMenor].altura;

				pessoas[posMenor].nome = pessoas[j].nome;    //atribui o valor da menor funçao, jogando a pra posição de cima
				pessoas[posMenor].cpf = pessoas[j].cpf;
				pessoas[posMenor].altura = pessoas[j].altura;

				pessoas[j].nome = troca1;					//reatribui os valores inerentes do nome com maior cpf
				pessoas[j].cpf = troca2;
				pessoas[j].altura = troca3;
				}
	
			if(pessoas[j].nome < pessoas[posMenor].nome){  //caso onde não há nomes iguais
                posMenor = j;
			}
			
		}
        pessoas[i].nome = pessoas[posMenor].nome;      //atribuição e passagem de valores;
        pessoas[posMenor].nome = aux;
		pessoas[i].cpf = pessoas[posMenor].cpf;
		pessoas[posMenor].cpf = auxcpf;
		pessoas[i].altura = pessoas[posMenor].altura;
		pessoas[posMenor].altura = aux2;
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