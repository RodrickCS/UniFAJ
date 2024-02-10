#include <iostream>
using namespace std;

float calcArea(float r) {
    float area = 3.1416 * r * r;
    return area;
}

int main () {
    float raio, area;

    cout << "Insira o raio: ";
    cin >> raio;

    area = calcArea(raio);
    return 0;
}