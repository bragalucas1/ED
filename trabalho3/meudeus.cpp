#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char **argv){

    int freqs[256] = {0};
    string line1 = "";    //calculamos a frequencia aquu, e passamos para o construtor da arvore
    ifstream compressfile(argv[1]);
    cout << "aqui" << endl;
    while(getline(compressfile,line1)){
        for(int i = 0; i < line1.size(); i++){
            unsigned char ch = line1[i];
                if(line1[i] == ch){
                    freqs[ch]++;
                }
        }
    }
    
    
    for(int i = 0; i < 256; i++){
        unsigned char ch = i;
        cout << i <<  ": " << ch << " " << freqs[ch] << endl;

    }
       
    

return 0;
}