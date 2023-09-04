#include <iostream>
#include <string>
#include "myLib.cpp"
using namespace std;

typedef struct
{
    int ra;
    float n1, n2, media;
    string nome;
} ficha;

int main()
{
    ficha f;
    cout << "Digite o RA: ";
    cin >> f.ra;
    cout << "Nome do Aluno: ";
    f.nome = leStr();
    cout << "Nota da primeira prova: " << endl;
    cin >> f.n1;
    cout << "Nota da segunda prova: " << endl;
    cin >> f.n2;

    f.media = (f.n1 + f.n2) / 2;

    cout << "Nome: " << f.nome << " RA: " << f.ra << " Media: " << f.media << endl;

    return 0;
}