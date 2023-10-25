#include <iostream>
#include <fstream>
#include <iomanip>
#include "../bibliotecas/myLib.cpp"
using namespace std;

struct Pessoa {
    int id;
    char nome[30];
    int idade;
    float altura;
    char flag;
};

int getId() {
    Pessoa p;
    ifstream f("agenda2.dat", ios::in | ios::binary);

    if (!f.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return -1; 
    }

    f.seekg(0, ios::end);
    f.seekg(-(sizeof(Pessoa)), ios::cur);
    f.read((char *)(&p), sizeof(Pessoa));

    if (f )
    {
        return p.id;
    }
    else
    {
        cerr << "Erro ao ler o registro." << endl;
        return -1; // Ou algum valor que indique erro
    }
}

void cadContato (){
    Pessoa p;
    string n;
    char cont = 's';
    ofstream f;
    f.open("agenda2.dat", ios::app|ios::binary);
    if (!f.is_open()){
        cout << "Erro de abertura de arquivo ";
        return ;
    }
    p.id = getId();
    while (cont == 's'){
        clearscr();
        p.id++;
        acento;
        cout << "Código: " << p.id << endl;
        sacento;
        cout << "Nome: ";
        /*n = leStr();
        strcpy(p.nome, n.c_str());*/
        leStr_c(p.nome, 30);
        cout << "Idade: ";
        cin >> p.idade;
        cout << "Altura: ";
        cin >> p.altura;
        f.write((char *)&p,sizeof(Pessoa));
        cout << endl;
        cout << "Novo cadastro (s/n): ";
        cin >> cont;
        cont = tolower(cont);
    }
    cout << "Fim" << endl;
    f.close();
}


void leContato() {
    ifstream f;
    f.open("agenda2.dat", ios::in|ios::binary);
    Pessoa p;
    clearscr();
    acento;
    cout << "+--------+--------------------------------+------------+------------+" << endl;
    cout << "| Código | Nome                           |  Idade     |  Altura    |" << endl;
    cout << "+--------+--------------------------------+------------+------------+" << endl;
    sacento;
    int linha = 0;
    while (f.read((char *)&p, sizeof(Pessoa)))
    {
        if (p.flag != '*'){
            cout << "| " << setw(6) << p.id
                 << " | " << setw(30) << left << p.nome
                 << " | " << right << setw(10) << p.idade
                 << " | " << right << setw(10) << fixed << setprecision(2) << p.altura
                 << " |" << endl;
            linha++;
            if (linha == 20)
            {
                pausa();
                linha = 0;
            }
        }
    }
    cout << "+--------+--------------------------------+------------+------------+" << endl
         << endl;
    f.close();
    pausa();
}

void excluiContato(){
    fstream f;
    f.open("agenda2.dat", ios::in | ios::out|ios::binary);
    Pessoa p;
    int id;
    char confirma;
    clearscr();
    acento;
    cout <<"Qual o código a ser excluido: (-1 listagem) ";
	sacento;
    cin >> id;
    if (id == -1){
        leContato();
        acento;
        cout <<"Qual o código a ser excluido:  ";sacento;
        cin >> id;
    }
    while (f.read((char *)&p, sizeof(Pessoa)))
    {
        if (p.id == id){
            f.seekg(-1 * sizeof(Pessoa), ios::cur);
            p.flag = '*';
            acento;
            cout << "Nome: " << p.nome <<", será excluido, confirma (s/n): ";
			sacento;
            cin >> confirma;
            confirma = tolower(confirma);
            if (confirma == 's'){
                f.write((char *)&p, sizeof(Pessoa));
                cout << p.nome << ", Excluido com sucesso " << endl;
                pausa();
            }
        }
    }
    f.close();
}


void alteraContato(){
    fstream f;
    f.open("agenda2.dat", ios::in | ios::out|ios::binary);
    Pessoa p;
    int id, campo;
    char confirma;
    clearscr();
    acento;
    cout << "Qual o código a ser alterado: (-1 listagem) ";
	sacento;
    cin >> id;
    if (id == -1){
        leContato();
        acento;
        cout << "Qual o código a ser alterado:  ";
		sacento;
        cin >> id;
    }
    while (f.read((char *)&p, sizeof(Pessoa)))
    {
        if (p.id == id){
            f.seekg(-1 * sizeof(Pessoa), ios::cur);
            cout << "1) Nome:   " << p.nome << endl;
            cout << "2) Idade:  " << p.idade << endl;
            cout << "3) Altura: " << p.altura << endl;
            cout << "digite o numero do campo a ser alterado: ";
            cin >> campo;
            switch (campo)
            {
            case 1:
                cout << "Nome: ";
                leStr_c(p.nome, 30);
                break;
            case 2:
                cout << "Idade: ";
                cin >> p.idade;
                break;
             case 3:
                cout << "Altura: ";
                cin >> p.altura;
                break;
            case 4:
                p.flag = ' ';
            default:
                break;
            }
            acento;
            cout << "Confirma alteração (s/n): ";
			sacento;
            cin >> confirma;
            confirma = tolower(confirma);
            if (confirma == 's'){
                f.write((char *)&p, sizeof(Pessoa));
                cout << p.nome << ", alterado com sucesso " << endl;
                pausa();
            }
        }
    }
    f.close();
}

int main()
{
    int op = 1;
    while(op){
        clearscr();
        cout << "Data: " << dataHoje() << endl
             << endl;
    	acento;
        cout <<"+---------------+" << endl;
        cout << "| 1 - Cadastro  |" << endl;
        cout << "| 2 - Relatório |" << endl;
        cout << "| 3 - Excluir   |" << endl;
        cout << "| 4 - Alteração |" << endl;
        cout << "| 0 - Fim       |" << endl;
        cout << "+---------------+" << endl;
        cout << "Opcao: ";
        sacento;
        cin >> op;
        switch (op)
        {
        case 1:
            cadContato();
            break;
        case 2:
            leContato();
            break;
        case 3:
            excluiContato();
            break;
        case 4:
            alteraContato();
            break;
        default:
            break;
        }
    }
    return 0;
}