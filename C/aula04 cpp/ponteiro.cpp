#include <iostream>
#include <string>
using namespace std;

void proxant(int i, int *prox, int *ant)
{
    *prox = i + 1;
    *ant = i - 1;
}

void proxantC(char c, char *prox, char *ant)
{
    *prox = c + 1;
    *ant = c - 1;
}

int main()
{
    int valor = 2;
    int next;
    int ant;
    proxant(valor, &next, &ant);
    cout << "Valor inicial " << valor << " seu antessor -> " << next << " anterior -> " << ant << endl;

    char letra, p, a;
    cout << "Digite um caractere: ";
    cin >> letra;
    proxantC(letra, &p, &a);
    cout << "Anterior -> " << a << " proximo -> " << p;
}