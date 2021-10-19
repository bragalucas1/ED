
#include "MyMap.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    MyMap<string, int> map;
    string s;
    int cont = 0;
    while (cin >> s) {
        if (map.find(s) == NULL){
            map.insert(make_pair(s, cont));
            cout << s << " " << cont << endl;
            cont++;
        } else{
            cout << s << " " << map[s] << endl;
        }
    }

    return 0;
}