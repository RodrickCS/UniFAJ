#include <iostream>
using namespace std;

int main() {
    float v[4];
    float media = 0;
    int i;

    v[0] = 101;
    v[1] = 102;
    v[2] = 9;
    v[3] = 50;

    for ( i = 0; i < 4; i++) {
        media = media + v[i];
    }
    media = media / 4;
    cout << media;
    return 0;
}