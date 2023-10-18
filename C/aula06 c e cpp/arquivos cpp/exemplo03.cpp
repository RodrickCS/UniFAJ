#include <iostream>
#include <fstream>
#include "../../bibliotecas/myLib.cpp"
using namespace std;

int main()
{
    string texto;
    ofstream arqSaida;
    arqSaida.open("saida.txt", ios::out);
    cout << "CTRL + C para finalizar" << endl;
    while (true)
    {
        texto = leStr();
        arqSaida << texto << endl;
    }
    return 0;
}