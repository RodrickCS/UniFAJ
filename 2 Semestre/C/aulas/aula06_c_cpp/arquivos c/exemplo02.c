#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    f = fopen("arquivo.txt", "r");
    if (f == NULL)
    {
        printf("Erro de abertura de arquivo.");
        return -1;
    }
    int i;
    char c;
    for (i = 0; i < 38; i++)
    {
        c = fgetc(f);
        printf("%c", c);
    }
    printf("\n");
    return 0;
}