
#include <iostream>
#include <fstream>
#include <sstream>
#include "cotas.h"
using namespace std;
//construtor recebendo a alocação dinamica dos vetores
Cotas::Cotas(){
    this->_ticker = new string[500000];
    this->_data = new string[500000];
    this->_price = new double[500000];
}


bool Cotas::operator<(const Cotas &other)const{ //construção do operator '<'
    if(*this < other){
        return true;
    }
    else{
        return false;
    }
}

/******************************FUNÇÕES SETS***********************************/
void Cotas::set_price(const double price, int cursor){ //setando preço da açao
    this->_price[cursor] = price;   
    this->_price[cursor] += 0.000001;
    this->_price[cursor] *= 100;
}
void Cotas::set_date(const string data, int cursor){//setando data da ação
    this->_data[cursor] = data;
}
void Cotas::set_ticker(const string ticker, int cursor){//setando ticker da ação
    this->_ticker[cursor] = ticker;
}
/***********************************************************************************/
/*********************************BUSCA BINÁRIA***********************************/
//Realiza-se a busca binária em relaçao á data e ticker, retornando a posição em que ambas se encontram.
//Pensei primordialmente em tentar com a busca binaria recursiva, porém não obtive sucesso ao trabalhar nela com duas chaves ao mesmo tempo.
//Pensei na busca binaria de forma interativa, que mantem a complexidade e eficiencia em n log n.
//Com a posição retornada, podemos usá-la na função get price, a fim de saber o preço em tal posição (data e dia) do vetor - método usado na entrada Q.
int Cotas::buscaBinInterativa(int begin, int end, string chavedata, string chaveticker) const{
      while(begin <= end){
		
        int meio = (end-begin)/2 + begin;

		if (this->_ticker[meio] == chaveticker && this->_data[meio] == chavedata) //encontrou o elemento com a mesma Data e Ticker
			return meio;
		if ((this->_ticker[meio] > chaveticker) || (this->_data[meio] > chavedata) && (this->_ticker[meio] == chaveticker)) 
			end =  meio-1; 
        else
            begin = meio + 1;   
    }   
	return -1;	 	
}

/**********************************MÉTODOS GET****************************************/

//Nesse método, a função chama uma busca binária que procura em qual posição do array a data da ação e o ticker dessa ação se encontram
//retornando o inteiro = posição. A partir dai, fica fácil achar informações uteis, tais como o preço.
//A função get_price recebe esse inteiro i, que é armazenado na execução da main, e recebe como parametro, retornando o preço em tal posição.
int Cotas::get_posicao(int begin, int end, string chavedata, string chaveticker) const{
    int resultado = buscaBinInterativa(0,end,chavedata,chaveticker);
    return resultado;
}
string Cotas::get_ticker(int n) const{ 
    return this->_ticker[n];
}
double Cotas::get_price(int n) const{
    return this->_price[n];
}
string Cotas::get_date(int n) const{
    return this->_data[n];
} 

//Função debugger.
void Cotas::displayinfo(int n) const{
    for(int i = 0; i < n; i++){
        cout << this->_ticker[i] << " " << this->_data[i] << "  " << int(this->_price[i]);
        cout << "\n";
    }
}

/****************************************Funções de Ordenação **********************************************************/
//Utilizando da noção da práticas de ordenação, optei pelo método quicksort afim de obter um algoritmo nlog n com uma eficiência considerável.
//Como nesta etapa do trabalho ordenamos por Ticker da ação e data da mesma, tomemos esses dois casos dentro das funções de ordenação,
//recebendo os atributos dos vetores alocados pelo método this->;
int Cotas::particiona(int beg, int end, int pivo){
//O caso de ordenação consiste em ordenar primeiro pelo Ticker, e se o ticker for igual, ordena-se pela data. Por conseguinte.
//recebemos como pivôs os 2 vetores.
    string pivot1 = this->_ticker[pivo]; //recebemos como primeiro caso de ordenação o ticker
    string pivot2 = this->_data[pivo]; //caso de desempate - a menor data
    
    swap(this->_ticker[pivo], this->_ticker[end-1]); //troca-se o pivo de todos os dados da classe, a fim
    swap(this->_data[pivo], this->_data[end-1]);     //de que nenhuma ação se embaralhe.
    swap(this->_price[pivo], this->_price[end-1]);
    
    int pos = beg;
    
    for(int i = beg; i < end-1; i++){
        if (this->_ticker[i] < pivot1 ){ //caso o ticker seja menor, lexicograficamente, colocamos na posição pos
            swap(this->_ticker[pos], this->_ticker[i]);     //Passa-se todas as informaçoes referentes á ação,
            swap(this->_data[pos], this->_data[i]);         //a fim de não ser perder nenhum dado.
            swap(this->_price[pos], this->_price[i]);
            pos++;       
        } 
        //caso o ticker for igual, ordenamos pela menor data
        if((this->_ticker[i] == pivot1) &&  (this->_data[i] < pivot2)){
            swap(this->_ticker[pos], this->_ticker[i]);
            swap(this->_data[pos], this->_data[i]);
            swap(this->_price[pos], this->_price[i]);
            pos++;
        }
    }
    
    swap(this->_ticker[pos],this->_ticker[end-1]); //coloque oS pivoS depois do ultimo elemento menor que ele
    swap(this->_data[pos],this->_data[end-1]);
    swap(this->_price[pos], this->_price[end-1]);
    return pos;
}
void Cotas:: quickSort2(int beg, int end){
    if(beg == end){
        return;
    }
    int pos = particiona(beg, end, beg); 
    quickSort2(beg, pos);
    quickSort2(pos + 1, end);
}

void Cotas::quickSort(int n){
    quickSort2(0, n);
}

/******************************************************************************************************************/
Cotas::~Cotas(){
   //cout << "Desalocando..............." << endl;
   delete []_ticker;
   delete []_data;
   delete []_price;
} 

