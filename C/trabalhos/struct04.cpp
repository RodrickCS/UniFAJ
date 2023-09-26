#include <iostream>
#include "../aula04 cpp/mylib.cpp"
using namespace std;

typedef struct
{
    int ra;
    float n1, n2;
    string nome;
} ficha;
    
void cadastro(ficha *ff) {
    cout<<"RA: ";
    cin >>ff->ra;
    cout<<"Nome: ";
    ff->nome = leStr();
    cout<<"Nota 1 ";
    cin >>ff->n1;
    cout<<"Nota 2 ";
    cin >> ff->n2;
}

void listagem(ficha *f){
    cout<<"RA "<<f->ra<<" Nome "<<f->nome<<
    " Media = "<<((f->n1 + f->n2) / 2.0)<<endl;
}

int main()
{
    ficha f;
    cadastro(&f);
    listagem(&f);
    return 0;
}