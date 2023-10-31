#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream arq;
    arq.open("arcCP001.txt", ios::out);
    arq << "C++ foi criado em 1979 por Bjorne Stroustrup" << endl;
    arq.close();
}
