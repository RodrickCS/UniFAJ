#ifndef _MYLIB_C_
#define _MYLIB_C_

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#define acento setlocale(LC_ALL, "")
#define sacento setlocale(LC_ALL, "C")

#if defined(__WIN32__) || defined(__NT__)
#include <conio.h>
#endif

#if defined(__linux__) || defined(__linux)
#include <termios.h>
#endif

// #if defined(__APPLE__)
// #  defined MEU_API_OSX
// #endif

#define false 0
#define true 1
typedef int bool;

int i;

void clearscr()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#endif
}

void pausa()
{
    printf("\nTecle enter para continuar ");
    getchar();
    getchar();
}

int num(char c)
{
    return c - '0';
}

bool cpfTest(char c[15])
{
    int tam = strlen(c);
    if (tam != 14)
        return false;
    int t;
    int resto1, resto2, soma = 0, i, j = -1;
    char p1[10];
    int r1, r2;
    for (i = 0; i < 10; i++)
    {
        if (i == 3)
            j++;
        if (i == 6)
            j++;
        if (i == 9)
            j++;
        j++;
        p1[i] = c[j];
    }
    r1 = num(c[12]) * 10;
    r1 = r1 + num(c[13]);
    soma = 0;
    for (i = 0; i < 9; i++)
    {
        t = num(p1[i]); // subtrair o valor asc de '0' para retornar o numero
        j = i + 1;
        soma = soma + (t * j);
    }
    resto1 = soma % 11;
    if (resto1 == 10)
        resto1 = 0;
    soma = 0;
    for (i = 1; i < 10; i++)
    {
        t = num(p1[i]);
        soma = soma + (t * i);
    }
    resto2 = soma % 11;
    if (resto2 == 10)
        resto2 = 0;
    r2 = resto1 * 10 + resto2;
    if (r1 == r2)
        return true;
    else
        return false;
}

bool validaRg(char r[13])
{
    int tam = strlen(r);
    if (tam != 12)
        return false;
    int soma, resto, digitoVerificador, i, j = -1;
    char aux[10];
    for (i = 0; i < 10; i++)
    {
        if (i == 2)
            j++;
        if (i == 5)
            j++;
        if (i == 8)
            j++;
        j++;
        aux[i] = r[j];
    }
    resto = num(r[11]);
    soma = 0;
    for (i = 0; i < 8; i++)
        soma = soma + (num(aux[i]) * (9 - i));
    resto = soma % 11;
    if (resto == 10)
        resto = 0;
    digitoVerificador = num(r[11]);
    if (resto == digitoVerificador)
        return true;
    else
        return false;
}

void delay(int t)
{
    int ms = 100 * t;
    clock_t ini = clock();
    while (clock() < ini + ms)
        ;
}

void leSenha(char *senha, int max)
{

#ifdef __unix__
    struct termios new, old;
    tcgetattr(fileno(stdin), &old);
    new = old;
    new.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), TCSAFLUSH, &new);
    fgets(senha, max, stdin);
    if (senha[0] == '\n')
        fgets(senha, max, stdin);
    int tam = strlen(senha) - 1;
    if (senha[tam] == '\n')
        senha[tam] = '\0';
    (void)tcsetattr(fileno(stdin), TCSAFLUSH, &old);
#elif defined(_WIN32) || defined(WIN32)
    int tam = 0;
    do
    {
        senha[tam] = getch();
        if (senha[tam] == 0x08 && tam > 0) // Backspace
        {
            printf("\b \b");
            senha[tam] = 0x00;
            tam--;
        }
        else if (senha[tam] == 13) // Enter
        {
            senha[tam] = 0x00;
            break;
        }
        else if (senha[tam] != 0x08)
        {
            putchar('*');
            tam++;
        }
    } while (tam < max);
#endif
    putchar('\n');
}

void leStr(char *tmp, int max)
{
    fgets(tmp, max, stdin);
    if (tmp[0] == '\n')
        fgets(tmp, max, stdin);
    int tam = strlen(tmp) - 1;
    if (tmp[tam] == '\n')
        tmp[tam] = '\0';
}

// funcoes para data
#define SED 86400
// SED Segundos em Dias 24 x 60 x 60 86400

int verificarNumero(char *entrada)
{
    int i;

    for (i = 0; entrada[i] != '\0'; i++)
    {
        if (entrada[i] != '/' && !isdigit(entrada[i]))
        {
            return 0;
        }
    }

    return 1;
}

