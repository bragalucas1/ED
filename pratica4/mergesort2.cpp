#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cassert>
using namespace std;


/* Supondo que v[p...q-1] e 
v[q...r-1] estejam ordenados */
void merge(int *v, int *vaux, int p, int q, int r) {//passa como argumento o novo vetor auxiliar,
    int tam = r-p;
    int i = p; //cursor 1
    int j = q; //cursor 2
    int k = 0; //cursor para aux
    while(i < q && j < r) {
        if (v[i] <= v[j])
            vaux[k++] = v[i++]; //vetor auxiliar alocado em outra função, sendo usado aqui apenas quando chamado
        else
            vaux[k++] = v[j++];
    }
    while(i < q)
        vaux[k++] = v[i++];
    while(j < r)
        vaux[k++] = v[j++];
    for(k = 0; k < tam; k++)
        v[p+k] = vaux[k];    
    
}

/* Ordena o vetor v entre as posicoes p e r-1 */
void mergeSort(int *v, int *vaux, int p, int r) {//passa como argumento o novo vetor auxiliar
    // com um elemento, já está ordenado
    if (p < r-1) {
        int meio = (p+r) / 2;
        mergeSort(v, vaux, p, meio);//passa como argumento o novo vetor auxiliar
        mergeSort(v, vaux, meio, r);//passa como argumento o novo vetor auxiliar
        merge(v, vaux, p, meio, r); //intercala
    }
}


void mergeSort(int *v, int n) {//
    //faca a alocacao aqui (apenas uma vez) e passe o array para que a versao recursiva do metodo possa utiliza-lo..
    int *newvet = new int[n]; //alocação APENAS AQUI.
    
    mergeSort(v,newvet,0, n); 
   
    delete  []newvet;
}

//nao modifique nada daqui para baixo...

int main(int argc, char**argv) {
	//sem srand, para sempre usarmos a mesma semente...
	int n;
	cin >> n;
	int *v = new int[n];

	for(int i=0;i<n;i++) cin >> v[i];

	int soma = 0;

	//Mede o tempo de 10000 execucoes em microsegundos
	auto t0 = std::chrono::system_clock::now();
	mergeSort(v,n);
	auto tempoSort = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	cerr << "Tempo para ordenar (us): " << tempoSort.count() << "\n";

	for(int i=0;i<n-1;i++) assert(v[i]<=v[i+1]);
	cout << "ok\n";

	delete []v;
	return 0;
}