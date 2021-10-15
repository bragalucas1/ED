#include <fstream>
#include <iostream>
using namespace std;


int main(int argc, char**argv){
    int vetor[5] = {0,0,0,0,0};

    ifstream openfile(argv[1]);
    cout.write(reinterpret_cast<vetor>,5*sizeof(int));
    openfile.close();
    return 0;
}