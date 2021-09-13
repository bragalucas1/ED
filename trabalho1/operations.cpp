#include <iostream>
#include <fstream>
#include <sstream>
#include "operations.h"
using namespace std;

Operations::Operations(){ //construtor inicilializando as variaveis
    _split = 0;
    _dividendos = 0;
    _tickersplit = " ";
    _datasplit =  " ";
    _buycost = 0;
    _valorizacao = 0;
    _numberofop = 0;
} 

bool Operations::operator<(const Operations &other)const{ //opeerador <
    if(*this < other){
        return true;
    }
    else{
        return false;
    }
}

//Os métodos SET abaixo recebem o parametro da main(), e colocam no vetor com a respectiva posição.
//Todos os dados abaixo são referentes aos splits, dividendos, custo de compra, operaçoes e entre outras coisas realizadas com as açoes.
void Operations::set_size(const int size){
    _tamanho = size;
}
void Operations::set_tickersdividendos(const string tickerdividendos){
    _tickersdividendos = tickerdividendos;
}
void Operations::set_datadividendos(const string datadividendos){
    _datadividendos = datadividendos;
}
void Operations::set_dividendos(const double dividendos){
    _dividendos = dividendos;
}
void Operations::set_buycost(const int buycost){
    _buycost = buycost;
}
void Operations::set_split(const double split){
    _split = split;
}
void Operations::set_datasplit(const string datasplit){
    _datasplit = datasplit;
}
void Operations::set_tickersplit(const string tickersplit){
    _tickersplit = tickersplit;
}
void Operations::set_valorizacao(const int valorizacao){
    _valorizacao = valorizacao;
}
void Operations::set_numberofop(const int numberofop){
    _numberofop += numberofop;
}

//Os métodos GET abaixo, retornam o usuario os dados necessários armazenados pelos métodos SET acima
string Operations::get_datasplit() const{
    return _datasplit;
}
string Operations::get_datadividendos()const{
    return _datadividendos;
}
string Operations::get_tickersdividendos()const{
    return _tickersdividendos;
}
string Operations:: get_tickersplit() const{
    return _tickersplit;
}

double Operations::get_split() const{
    return _split;
}
double Operations::get_dividendos() const{
    return _dividendos;

}
int Operations::get_buycost() const{
    return _buycost;
}
int Operations::get_valorizacao() const{
    return _valorizacao;
}
int Operations::get_numberofop() const{
    return _numberofop;
}
//Função debugger.
void Operations::displayinfo(int n){
    for(int i = 0; i < n; i++) {
        cout << _datasplit << " " << _tickersplit << " " << _split << endl;
    }
}
Operations::~Operations(){

}