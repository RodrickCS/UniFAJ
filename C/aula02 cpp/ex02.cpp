#include <iostream>
using namespace std;

int main (){
   char sexo;
   int idade;
   int numero;
   char email[30];

   cout << "Digite o sexo (m/f) ";
   cin >> sexo;

   if(sexo == 'f') {
    cout << "Qual a sua idade ";
    cin >> idade;

    if(idade >= 18 && idade < 30){
        cout << "Digite seu email ";
        cin >> email;
        cout << "Digite seu numero ";
        cin >> numero;
        cout << "email: " << email << " numero: " << numero;
    }
   } else {
    cout << "Entraremos em contato";
   }

    return 0;
}