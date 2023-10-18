#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    f = fopen("arquivo.txt", "w");
    if (f == NULL)
    {
        printf("Erro de abertura de arquivo.");
    }
    char texto[50] = {"Meu primeiro programa com arquivo em C"};
    int i;
    printf("Tamanho do texto %d\n", strlen(texto));
    for (i = 0; i < strlen(texto); i++)
    {
        fputc(texto[i], f);
    }
    fclose(f);
    return 0;
}