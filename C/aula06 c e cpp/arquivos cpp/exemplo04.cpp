#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string texto;
    ifstream arqEntrada;
    arqEntrada.open("saida.txt", ios::in);
    while (arqEntrada >> texto)
    {
        cout << texto << endl;
    }
}