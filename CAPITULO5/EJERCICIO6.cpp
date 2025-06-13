#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int n, num, x, y;
    multiset<int> ms;

    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    cout << "Ingrese " << n << " numeros (pueden repetirse):\n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        ms.insert(num);
    }

    // Mostrar cu�ntas veces aparece cada n�mero
    map<int, int> frecuencias;
    for (int val : ms) {
        frecuencias[val]++;
    }

    cout << "\nFrecuencia de cada n�mero:\n";
    for (auto [valor, frecuencia] : frecuencias) {
        cout << valor << " aparece " << frecuencia << " veces\n";
    }

    // Mostrar el valor m�nimo y m�ximo
    if (!ms.empty()) {
        auto min = *ms.begin();
        auto max = *ms.rbegin();
        cout << "\nValor m�nimo: " << min << "\n";
        cout << "Valor m�ximo: " << max << "\n";
    }

    // Eliminar una copia de x
    cout << "\nIngrese un n�mero para eliminar una sola copia: ";
    cin >> x;
    auto it = ms.find(x);
    if (it != ms.end()) {
        ms.erase(it);
        cout << "Una copia de " << x << " fue eliminada.\n";
    } else {
        cout << x << " no se encuentra en el multiset.\n";
    }

    // Eliminar todas las copias de y
    cout << "\nIngrese un n�mero para eliminar todas sus copias: ";
    cin >> y;
    int borrados = ms.erase(y);
    cout << "Se eliminaron " << borrados << " copias de " << y << ".\n";

    // Mostrar multiset actualizado
    cout << "\nMultiset actualizado:\n";
    for (int val : ms) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}


