#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    f = fopen("arquivo4.txt", "w");
    char nome[30] = "Carlos Miglinski";
    int idade = 52;
    float altura = 1.83;
    fprintf(f, "%-30s\n%d\n%f", nome, idade, altura);
}