#include <iostream>
#include <cassert>
#include <fstream>
#include "Huffman.h"

using namespace std;

int main(int argc, char **argv){

    if(argc == 'c'){
        ifstream compressfile(argv[1]);
    }


    if(argc == 'd'){
        ifstream descompressfile(argv[1]);
    }
    return 0;

}