/*compilar sqlite3 para gerar objeto
gcc -c sqlite3.c
compilar o codigo 
g++ exSQLIte2.cpp sqlite3.o -o exSQLite.exe
o arquivo sqlite.c e sqlite.h e sqlite.o devem estar no mesmo diretorio
ou indicado através do -Ic:/etc.....
*/
#include <iostream>
#include <iomanip>
#include "sqlite3.h"
#include "myLib.cpp"
using namespace std;

void inserir(sqlite3 *db) {
    // inserir
    char *erro;
    string nome, cel;
    int idade;
    clearscr();
    cout << endl
         << endl
         <<"Cadastro de contatos " << endl;
    cout << "Nome: ";
    nome = leStr();
    /*getline(cin, nome);
    if(nome[0]=='\0')
        getline(cin, nome);*/
    cout << "Celular: ";
    getline(cin, cel); // ou cel = leStr();
    cout << "Idade: ";
    cin >> idade;

    char sql_c[200];
    sprintf(sql_c, "INSERT INTO contatos (nome,cel, idade) VALUES ('%s','%s',%d);",
            nome.c_str(), cel.c_str(), idade );
    
    int rc = sqlite3_exec(db, sql_c,NULL, NULL, &erro);
    if (rc != SQLITE_OK){
        cerr << "Erro " << erro << endl;
        return ;
    }
}

void matar (sqlite3 *db){
    char *erro;
        string sql = "DROP TABLE contatos;";
    int rc = sqlite3_exec(db, sql.c_str(),NULL, NULL, &erro);
    if (rc != SQLITE_OK){
        cerr << "Erro " << erro << endl;
        return ;
    }
    exit(-1);
}

void listar(sqlite3 *db){
    sqlite3_stmt *stmt;
    char *erro;
    const unsigned char *nome;
    const unsigned char* cel;
    int idade,id;
    
    int rs = sqlite3_prepare_v2(db, "SELECT * FROM contatos;", -1, &stmt, 0);
    clearscr();
    cout << endl
         << endl
         << "Agenda" << endl;
    cout << "+-----+--------------------------------+------------------+-------+" << endl;
    cout << "| ID  | NOME                           | CELULAR          | IDADE |" << endl;
    cout << "+-----+--------------------------------+------------------+-------+" << endl;
    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        id = sqlite3_column_int(stmt, 0);
        nome = sqlite3_column_text(stmt, 1);
        cel   = sqlite3_column_text(stmt,2);
        idade = sqlite3_column_int(stmt,3);
        cout <<"|"<<setw(4)<<right<<id<<" | "
		<< setw(30) << left << nome << " | " 
        << setw(16) << cel << " | "
		<<setw(3) << idade << "   |"<< endl;
    }
    cout << "+-----+--------------------------------+------------------+-------+" << endl;
}

int consulta(sqlite3 *db, int id){
    sqlite3_stmt *stmt;
    char *erro;
    const unsigned char *nome;
    const unsigned char* cel;
    int idade;
    char sql[200];
    sprintf(sql, "SELECT * FROM contatos WHERE ID = %d;",id);
    int rs = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    rs = sqlite3_step(stmt);
    if (rs == 100){
    id = sqlite3_column_int(stmt, 0);
    nome = sqlite3_column_text(stmt, 1);
    cel = sqlite3_column_text(stmt, 2);
    idade = sqlite3_column_int(stmt, 3);
    cout << "+-----+--------------------------------+------------------+-------+" << endl;
    cout << "| ID  | NOME                           | CELULAR          | IDADE |" << endl;
    cout << "+-----+--------------------------------+------------------+-------+" << endl;
    cout <<"|" <<setw(4) << id << " | " 
		 << setw(30) << left << nome << " | "
         << setw(16) << cel << " | " 
		 << setw(3) << idade<<"   |"<< endl;
    cout << "+-----+--------------------------------+------------------+-------+" << endl;
    } else {
        cout << "ID nao encontrado!" << endl;
        return 0;
    }
    return 1;
}

void alterar (sqlite3 *db){
    char *erro;
    string nome;
    string cel;
    int idade, id;
    char sql_c[200];
    cout << "Qual o codigo do registro a ser alterado: ";
    cin >> id;
    int ok = consulta(db, id);
    if (! ok) return;
    int op;
    cout << "Qual campo sera alterado: 1-nome, 2-celular, 3-idade, 0-cancelar : ";
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "Nome: ";
        nome = leStr();
        sprintf(sql_c, "UPDATE contatos SET NOME = '%s' WHERE ID = %d;",nome.c_str(),id);
        break;
    case 2:
        cout << "Celular: " ;
        cel = leStr();
        sprintf(sql_c, "UPDATE contatos SET CEL = '%s' WHERE ID = %d;",cel.c_str(),id);
        break;
    case 3:
        cout << "Idade: ";
        cin >> idade;
        sprintf(sql_c, "UPDATE contatos SET idade = %d WHERE ID = %d;",idade,id);
        break;
    default:
        cout << "Alteracao cancelada" << endl;
        return;
    }
    int rc = sqlite3_exec(db, sql_c,NULL, NULL, &erro);
    if (rc != SQLITE_OK){
        cerr << "Erro " << erro << endl;
        return ;
    }
    cout << "Dados alterados com sucesso (enter) para continuar ";
}

void excluir (sqlite3 *db){
    char *erro;
    int id;
    cout << "Codigo da exclusao: ";
    cin >> id;
	char sql_c[200];
    sprintf(sql_c, "DELETE FROM contatos WHERE ID = %d;",id);
    int rc = sqlite3_exec(db, sql_c,NULL, NULL, &erro);
    if (rc != SQLITE_OK){
        cerr << "Erro " << erro << endl;
        return ;
    }
}



int main(int argc, char const *argv[])
{
    char *erro;
    sqlite3 *db;
    sqlite3_open("agenda.db", &db);
    int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS contatos (id integer primary key autoincrement, nome varchar(30), cel varchar(20), idade integer)", NULL, NULL, &erro);
    if (rc != SQLITE_OK){
        cerr << "Erro " << erro << endl;
        return -1;
    }

    int op = 1;
    while (op){
        clearscr();
        cout << endl
             << "Eu sou escrito em C++" << endl;
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Listar" << endl;
        cout << "3 - Consultar" << endl;
        cout << "4 - Alterar" << endl;
        cout << "5 - Excluir" << endl;
        cout << "0 - Fim" << endl;
        cout << "Opcao: ";
        cin >> op;
        char cont = 's';
               
        switch (op){
            case 1 :
                while (cont == 's'){ 
                  inserir(db);
                  cout << "Novo cadastro [s/n]: ";
                  cin >> cont;
                }
                break;
            case 2 :
                listar(db);
                pausa();
				break;
            case 3 :
                int id;
                clearscr();
                cout << "Qual o codigo: ";
                cin >> id;
                consulta(db, id);
                pausa();
				break;
            case 4:
                alterar(db);
            	pausa();
                break;
            case 5 :
                excluir(db);
                pausa();
                break;
            case -1:
                matar(db);
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    }
    
    sqlite3_close(db);
    return 0;
}

