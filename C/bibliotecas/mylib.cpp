#ifndef _MYLIB_CPP_
#define _MYLIB_CPP_
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

#if defined(__WIN32__) || defined(__NT__)
#include <conio.h>
#endif
#if defined(__linux__) || defined (__linux)
#include <termios.h>
#endif
#if defined (__APPLE__)
//adiciona a biblioteca para ios
#endif

#define acento setlocale(LC_ALL,"")
#define sacento setlocale(LC_ALL,"C")

string leStr(){
    string txt;
    getline(cin,txt);
    if (txt[0] == '\0')
        getline(cin,txt);
    return txt;
}

string leSenha() {
    string senha;
    #ifdef __unix__
    struct termios novo,old;
    tcgetattr(fileno(stdin),&old);
    novo = old;
    novo.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin),TCSAFLUSH,&novo);
    getline(cin,senha);
    if (senha[0] == '\0')
        getline(cin,senha);
    (void)tcsetattr(fileno(stdin),TCSAFLUSH, &old);
    #elif defined(_WIN32) || defined(WIN32)
    int tam = 0;
    char letra;
    bool ok = true;
    do {
        letra = getch();
        senha += letra;
        if (letra == '\b' && tam > 0){
            printf("\b \b");
            senha[tam] = '\0';
            tam --;
        }
        else if (letra == 13){
            senha[tam] = '\0';
            ok = false;
            break;
        }
        else if (letra != '\b'){
            putchar('*');
            tam ++;
        }
       
    } while(ok);
    #endif
    cout << endl;
    return senha;
}


bool cpfTest(string cpf){
    //123.456.789-09 cpf com mascara
    //01234567890123 regua
    //12345678909    cpf sem mascara
    if (cpf.size() != 14) return false;
    string tmp;
    tmp = cpf.substr(0,3)+
          cpf.substr(4,3)+
          cpf.substr(8,3)+
          cpf.substr(12,2);
    int i, soma = 0;
    for (i = 0; i < 9; i++)
        soma += (char2num(tmp[i]) * (i + 1));
    int resto1 = soma % 11;
    if (resto1 == 10) resto1 = 0;
    soma = 0;
    for (i = 1; i < 10 ; i++)
        soma += (char2num(tmp[i]) * i);
    int resto2 = soma % 11;
    if (resto2 == 10) resto2 = 0;
    resto1 = (resto1 * 10) + resto2;
    resto2 = (char2num(tmp[9]) * 10) + char2num(tmp[10]);
    if (resto1 == resto2) return true;
    else                  return false;      
}

// inicio funcoes conversao de base
string inverteStr(string str){
    int i, tam;
    tam = str.size()-1;
    string aux = "";
    for (i = tam; i >= 0; i--)
        aux += str[i];
    return aux;
}

long int bin2dec(string bin){
    int tam = bin.size();
    int n, i;
    long int dec = 0;
    for (i = 0; i < tam; i++){
        n = bin[i] - '0';
        dec += n * (pow(2,tam -1 - i));
    }
    return dec;
}

string dec2bin(long int dec){
    int resto;
    string bin = "";
    while (dec >= 2){
        resto = dec % 2;
        dec = dec / 2;
        bin += resto + '0';
    }
    bin += dec + '0';
    bin = inverteStr(bin);
    return bin;
}

char calcHex(int pos){
    char v_hex[16] = {'0','1','2','3','4','5','6','7','8',
                     '9','A','B','C','D','E','F'};
    //string v_hex = "0123456789ABCDEF"                    
    return v_hex[pos];
}

string dec2hex (long int dec, bool cabecalho = false){
    int resto;
    string hex;
    while(dec > 0){
        resto = dec % 16;
        dec = dec / 16;
        hex += calcHex(resto);
    }
    hex = inverteStr(hex);
    if (cabecalho)
        hex = "0x"+hex;
    return hex;
}

int calcDec(char c){
    string hex = "0123456789ABCDEF";
    c = toupper(c);
    for (int i = 0; i < 17; i++)
        if (hex[i] == c)
            return i;
    return -1;
}

long int hex2dec (string hex){
    if (hex.substr(0,2) == "0x")
        hex = hex.substr(2,hex.size());
    int tam = hex.size();
    int i, dec = 0, pos = tam - 1;
    for (i = 0; i < tam; i++){
        dec += calcDec(hex[i]) * pow(16,pos);
        pos--;
    }
    return dec;
}
// fim conversao de base
#endif