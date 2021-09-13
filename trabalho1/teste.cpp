#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>

using namespace std;


int main(/*int argc, char **argv*/){
   string *teste = new string[600];
    int *valor = new int [500000];
   string *data = new string [500000];
   int *valor2 = new int[500000];
   double *wtf = new double[500000];
   //Caso o programa não seja chamado corretamente, exibe a mensagem de erro:
   /*if(argc != 5){
       cerr << "Erro ao inserir os dados corretos." << "\n";
       return 0;
   }*/

   ifstream xd;
   string useless;
   string line;
   float soma = 0.000001;
   int contador = 0;
   xd.open("splits.csv");
   
   if(!xd.is_open()){
       throw "Arquivo inexistente."; //Tratamento de exceção"
    }

    while(getline(xd, line)){
        stringstream passing;
        for(int i = 0; i < line.size();i++){
            if(line[i] == ','){
                line[i] = ' ';
            }
            if(line[i] == ':'){
                line[i] = ' ';
            }
        }
    passing << line;
    passing >> teste[contador] >>  data[contador] >> valor[contador] >> valor2[contador];
    cout << valor[contador] << " " << data[contador] << valor[contador] << valor2[contador] << endl;
    //wtf[contador] = valor[contador]/valor2[contador];
    contador++;
    }

    /*for(int i = 0; i < contador ; i ++){ 
         cout << teste[i] << " " << data[i] << " " << valor[i] << " " << valor2[i] << "\n";
         cout << endl;
        //cout << valor[i]/valor2[i];
        //cout << valor[i] << "/" << valor2[i];
        cout << wtf[i] << endl;
     }*q
     /*for(int i = 0; i < contador; i++){
         cout << valor2[i];
     }*/
    //cout << contador << endl;
    xd.close();

    /*for(int i = 0; i < contador ; i ++){ 
        //valor[i] = int(valor[i] + 0.000001);
        //int(valor[i]);
        cout <<  fixed << setprecision(6) << valor[i] << " ";
        //cout << "\n";
    }*/
    //cout << teste[i] << " " << data[i] << " " << valor[i] << " ";
    //cout << "\n";


delete []teste;
delete []valor;
delete []data;
delete []valor2;
return 0;
}