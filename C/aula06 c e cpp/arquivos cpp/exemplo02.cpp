#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream arq;
    arq.open("arcCP001.txt", ios::in);
    string msg;
    while (arq >> msg)
        cout << msg << " ";
    arq.close();
    return 0;
}
