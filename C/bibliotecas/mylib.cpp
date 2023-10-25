#ifndef _MYLIB_CPP_
#define _MYLIB_CPP_
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;
#include <conio.h>

#if defined(__linux__) || defined(__linux)
#include <termios.h>
#endif

// #if defined(__APPLE__)
// #  defined MEU_API_OSX
// #endif

#define acento setlocale(LC_ALL, "")
#define sacento setlocale(LC_ALL, "C")

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

void leStr_c(char *tmp, int max)
{
    fgets(tmp, max, stdin);
    if (tmp[0] == '\n')
        fgets(tmp, max, stdin);
    int tam = strlen(tmp) - 1;
    if (tmp[tam] == '\n')
        tmp[tam] = '\0';
}

string leStr()
{
    string txt;
    getline(cin, txt);
    if (txt[0] == '\0')
        getline(cin, txt);
    return txt;
}

string leSenha()
{
    string senha;
#ifdef __unix__
    struct termios novo, old;
    tcgetattr(fileno(stdin), &old);
    novo = old;
    novo.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), TCSAFLUSH, &novo);
    getline(cin, senha);
    if (senha[0] == '\0')
        getline(cin, senha);
    (void)tcsetattr(fileno(stdin), TCSAFLUSH, &old);
#elif defined(_WIN32) || defined(WIN32)
    int tam = 0;
    char letra;
    bool ok = true;
    do
    {
        letra = getch();
        senha += letra;
        if (letra == '\b' && tam > 0) // Backspace
        {
            printf("\b \b");
            senha[tam] = '\0';
            tam--;
        }
        else if (letra == 13) // Enter
        {
            senha[tam] = '\0';
            ok = false;
            break;
        }
        else if (letra != '\b')
        {
            putchar('*');
            tam++;
        }
    } while (ok);
#endif
    cout << endl;
    return senha;
}

int char2num(char c)
{
    return c - '0';
}

bool cpfTest(string cpf)
{
    if (cpf.size() != 14)
        return false;
    string tmp;
    tmp = cpf.substr(0, 3) +
          cpf.substr(4, 3) +
          cpf.substr(8, 3) +
          cpf.substr(12, 2);
    int i, soma = 0;
    for (i = 0; i < 9; i++)
        soma += (char2num(tmp[i]) * (i + 1));
    int resto1 = soma % 11;
    if (resto1 == 10)
        resto1 = 0;
    soma = 0;
    for (i = 1; i < 10; i++)
        soma += (char2num(tmp[i]) * i);
    int resto2 = soma % 11;
    if (resto2 == 10)
        resto2 = 0;
    resto1 = (resto1 * 10) + resto2;
    resto2 = (char2num(tmp[9]) * 10) + char2num(tmp[10]);

    if (resto1 == resto2)
        return true;
    else
        return false;
}

bool rgTest(string rg)
{
    if (rg.size() != 12)
        return false;
    string str;
    str = rg.substr(0, 2);
    str = str + rg.substr(3, 3);
    str = str + rg.substr(7, 3);
    char dig = rg[11];
    int mult = 9, i, soma = 0;
    for (i = 0; i < 8; i++)
    {
        soma += (mult * char2num(str[i]));
        mult--;
    }
    int resto = soma % 11;
    if (resto == char2num(dig))
        return true;
    else
        return false;
}

