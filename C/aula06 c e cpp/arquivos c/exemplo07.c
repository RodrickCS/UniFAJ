#include <stdio.h>
int main()
{
    FILE *f;
    f = fopen("arquivo3.txt", "a");
    if (f == NULL)
    {
        printf("Erro");
        return -1;
    }
    char nome[30] = {"Carlos"};
    int idade = 52;
    float altura = 1.83;
    fprintf(f, "Nome: %-30s\nIdade: %d\nAltura: %.2f\n",
            nome, idade, altura);
    fclose(f);
}