#include <iostream>

using namespace std;

void encontraPosicoes(const int numeros[],int posicoes[], int n){
    for(int i=0;i<n;i++){  //para cada numero i, descobre em qual posicao de numeros[] ele se encontra
		for(int j=0;j<n;j++){//varre o array procurando a posicao onde i se encontra
			if(numeros[j]==i){
				posicoes[i] = j; //o numero i se encontra na posicao j do array...
				break;
                }
				
			}
            
		}
        
}

int main(){
    int n;
	cin >> n;

	int *numeros = new int[n];
	int *posicoes = new int[n];

	//le a permutacao de numeros.
	for(int i=0;i<n;i++) cin >> numeros[i];
    for(int i=0;i<1000000;i++) { //Vamos medir o tempo de 1000 chamadas ! NAO altere isso!!!
		encontraPosicoes(numeros,posicoes,n);
	}	

    for(int i=0;i<n;i++) cout << posicoes[i] << " ";
	cout << "\n";
    delete []numeros;
	delete []posicoes;
    return 0;
}