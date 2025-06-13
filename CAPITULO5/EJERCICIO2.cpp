#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int num;

    cout << "Ingrese numeros enteros (ingrese -1 para terminar):\n";

    while (true) {
        cin >> num;
        if (num == -1) break;
        v.push_back(num);
    }

    cout << "\nElementos ingresados:\n";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";

    if (!v.empty()) {
        cout << "\nEliminando el ultimo elemento...\n";
        v.pop_back();

        cout << "Elementos despues de pop_back:\n";
        for (int x : v) {
            cout << x << " ";
        }
        cout << "\n";

        if (!v.empty()) {
            cout << "\nUltimo elemento restante: " << v.back() << "\n";
        } else {
            cout << "\nEl vector ahora esta vacio.\n";
        }
    } else {
        cout << "\nNo se ingresaron elementos validos.\n";
    }

    return 0;
}