bool cnpjTest(string cnpj){
    //11.222.333/0001-xx
    //0123456789012345678
    int tam = cnpj.size();
    if (tam != 18)
        return false;
    cnpj = cnpj.substr(0, 2) + cnpj.substr(3, 3) + 
           cnpj.substr(7, 3) + cnpj.substr(11, 4) + 
           cnpj.substr(16, 2);
    int nums1[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int nums2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int soma = 0, i;
    tam = cnpj.size() - 2;
    for (i = 0; i < tam; i++)
        soma += (char2num(cnpj[i]) *nums1[i]);
    int resto1 = soma % 11;
    if (resto1 < 2)
        resto1 = 0;
    else
        resto1 = 11 - resto1;
    resto1 *= 10;
    soma = 0;
    for (i = 0; i < tam + 1; i++)
        soma += (char2num(cnpj[i]) * nums2[i]);
    int resto2 = soma % 11;
     if (resto2 < 2)
        resto2 = 0;
    else
        resto2 = 11 - resto2;
    resto1 = resto1 + resto2;
    resto2 = char2num(cnpj[12]) * 10 + char2num(cnpj[13]);
    if (resto1 == resto2)
        return true;
    else
        return false;
}

// inicio conversao de base

string inverteStr(string str){
    int i, tam;
    tam = str.size()-1;
    string aux = "";
    for (i = tam; i >=0; i--)
        aux += str[i];
    return aux;
}

long int bin2dec(string bin){
    int tam = bin.size();
    int n, i;
    long int dec = 0;
    for (i = 0; i < tam; i++)
    {
        n = bin[i] - '0';
        dec += n * (pow(2.0, tam - 1 - i));
    }
    return dec;
}


string dec2bin(long int dec){
    int resto;
    string bin = "";
    while (dec >= 2)
    {
        resto = dec % 2;
        dec = dec / 2;
        bin += resto + '0';
    }
    bin += dec + '0';
    bin = inverteStr(bin);
    return bin;
}

char calcHex(int pos){
    char v_hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    return v_hex[pos];
}


string dec2hex(long int dec, bool cabecalho = false){
    int resto;
    string hex;
    while (dec > 0)
    {
        resto = dec % 16;
        dec = dec / 16;
        hex += calcHex(resto);
    }
    hex = inverteStr(hex);
    if (cabecalho)
        hex = "0x" + hex;
    return hex;
}

int calcDec(char c){
    string hex = "0123456789ABCDEF";
    c = toupper(c);
    for (int i = 0; i < 17; i++)
        if (hex[i]==c)
            return i;
    return 0;
}

long int hex2dec(string hex){
    if (hex.substr(0,2)=="0x")
        hex = hex.substr(2, hex.size());
    int tam = hex.size();
    int i, dec = 0,pos = tam - 1;
    for (i = 0; i < tam; i++)
    {
        dec += calcDec(hex[i]) * pow(16, pos); 
        pos--;
    }
    return dec;
}

// fim conversao de base
// funcoes para data

int str2int(string txt){
	int num = 0,tam = txt.size()-1;
	for (int i = tam; i >= 0;i--){
		num += (char2num(txt[i])*pow(10,tam-i));
	} 
	return num;
}

bool verificaNumero(string entrada)
{
    int i;
    for (i = 0; entrada[i] != '\0'; i++)
    {
        if (entrada[i] != '/' && !isdigit(entrada[i]))
        {
            return false;
        }
    }
    return true;
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

bool verificaData(string entrada)
{
    if (entrada[2] != '/' || entrada[5] != '/')
    {
        return false;
    }

    if (!verificaNumero(entrada))
    {
        cout << "Não sao numéricos.\n";
        return false;
    }

    int dia, mes, ano;
    dia = str2int(entrada.substr(0, 2));
    mes = str2int(entrada.substr(3, 2));
    ano = str2int(entrada.substr(6, 4));

    int maxDias = maxDiasMes(mes, ano);
    if ((dia > maxDias) || (mes > 12) || (mes < 0))
        return false;
    return true;
}

int ano(string data)
{
    return str2int(data.substr(6, 4));
    
}

int mes(string data)
{
    return str2int(data.substr(3, 2));
}

int dia(string data)
{
    return str2int(data.substr(0, 2));
}

int mesDia(int dia, int mes)
{
    return mes * 100 + dia;
}

int calculaIdade(string dtAnt, string dtHoje)
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
/*
string dataHoje(){
    time_t t = time(0);
    tm *agora = localtime(&t);
    string dia = to_string(agora->tm_mday);
    if (dia.size() == 1)
        dia = '0' + dia;
    string mes = to_string(agora->tm_mon + 1);
    if (mes.size() == 1)
        mes = "0" + mes;
    string ano = to_string(agora->tm_year + 1900);
    return dia + "/" + mes + "/" + ano;
}

*/

string dataHoje(){
    time_t t = time(0);
    //cout << "time(0) "<<t<<endl;
    tm *agora = localtime(&t);
    char tmp[5];
    sprintf(tmp, "%02d", agora->tm_mday);
    string dia = tmp; // to_string(agora->tm_mday);
    sprintf(tmp, "%02d", agora->tm_mon+1);
    string mes = tmp; //to_string(agora->tm_mon + 1);
    sprintf(tmp, "%04d", agora->tm_year+1900);
    string ano = tmp; // to_string(agora->tm_year + 1900);
    return dia + "/" + mes + "/" + ano;
}

void somaDias(char T[11], char newDate[11], int diasAdd)
{
   time_t resultado = 0;

   int ano = 0, mes = 0, dia = 0;

   if (sscanf(T, "%2d/%2d/%4d", &dia, &mes, &ano) == 3)
   {
       struct tm breakdown;            //= {0};
       breakdown.tm_year = ano - 1900; /* ano desde 1900 */
       breakdown.tm_mon = mes - 1;
       breakdown.tm_mday = dia;
       if ((resultado = mktime(&breakdown)) == (time_t)-1)
       {
           fprintf(stderr, "Erro -> time_t\n");
           return; 
      }
      resultado += (diasAdd * 86400);
      char data[40];
      struct tm *tmData;
      tmData = localtime(&resultado);
      sprintf(data, "%02d/%02d/%04d", tmData->tm_mday, tmData->tm_mon + 1, tmData->tm_year + 1900);
    
      strcpy(newDate,data);
      return;
   }
   else
   {
      fprintf(stderr, "Data invalida\n");
      return;
   }
}


string somaDiasCPP(string data, int dias){
	char novaData[11];
	char datai[11];
	strcpy(datai,data.c_str());
	somaDias(datai, novaData, dias);
	string nd = novaData;
	return nd;
}

string mesExt(int mes){
    string meses[12] = {"janeiro",
    "feveriro",
        "março",
        "abril",
        "maio",
        "junho",
        "julho",
        "agosto",
        "setembro",
        "outubro",
        "novembro",
        "dezembro"
};
    return meses[mes - 1];
}

#endif