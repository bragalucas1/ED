#ifndef COTAS_h
#define COTAS_H

#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

class Cotas{

    private: //garantir o acesso da classe Operações
    Cotas& operator=(const Cotas &other)  const; //operador de atribuição
    bool operator<(const Cotas &other) const;//operador de comparação
    string *_ticker;  //ticker referente à empresa
    double *_price;   //preço referente ao dia da ação - coluna 6 é o preço que salvaremos
    string *_data; //data referente à cotação
    
    

    public:
    /************** CONSTRUTOR E DESTRUTOR***************/
    Cotas(); 
    ~Cotas();
    /*------------ MÉTODOS GET's e SET'S************/
    string get_ticker(int n) const;  //função responsável por receber o ticker da empresa
    void set_ticker(const string ticker, int cursor); //função responsável por setar o ticker
    string get_date(int n) const; //função responsável por receber a data referente á cotação
    void set_date(const string data, int cursor);
    double get_price(int n) const; //função responsável por reveber o preço referente ao ticker da empresa
    void set_price(const double price, int cursor); //função responsável por setar o preço
    int get_posicao(int begin, int end, string chavedata, string chaveticker) const;
    /************************************************/
    
    /***************** MÉTODOS DE ORDENAÇÃO***********/
    void quickSort(int n); //método de ordenação responsável pela ordenação de todas as entradas.
    int particiona(int beg, int end, int pivo);
    void quickSort2(int beg, int end);
    void displayinfo(int n) const ; //mostra os dados correntes
    /*************************************************/
    
    
    /*******************BUSCA BINÁRIA*****************/
    int buscaBinInterativa(int begin, int end, string chavedata, string chaveticker) const;

    
    
    
   

};  

#endif
