#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    vector<int> numeros(n); // Creamos un vector de tamaño n

    cout << "Ingrese " << n << " numeros enteros:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> numeros[i];
    }

    int suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += numeros[i];
    }

    cout << "La suma de los elementos es: " << suma << endl;

    return 0;
}

