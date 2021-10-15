#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char **argv){

    int freqs[256] = {0};
    string line1 = "";    //calculamos a frequencia aquu, e passamos para o construtor da arvore
    ifstream compressfile(argv[1]);
    cout << "aqui" << endl;
    compressfile.read()
    
    
    for(int i = 0; i < 256; i++){
        unsigned char ch = i;
        cout << i <<  ": " << ch << " " << freqs[ch] << endl;

    }
       
    

return 0;
}