#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

//Vamos usar variaveis globais nesse caso...
//Isso nao é uma boa pratica, mas vai facilitar no seu entendimento/implementacao da busca binaria
int taxaVideo,taxaDownload,tamanho;

//Essa funcao devera retornar true sse for possível 
//assistir a um vídeo de "tamanho" segundos, que gasta taxaVideo bytes por segundo para ser assistido
//supondo que sua internet consegue baixar taxaDownload bytes por segundo.
//tempoCarregamento indica quanto tempo voce irá aguardar para começar assistir ao vídeo
//Implemente esta funcao
bool consigoAssistirSemPausas(int tempoCarregamento) {
	int DownloadedBytes;
	DownloadedBytes = taxaDownload*tempoCarregamento;

	for(int i = 0; i<tamanho; i++){
		DownloadedBytes = DownloadedBytes - taxaVideo + taxaDownload; //15 + 3 - 10 = 8 bytes - retirado do pdf e adaptado
	}
	if(DownloadedBytes > 0){
		return true;
	}
	else{
		return false;
	}
}

int buscaBin(bool *array,int begin, int end, bool chave) {
	if (begin > end) return -1;
	int meio = (end-begin)/2 + begin;
	if (array[meio] == chave)
		return meio;
	if (array[meio] > chave)
		return buscaBin(array,begin, meio-1, chave); 
	return buscaBin(array,meio+1, end, chave); 	
}

int main(){
    cin >> taxaVideo >> taxaDownload >> tamanho;

    bool *resultado = new bool[5000];
    for(int i=0;i<5000;i++){
        resultado[i] = consigoAssistirSemPausas(i);
    }
    cout << buscaBin(resultado,0,5000,1) << '\n';
    delete[] resultado;
    return 0;

}