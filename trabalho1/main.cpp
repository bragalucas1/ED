#include <iostream>
#include "cotas.h"
#include "operations.h"

using namespace std;

int main(int argc, char **argv){    

    Cotas carteira; //abertura da carteira
    Operations *operacao = new Operations[100]; //abertura da classe operacao
    
    //Declaração de variáveis e inicialização de variáveis
    string nome = " ", data = " ", line1 = " ", line2 = " ", line3 = " ", line4 = " ", tickersplit = " ", datasplit = " ", valorsplit = " ", datadividendos = " ", tickerdividendos = " ", operation = " ";
    string line5 = " ", useless = " ", compraouvenda = " ",  pass6 = " ",  line6 = " ", dataopf = " ", stringopf = " ";
    double valor = 0, n = 0, cursor = 0, junk = 0, denom = 0, num = 0, truesplit = 0, valordividendos = 0.0;
    int cursor2 = 0, cursor3 = 0, qtd = 0, cursor4 = 0;

        //* LEITURA DO PRIMEIRO ARQUIVO REFERENTE AOS PREÇOS, DATAS E COTAÇÕES DAS AÇÕES* //
        ifstream entradacotacoes(argv[1]);
        while(getline(entradacotacoes,line1)){
        stringstream pass;  //criamos um stringstream a fim de ''quebrar'' as palavras em blocos, tornando mais facil o parsing
        for(int i = 0; i < line1.size();i++){
            if(line1[i] == ','){  //verifica se há uma virgula entre as palavras, se houver
                line1[i] = ' ';   // troca por um espaço
            }
        }
        pass << line1;
        pass >> nome >> data >> junk >> junk >> junk >> valor >> junk >> junk;
        carteira.set_ticker(nome,cursor); //seta os dados em um vetor alocado na classe;
        carteira.set_date(data,cursor);
        carteira.set_price(valor,cursor);
        cursor++;//parsing dos dados, incrementa-se o cursor a cada passada de linha a fim de salvar os dados que nos interessa(ticker,data e sexta coluna)
        }
        carteira.quickSort(cursor); //ordena os dados pelo método quicksort - busca binária funciona apenas em array ordenado.
       
       
        // * LEITURA DO ARQUIVO REFERENTE Á DATAS QUE SOFRERAM SPLITS*          //
        ifstream entradasplits(argv[2]);
        while(getline(entradasplits,line2)){
        stringstream pass2;
        for(int i = 0; i < line2.size(); i++){
            if(line2[i] == ','){
                line2[i] = ' ';
            }
            else if(line2[i] == ':'){
                line2[i] = ' ';
            }
        }
        
        pass2 << line2;
        pass2 >> tickersplit >> datasplit >> num >> denom;
        truesplit = num/denom;
        operacao[cursor2].set_tickersplit(tickersplit);
        operacao[cursor2].set_datasplit(datasplit);
        operacao[cursor2].set_split(truesplit);
        cursor2++;
        }
        //LEITURA DO TERCEIRO AQRUIVO REFERENTE AOS DIVIDENDOS PAGOS PELAS AÇOES EM SEUS RESPECTIVOS DIAS.
        ifstream entradadividendos(argv[3]);
        while(getline(entradadividendos,line3)){
            stringstream pass3;
            for(int i = 0; i < line3.size(); i++){
                if(line3[i] == ','){
                    line3[i] = ' ';
                }
            }
        pass3 << line3;
        pass3 >> tickerdividendos >> datadividendos >> valordividendos;
        operacao[cursor3].set_tickersdividendos(tickerdividendos);
        operacao[cursor3].set_datadividendos(datadividendos);
        operacao[cursor3].set_dividendos(valordividendos);
        cursor3++;
        }
        
        //Leitura dos arquivos contento operações acerca das açoẽs. Tais arquivos são padronizados com a primeira linha contendo o tipo da operação.
        //Mediante isso, fazemos um tratamento acerca da operação.
        ifstream entradaoperacoes(argv[4]);
        getline(entradaoperacoes,line4);
        stringstream passing;
        passing << line4;
        passing >> operation;
        
        if(operation == "Q"){
            int cont = 0;
            while(getline(entradaoperacoes,line5)){
                stringstream pass5;
                for(int i = 0; i < line5.size();i++){
                    if(line5[i] == ','){  //verifica se há uma virgula entre as palavras, se houver
                        line5[i] = ' ';   // troca por um espaço
                }
            }
            pass5 << line5;
            pass5 >> data >> useless >> nome; 
            int pos = carteira.get_posicao(0,cursor,data,nome);  
            cout << int(carteira.get_price(pos)) << endl;
            cont++;
            }   
        }   

    
        if(operation =="D"){
            cout << "Não consegui implementar." << endl;
        }
        if(operation == "F"){
            cout << "Não consegui implementar." << endl;
        }
        if(operation == "M"){
            cout << "Não consegui implementar." << endl;
        }
        if(operation == "DR"){
            cout << "Não consegui implementar." << endl;
        }
        

        delete[] operacao; //desalocamos a fim de evitar vazamentos de memória
    
    
        
    return 0;
    
    
}