#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, num, x, y;
    set<int> s;

    // Ingreso de datos
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    cout << "Ingrese " << n << " numeros:\n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num); // Inserta (autom�ticamente evita duplicados)
    }

    // Mostrar elementos �nicos en orden
    cout << "\nElementos �nicos en orden ascendente:\n";
    for (int val : s) {
        cout << val << " ";
    }
    cout << "\n";

    // Buscar un n�mero en el set
    cout << "\nIngrese un n�mero para buscar en el set: ";
    cin >> x;
    if (s.find(x) != s.end())
        cout << x << " se encuentra en el set.\n";
    else
        cout << x << " no se encuentra en el set.\n";

    // Eliminar un n�mero
    cout << "\nIngrese un n�mero para eliminar del set: ";
    cin >> y;
    if (s.erase(y))
        cout << y << " fue eliminado del set.\n";
    else
        cout << y << " no se encontraba en el set.\n";

    // Mostrar el set actualizado
    cout << "\nSet actualizado:\n";
    for (int val : s) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}


