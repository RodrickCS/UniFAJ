#include <iostream>
#include <string>
using namespace std;

int main() {
    float n1[3], n2[3];
    string nome[3], ra[3];
    int i;

    for(i = 0; i < 3; i++){
        cout << "Insira o ra: ";
        cin >> ra;
        cout << "Insira o nome: ";
        cin >> nome;
        cout << "nota da p1: ";
        cin >> n1[i];
        cout << "nota da p2: ";
        cin >> n2[i];
    }

    for ( i = 0; i < 3; i++) {
        cout << " RA " << ra[1] << " Nome " << nome[i] << " Media " << (n1[i] + n2[i] / 4)
    }

    return 0;
}