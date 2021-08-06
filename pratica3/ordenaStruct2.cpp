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
		int ct = 0;
		string aux = pessoas[i].nome; 
		int auxcpf = pessoas[i].cpf;
		double aux2 = pessoas[i].altura;
		int posMenor = i;
		for (int j = i+1; j < n; j++){
            if(pessoas[posMenor].nome == pessoas[j].nome){
				string troca1 = pessoas[posMenor].nome;
				int troca2 =	pessoas[posMenor].cpf;
				double troca3 = pessoas[posMenor].altura;

				pessoas[posMenor].nome = pessoas[j].nome;
				pessoas[posMenor].cpf = pessoas[j].cpf;
				pessoas[posMenor].altura = pessoas[j].altura;

				pessoas[j].nome = troca1;
				pessoas[j].cpf = troca2;
				pessoas[j].altura = troca3;
				}
			
			
			if(pessoas[j].nome < pessoas[posMenor].nome){
                posMenor = j;
			}
			
		}
			
			
			
		
		
		/*if(pessoas[i].nome == pessoas[i].nome){
			pessoas[i+1].nome = pessoas[i].nome; //realiza a ordenação baseado no cpf menor
			pessoas[i+1].cpf = pessoas[i].cpf;
			pessoas[i+1].altura = pessoas[i].altura;
			}
		}*/
		
		cout << ct << "  " << endl;
        pessoas[i].nome = pessoas[posMenor].nome;
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