#include <iostream>
#include <string>
using namespace std;

string crypt(string t) {
    int i, tam = t.length();

    for (i = 0; i < tam; i++) {
        t[i] = t[i] + 1;
    } 
    return t;
}

string decrypt(string t){
     int i, tam = t.length();

    for (i = 0; i < tam; i++) {
        t[i] = t[i] - 1;
    } 
    return t;
}

int main () {
    
    string criptografado = crypt("Nome");

    string descriptografado = decrypt(criptografado);

    cout << "Criptografado: " << criptografado << endl;
    cout << "Descriptografado: " << descriptografado;

    return 0;
    
}