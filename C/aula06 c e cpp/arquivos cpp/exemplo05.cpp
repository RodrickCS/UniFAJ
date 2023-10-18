#include <iostream>
#include <fstream>
#include "../../bibliotecas/myLib.cpp"
using namespace std;

int main()
{
    string texto;
    ifstream arqEntrada;
    while (getline(arqEntrada, texto))
    {
        cout << texto << endl;
    }
    return 0;
}