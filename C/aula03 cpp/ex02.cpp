#include <iostream>
#include <iomanip>
using namespace std;
#define L 3
#define C 4

int main()
{
    int matriz[L][C];
    int l, c;
    for (l = 0; l < L; l++)
    {
        for (c = 0; c < C; c++)
        {
            cout << "Elemento [" << l << "][" << c << "] ";
            cin >> matriz[l][c];
        }
    }

    for (l = 0; l < L; l++)
    {
        for (c = 0; c < C; c++)
        {
            cout << setw(4) << matriz[l][c] << " ";
        }
        cout << endl;
    }

    int soma = 0;
    for (l = 0; l < L; l++)
    {
        for (c = 0; c < C; c++)
        {
            soma += matriz[l][c];
        }
    }

    int menor = matriz[0][0];
    int maior = matriz[0][0];

    for (l = 0; l < L; l++)
    {
        for (c = 0; c < C; c++)
        {
            if (matriz[l][c] < menor)
            {
                menor = matriz[l][c];
            }
            if (matriz[l][c] > maior)
            {
                maior = matriz[l][c];

            }
        }
    }

    int contador = 0;
    for (l = 0; l < L; l++)
    {
        for (c = 0; c < C; c++)
        {
            contador++;
        }
    }

    cout << "Somatoria: " << soma << endl;
    cout << "Menor: " << menor << endl;
    cout << "Maior: " << maior << endl;
    cout << "Media: " << soma / contador << endl;
    cout << "Media real: " << (float)soma / contador << endl;
}