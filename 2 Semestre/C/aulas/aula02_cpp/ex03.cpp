#include <iostream>
using namespace std;

float calcMedia (float n1 , float n2) {
    float med = (n1 + n2) / 2;
    return med;
}

int main () {
    float nota1,nota2,med;

    cout << "Nota prova 1: ";
    cin >> nota1;
    cout << "Nota prova 2: ";
    cin >> nota2;

   med = calcMedia(nota1,nota2);
   cout << "Sua media eh " << med;
}