int verificarData(char *entrada)
{
    const char substring[3] = "//";

    if (strstr(entrada, substring) != NULL)
    {
        return 0;
    }

    if (!verificarNumero(entrada))
    {
        printf("Não são numéricos.\n");
        return 0;
    }

    int i = 0;
    long data[3];
    const char delimitador[2] = "/";
    char *token = strtok(entrada, delimitador);

    // Alimenta o vetor de inteiros
    while (token != NULL)
    {
        data[i++] = strtol(token, NULL, 10);
        token = strtok(NULL, delimitador);
    }

    // Realize suas validações. Se alguma não for atingida, retorne '0'
    // Caso contrário, retorne '1'

    return 1;
}

int mesDia(int dia, int mes)
{
    return mes * 100 + dia;
}

int bissexto(int ano)
{
    if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0))
        return 1;
    else
        return 0;
}

int maxDiasMes(int mes, int ano)
{
    int dias = 31;
    if (mes < 1 || mes > 12)
        return -1;
    switch (mes)
    {
    case 2:
        if (bissexto(ano))
            dias = dias - 2;
        else
            dias = dias - 3;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dias--;
    }
    return dias;
}

int ano(const char data[11])
{
    struct tm tm = {0}; /* zera a struct toda */
    int tam = strlen(data);
    if (sscanf(data, "%d/%d/%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year) < 3 || tam != 10)
    {
        fprintf(stderr, "Erro de formatacao ao ler data %s\n", data);
        exit(1);
    }
    return (tm.tm_year);
}

int mes(const char data[11])
{
    struct tm tm = {0}; /* zera a struct toda */
    int tam = strlen(data);
    if (sscanf(data, "%d/%d/%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year) < 3 || tam != 10)
    {
        fprintf(stderr, "Erro de formatacao ao ler data %s\n", data);
        exit(1);
    }
    tm.tm_mon--;
    return (tm.tm_mon);
}

int dia(const char data[11])
{
    struct tm tm = {0}; /* zera a struct toda */
    int tam = strlen(data);
    if (sscanf(data, "%d/%d/%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year) < 3 || tam != 10)
    {
        fprintf(stderr, "Erro de formatacao ao ler data %s\n", data);
        exit(1);
    }
    tm.tm_mday;
    return (tm.tm_mday);
}

time_t data2int(const char data[11])
{
    struct tm tm = {0}; /* zera a struct toda */
    int tam = strlen(data);
    if (sscanf(data, "%d/%d/%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year) < 3 || tam != 10)
    {
        fprintf(stderr, "Erro de formatacao ao ler data %s\n", data);
        exit(1);
    }
    tm.tm_mon--;        /* tm.mon espera o número de meses desde janeiro (0–11) */
    tm.tm_year -= 1900; /* tm.year espera o número de anos desde 1900 */
    if (tm.tm_mday > maxDiasMes(tm.tm_mon, tm.tm_year))
    {
        fprintf(stderr, "Data invalido %s\n", data);
        exit(1);
    }
    return mktime(&tm);
}

void int2data(char *buf, size_t len, time_t data)
{
    struct tm *tm = localtime(&data);
    buf[0] = '\0';
    if (snprintf(buf, len, "%02d/%02d/%04d",
                 tm->tm_mday,
                 tm->tm_mon + 1,
                 tm->tm_year + 1900) < 10)
    {
        fprintf(stderr, "Erro de formatação ao escrever data %ld \n", data);
        exit(1);
    }
}

int idade(const char dtAnt[11], const char dtHoje[11])
{
    int anoHoje = ano(dtHoje);
    int anoAnt = ano(dtAnt);
    int idade = anoHoje - anoAnt;
    int mesHoje = mes(dtHoje);
    int mesAnt = mes(dtAnt);
    int diaHoje = dia(dtHoje);
    int diaAnt = dia(dtAnt);
    int jaFezNiver = mesDia(diaHoje, mesHoje) - mesDia(diaAnt, mesAnt);
    if (jaFezNiver < 0)
        idade--;
    return idade;
}

// fim funcoes para data

/*
Apenas para exemplo
*/
void leInt(int *i)
{
    scanf("%d", i);
}

int leInt2()
{
    int tmp;
    scanf("%d", &tmp);
    return tmp;
}

void leFloat(float *tmp)
{
    scanf("%f", tmp);
}

float leFloat2()
{
    float tmp;
    scanf("%f", &tmp);
    return tmp;
}

void leChar(char *tmp)
{
    scanf(" %c", tmp);
}

char leChar2()
{
    char tmp;
    scanf(" %c", &tmp);
    return tmp;
}

#endif