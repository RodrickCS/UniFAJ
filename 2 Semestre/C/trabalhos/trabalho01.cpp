#include <iostream>
#include <string>
#include "../bibliotecas/myLib.cpp"
using namespace std;

// Desenvolva uma aplicação em C++ que leia e imprima os seguintes campos:
// código, nome, rua, bairro, cidade, estado, cep, celular, e-mail, CPF e RG

typedef struct
{
    int codigo;
    string nome;
    string rua;
    string bairro;
    string cidade;
    string estado;
    string cep;
    string celular;
    string email;
    string cpf;
    string rg;
} ficha;

void Imprimir(ficha *f)
{

    cout << "Codigo: " << f->codigo << endl
         << "Nome: " << f->nome << endl
         << "rua: " << f->rua << endl
         << "bairro: " << f->bairro << endl
         << "cidade: " << f->cidade << endl
         << "estado: " << f->estado << endl
         << "cep: " << f->cep << endl
         << "celular: " << f->celular << endl
         << "email: " << f->email << endl
         << "cpf: " << f->cpf << endl
         << "rg: " << f->rg << endl;
}

void ler(ficha *f)
{

    cout << "Digite o seu nome: ";
    f->nome = leStr();

    cout << "Digite a sua rua: ";
    f->rua = leStr();

    cout << "Digite o seu bairro: ";
    f->bairro = leStr();

    cout << "Digite a sua cidade: ";
    f->cidade = leStr();

    cout << "Digite o seu estado: ";
    f->estado = leStr();

    cout << "Digite o seu cep: ";
    f->cep = leStr();

    cout << "Digite o seu celular: ";
    f->celular = leStr();

    cout << "Digite o seu email: ";
    f->email = leStr();

    cout << "Digite o seu cpf: ";
    f->cpf = leStr();

    cout << "Digite o seu rg: ";
    f->rg = leStr();
}

int main()
{
    ficha f;
    ler(&f);
    Imprimir(&f);
    return 0;
}