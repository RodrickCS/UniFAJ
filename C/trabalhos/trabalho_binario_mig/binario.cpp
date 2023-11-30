#include <iostream>
#include <string>
#include <fstream>
#include "myLib.cpp"
using namespace std;

struct Ficha
{
    int id;
    char nome[30];
    char rua[30];
    char bairro[30];
    char cidade[30];
    char estado[30];
    char cep[9];
    char celular[30];
    char email[30];
    char cpf[14];
    char rg[12];
    char flag;
};

struct Usuario
{
    string user;
    string senha;
};

bool login(string user, string senha)
{
    ifstream f("usuarios.txt");

    Usuario usuarios[10];

    int i = 0;
    while (f >> usuarios[i].user >> usuarios[i].senha)
    {
        i++;
    }

    bool user_valido = false;
    bool senha_valida = false;
    for (int i = 0; i < 10; i++)
    {
        if (usuarios[i].user == user)
        {
            user_valido = true;
            if (usuarios[i].senha == senha)
            {
                senha_valida = true;
                break;
            }
        }
    }

    if (!user_valido)
    {
        cout << "User invalido." << endl;
    }
    else if (!senha_valida)
    {
        cout << "Senha incorreta." << endl;
    }
    else
    {
        return true;
    }

    return false;
}

