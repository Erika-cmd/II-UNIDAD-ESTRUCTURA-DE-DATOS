#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, valor;
    string clave;
    map<string, int> m;

    cout << "Ingrese la cantidad de pares (clave valor): ";
    cin >> n;

    cout << "Ingrese los " << n << " pares:\n";
    for (int i = 0; i < n; i++) {
        cout << "Clave (string): ";
        cin >> clave;
        cout << "Valor (int): ";
        cin >> valor;
        m[clave] = valor;
    }

    // Consultar una clave específica
    cout << "\nIngrese una clave para consultar su valor: ";
    cin >> clave;

    // Mostrar el valor (esto también la añade con valor 0 si no existe)
    cout << "Valor asociado a \"" << clave << "\": " << m[clave] << "\n";

    // Verificar existencia con count
    if (m.count(clave)) {
        cout << "La clave \"" << clave << "\" existe en el mapa.\n";
    } else {
        cout << "La clave \"" << clave << "\" NO existe en el mapa.\n";
    }

    // Mostrar todos los pares clave-valor
    cout << "\nContenido completo del mapa:\n";
    for (auto x : m) {
        cout << x.first << " => " << x.second << "\n";
    }

    return 0;
}


