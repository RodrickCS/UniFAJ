#include <iostream>
using namespace std;

int main (){
   float nota1, nota2, media;

   cout << "insira sua 1 nota: ";
   cin >> nota1;
   cout << "insira sua 2 nota: ";
   cin >> nota2;

    media = (nota1 + nota2) / 2;

    if (media < 6) {

        cout << "nota da sub: ";
        if(nota1 > nota2) {
            cin >> nota2;
        } else {
            cin >> nota1;
        }

        media = (nota1 + nota2) / 2;

        if(media >= 6) {
            cout << "Sua nova media eh " << media << " aprovado";
        } else {
            cout << "Sua nova media eh " << media << " reprovado";
        }

    } else {
        cout << "Aprovado " << media;
    }
    return 0;
}