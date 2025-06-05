#include <iostream>
using namespace std;

int main() {
    int n = 7;                // tamaño del arreglo
    int a[8] = {3, 5, 2, 8, 6, 7, 4}; // arreglo con espacio extra para la versión con centinela
    int x = 6;                // valor a buscar

    // Versión 1: sin break
    bool ok1 = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) ok1 = true;
    }
    cout << "Version 1 (sin break): " << (ok1 ? "Encontrado" : "No encontrado") << "\n";

    // Versión 2: con break
    bool ok2 = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            ok2 = true;
            break;
        }
    }
    cout << "Version 2 (con break): " << (ok2 ? "Encontrado" : "No encontrado") << "\n";

    // Versión 3: con centinela
    a[n] = x; // centinela
    int i = 0;
    while (a[i] != x) {
        i++;
    }
    bool ok3 = (i < n);
    cout << "Version 3 (con centinela): " << (ok3 ? "Encontrado" : "No encontrado") << "\n";

    return 0;
}