void pesquisarFicha()
{
    Ficha fi;
    char cpf[12]; 
    clearscr();
    acento;
    cout << "CPF: ";
    sacento;
    cin >> cpf; 

    ifstream f("teste.dat", ios::in | ios::binary);

    if (!f.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    bool encontrado = false;

    while (f.read((char *)(&fi), sizeof(Ficha)))
    {
        if (strcmp(fi.cpf, cpf) == 0)
        {
            cout << "Codigo: " << fi.id << endl;
            cout << "Nome: " << fi.nome << endl;
            cout << "Rua: " << fi.rua << endl;
            cout << "Bairro: " << fi.bairro << endl;
            cout << "Cidade: " << fi.cidade << endl;
            cout << "Estado: " << fi.estado << endl;
            cout << "CEP: " << fi.cep << endl;
            cout << "Celular: " << fi.celular << endl;
            cout << "Email: " << fi.email << endl;
            cout << "CPF: " << fi.cpf << endl;
            cout << "RG: " << fi.rg << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "CPF não encontrado." << endl;
    }

    f.close();
    pausa();
    clearscr();
}

void lerFicha()
{
    ifstream f;
    f.open("teste.dat", ios::in | ios::binary);
    Ficha fi;
    clearscr();
    acento;
    cout << "+--------+--------------------------------------+----------------------------+-----------------------------+-------------------------+" << endl;
    cout << "| Codigo |                Nome                  |         Estado             |            CPF              |           RG            |" << endl;
    cout << "+--------+--------------------------------------+----------------------------+-----------------------------+-------------------------+" << endl;

    sacento;
    int linha = 0;
    while (f.read((char *)&fi, sizeof(Ficha)))
    {
        if (fi.flag != '*')
        {
            cout << "| " << setw(6) << fi.id
                 << " | " << setw(36) << left << fi.nome
                 << " | " << right << setw(26) << fi.estado
                 << " | " << right << setw(27) << fi.cpf
                 << " | " << right << setw(23) << fi.rg
                 << " |" << endl;
            linha++;
            if (linha == 20)
            {
                pausa();
                linha = 0;
            }
        }
    }
    cout << "+--------+--------------------------------------+----------------------------+-----------------------------+-------------------------+" << endl
         << endl;
    f.close();
    pausa();
}

void alterarFicha()
{
    fstream f;
    f.open("teste.dat", ios::in | ios::out | ios::binary);

    if (!f.is_open())
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    Ficha fi;
    int id, campo;
    char confirma;
    clearscr();
    acento;
    cout << "Qual o código a ser alterado: (-1 listagem) ";
    sacento;
    cin >> id;

    if (id == -1)
    {
        lerFicha();
        acento;
        cout << "Qual o código a ser alterado:  ";
        sacento;
        cin >> id;
    }

    while (f.read((char *)&fi, sizeof(Ficha)))
    {
        if (fi.id == id)
        {
            
           f.seekp(f.tellp() - static_cast<std::streamoff>(sizeof(Ficha)));
            cout << "1) Nome:   " << fi.nome << endl;
            cout << "2) Estado:  " << fi.estado << endl;
            cout << "3) CPF: " << fi.cpf << endl;
            cout << "4) RG: " << fi.rg << endl;
            cout << "Digite o número do campo a ser alterado: ";
            cin >> campo;

            switch (campo)
            {
            case 1:
                cout << "Nome: ";
                leStr_c(fi.nome, 30);
                break;
            case 2:
                cout << "Estado: ";
                leStr_c(fi.estado, 30);
                break;
            case 3:
                cout << "CPF: ";
                leStr_c(fi.cpf, 14);
                break;
            case 4:
                cout << "RG: ";
                leStr_c(fi.rg, 12);
                break;
            case 5:
                fi.flag = ' ';
                break;
            default:
                break;
            }

            acento;
            cout << "Confirma alteração (s/n): ";
            sacento;
            cin >> confirma;
            confirma = tolower(confirma);

            if (confirma == 's')
            {
                f.write((char *)&fi, sizeof(Ficha));
                cout << fi.nome << ", alterado com sucesso " << endl;
                pausa();
            }
        }
    }

    cout << "Registro não encontrado." << endl;

    f.close();
}

void excluirFicha()
{
    fstream f;
    f.open("teste.dat", ios::in | ios::out | ios::binary);
    Ficha fi;
    int id;
    char confirma;
    clearscr();
    acento;
    cout << "Qual o código a ser excluido: (-1 listagem) ";
    sacento;
    cin >> id;
    if (id == -1)
    {
        lerFicha();
        cout << "Qual o código a ser excluido:  ";
        sacento;
        cin >> id;
    }
    while (f.read((char *)&fi, sizeof(Ficha)))
    {
        if (fi.id == id)
        {
            f.seekg(-1 * sizeof(Ficha), ios::cur);
            fi.flag = '*';
            acento;
            cout << "Nome: " << fi.nome << ", será excluido, confirma (s/n): ";
            sacento;
            cin >> confirma;
            confirma = tolower(confirma);
            if (confirma == 's')
            {
                f.write((char *)&fi, sizeof(Ficha));
                cout << fi.nome << ", Excluido com sucesso " << endl;
                pausa();
            }
        }
    }
    f.close();
}

int getId()
{
    Ficha fi;
    ifstream f("teste.dat", ios::in | ios::binary);

    if (!f.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return -1;
    }

    f.seekg(0, ios::end);
    f.seekg(-(static_cast<streampos>(sizeof(Ficha))), ios::cur);
    f.read(reinterpret_cast<char*>(&fi), sizeof(Ficha));

    if (f)
    {
        return fi.id;
    }
    else
    {
        cerr << "Erro ao ler o registro." << endl;
        return -1;
    }
}

void cadastrarFicha()
{
    Ficha fi;
    char cont = 's';
    ofstream f;
    f.open("teste.dat", ios::app | ios::binary);
    if (!f.is_open())
    {
        cout << "Erro na abertura do arquivo";
        return;
    }
    fi.id = getId();
    while (cont == 's')
    {
        clearscr();
        fi.id++;
        acento;
        cout << "Código: " << fi.id << endl;
        sacento;
        cout << "Nome: ";
        leStr_c(fi.nome, 30);
        cout << "Rua: ";
        leStr_c(fi.rua, 30);
        cout << "Bairro: ";
        leStr_c(fi.bairro, 30);
        cout << "Cidade: ";
        leStr_c(fi.cidade, 30);
        cout << "Estado: ";
        leStr_c(fi.estado, 30);
        cout << "CEP: ";
        leStr_c(fi.cep, 9);
        cout << "Celular: ";
        leStr_c(fi.celular, 30);
        cout << "Email: ";
        leStr_c(fi.email, 30);
        cout << "CPF: ";
        leStr_c(fi.cpf, 14);
        cout << "RG: ";
        leStr_c(fi.rg, 12);
        f.write((char *)&fi, sizeof(Ficha));
        cout << endl;
        cout << "Novo cadastro (s/n): ";
        cin >> cont;
        cont = tolower(cont);
    }
    cout << "Fim" << endl;
    f.close();
}

int main()
{
    clearscr();

    string user, senha;
    cout << "User: ";
    cin >> user;
    cout << "Senha: ";
    cin >> senha;

    if (!login(user, senha))
    {
        return 0;
    }

    int op = 1;
    while (op)
    {
        cout << "Data: " << dataHoje() << endl
             << endl;
        acento;
        cout << "+------------------+" << endl;
        cout << "| 1 - Cadastro     |" << endl;
        cout << "| 2 - Relatorio    |" << endl;
        cout << "| 3 - Excluir      |" << endl;
        cout << "| 4 - Alteracao    |" << endl;
        cout << "| 5 - Pesquisa CPF |" << endl;
        cout << "| 0 - Fim          |" << endl;
        cout << "+------------------+" << endl;
        cout << "Opcao: ";
        sacento;
        cin >> op;

        switch (op)
        {
        case 1:
            cadastrarFicha();
            break;
        case 2:
            lerFicha();
            break;
        case 3:
            excluirFicha();
            break;
        case 4:
            alterarFicha();
            break;
        case 5:
            pesquisarFicha();
            break;
        default:
            break;
        }
    }

    return 0;
}