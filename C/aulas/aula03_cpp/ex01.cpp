#include <iostream>
using namespace std;
#define MAX 4

int main()
{
    int vetor[MAX];
    int i;

    for (i = 0; i < MAX; i++)
    {
        cout << "Digite um valor para a posicao " << i << endl;
        cin >> vetor[i];
    }

    for (i = 0; i < MAX; i++)
    {
        cout << "Elementos do vetor na posicao " << i << " = " << vetor[i] << endl;
    }
    int soma = 0;
    for (i = 0; i < MAX; i++)
    {
        soma += vetor[i];
    }
    cout << "Somatoria: " << soma << endl;
    cout << "Media: " << soma / MAX << endl;
    cout << "Media real: " << (float)soma / MAX << endl;

    int menor = vetor[0];
    int maior = vetor[0];
    for (i = 0; i < MAX; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    cout << "O menor elemento " << menor << endl;
    cout << "O maior elemento " << maior << endl;

    return 0;
}