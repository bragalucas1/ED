#ifndef SPLITS_H
#define SPLITS_H
using namespace std;
#include <string>

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

class Operations{

    private:
   
    
    double _split;
    double _dividendos;
    string _tickersplit;
    string _tickersdividendos;
    string _datadividendos;
    string _datasplit;
    int     _buycost;
    int _valorizacao;
    int _numberofop;
    int _tamanho;
    bool operator< (const Operations &other)const;
  

    public:
    /*****************CONSTRUTOR E DISTRUTOR************/
    Operations();
    ~Operations();
    /***************************************************/
    /******************ḾÉTODOS SET'S********************/
    void set_split(const double split);
    void set_size(const int size);
    void set_dividendos(const double dividendos);
    void set_datasplit(const string datasplit);
    void set_tickersplit(const string tickersplit);
    void set_tickersdividendos(const string tickersdividendos);
    void set_datadividendos(const string datadividendos);
    void set_buycost(const int buycost);
    void set_valorizacao(const int valorizacao);
    void set_numberofop(const int numberofop);
    void displayinfo(int n);
    /****************MÉTODOS GET***************************/
    string get_datasplit() const;
    string get_tickersdividendos()const;
    string get_datadividendos()const;
    string get_tickersplit() const;
    double get_split() const;
    double get_dividendos()const;
    int get_buycost() const;
    int get_valorizacao() const;
    int get_numberofop() const;
    /*******************************************************/
   
};

#endif