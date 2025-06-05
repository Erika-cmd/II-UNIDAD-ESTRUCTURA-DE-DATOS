#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 5328; // 00000000000000000001010011010000

    // Imprimir la representación binaria de x, 32 bits
    for (int k = 31; k >= 0; k--) {
        if (x & (1 << k)) cout << "1";
        else cout << "0";
    }
    cout << "\n";

    return 0;
}
