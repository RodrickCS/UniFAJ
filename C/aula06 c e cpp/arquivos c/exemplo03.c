#include <stdio.h>
int main()
{
    FILE *f = fopen("arquivo3.txt", "r");
    if (f == NULL)
    {
        printf("Erro");
        return -1;
    }
    char nome[30], txt[30];
    int idade;
    float altura;
    fscanf(f, "%s %s", txt, nome);
    printf("%s %s\n", txt, nome);

    fscanf(f, "%s %d", txt, &idade);
    printf("%s %s\n", txt, idade);

    fscanf(f, "%s %f", txt, &altura);
    printf("%s %s\n", txt, altura);
    fclose(f);
}