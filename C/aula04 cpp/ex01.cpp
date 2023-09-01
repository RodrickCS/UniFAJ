#include <iostream>
#include <string>
#include "myLib.cpp"

int main()
{
    int x;
    string nome;
    cout << "Digite um inteiro ";
    cin >> x;
    cout << "Digite nome e sobrenome: ";
    nome = leStr();
    cout << "Seu nome eh " << nome << " Digito numero " << x << endl;
    return 0;
}