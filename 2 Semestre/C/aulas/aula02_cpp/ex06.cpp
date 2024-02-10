#include <iostream>
using namespace std;

int main() {
    float n1[3], n2[3];
    int i;
    for(i = 0; i < 3; i++) {
        cout << "nota da p1 ";
        cin >> n1[i];
        cout << "nota da p2 ";
        cin >> n2[i];
    }
    // float m = (n1 + n2) / 2;
    for ( i = 0; i < 3; i++) {
        cout << "Media" << (n1[i] + n2[i] / 2) << endl
        
    }
    return 0;
}