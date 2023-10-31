#include "../bibliotecas/mylib.cpp"
#include <iostream>

int main()
{
    string usr;
    string passwd;
    acento;
    cout << "Qual o seu usuário?";
    sacento;
    cin >> usr;
    cout << "Senha ";
    passwd = leSenha();
    cout << "usuario " << usr << "senha " << passwd << endl;

    if (cpfTest("123.456.789.10"))
        cout << "cpf valido" << endl;
    else
        cout << "cpf inválido";
}
