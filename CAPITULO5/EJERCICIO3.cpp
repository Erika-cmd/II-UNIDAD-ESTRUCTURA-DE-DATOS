#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    vector<int> v(n);
    cout << "Ingrese " << n << " numeros enteros:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Ordenar el vector
    sort(v.begin(), v.end());

    // Eliminar duplicados
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << "\nVector ordenado sin duplicados:\n";
    for (int num : v) {
        cout << num << " ";
    }
    cout << "\n";

    // Buscar con lower_bound y upper_bound
    cout << "\nIngrese un valor para buscar (x): ";
    cin >> x;

    auto it_lower = lower_bound(v.begin(), v.end(), x);
    auto it_upper = upper_bound(v.begin(), v.end(), x);

    if (it_lower != v.end()) {
        cout << "lower_bound (= " << x << "): " << *it_lower << "\n";
    } else {
        cout << "No hay elemento = " << x << "\n";
    }

    if (it_upper != v.end()) {
        cout << "upper_bound (> " << x << "): " << *it_upper << "\n";
    } else {
        cout << "No hay elemento > " << x << "\n";
    }

    return 0;
}


