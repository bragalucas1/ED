#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

//Busca binaria
//Pesquisa pelo elemento "chave" entre as posicoes begin e end (inclusive) do array 
//Retorna -1 se elemento nao esta no array
int buscaBin(int *array,int begin, int end, int chave) {
	if (begin > end) return -1;
	int meio = (end-begin)/2 + begin;
	if (array[meio] == chave)
		return meio;
	if (array[meio] > chave)
		return buscaBin(array,begin, meio-1, chave); 
	return buscaBin(array,meio+1, end, chave); 	
}

//Busca binaria iterativa
//Pesquisa pelo elemento "chave" entre as posicoes begin e end (inclusive) do array 
//Retorna -1 se elemento nao esta no array
int buscaBinIterativa(int *array,int begin, int end, int chave) {
	while(begin <= end){
		int meio = (end-begin)/2 + begin;
		if (array[meio] == chave)
			return meio;
		if (array[meio] > chave) 
			end =  meio-1; 
		else begin = meio+1; 
	}
	return -1;	 	
}

//Busca sequencial
//Pesquisa pelo elemento "chave" entre as posicoes begin e end (inclusive) do array 
//Retorna -1 se elemento nao esta no array
int buscaSeq(int *array,int begin,int end, int chave) {
	for(int i=begin;i<=end;i++)
		if (array[i] == chave)
			return i;
	return -1;
}



int main(int argc, char**argv) {
	//sem srand, para sempre usarmos a mesma semente...
	int n = atoi(argv[1]);
	int *v = new int[n];

	for(int i=0;i<n;i++) v[i] = i;

	int soma = 0;

	//Mede o tempo de 10000 execucoes em microsegundos
	auto t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000;i++) {
		soma += buscaSeq(v,0,n-1,rand()%n);
	}	
	auto tempoSeq = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);


	t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000;i++) {
		soma += buscaBin(v,0,n-1,rand()%n);
	}	
	auto tempoBin = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	
	t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000;i++) {
		soma += buscaBinIterativa(v,0,n-1,rand()%n);
	}	
	auto tempoBinIt = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

	cout << "Busca sequencial (repetidas 10000x):        " << setw(10)<< tempoSeq.count() << "\n";
	cout << "Busca binaria (repetidas 10000x):           " << setw(10)<< tempoBin.count() << "\n";
	cout << "Busca binaria iterativa (repetidas 10000x): " << setw(10)<< tempoBinIt.count() << "\n";
	cout << "Soma: " << soma << endl;
	soma = 0;


	delete []v;
	return 0;
}