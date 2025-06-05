#include <iostream>
using namespace std;

// Ejemplo simple: contar operaciones en un ciclo que va de 1 a n
void exampleLinear(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count++;  // O(1) operación repetida n veces
    }
    cout << "Linear example count: " << count << endl;
    // Aquí: O(n), O(n), T(n)
}

// Ejemplo con operación constante
void exampleConstant(int n) {
    int count = 0;
    count++; // Solo una operación
    cout << "Constant example count: " << count << endl;
    // Aquí: O(1), O(1), T(1)
}

// Ejemplo con cota superior más grande (pero no ajustada)
void exampleMisleading(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count++;  // O(n)
    }
    cout << "Misleading example count (claimed O(n^2)): " << count << endl;
    // Técnicamente O(n^2) es correcto porque n^2 > n, pero no es ajustado ni preciso
}

int main() {
    int n = 10;

    exampleConstant(n);
    exampleLinear(n);
    exampleMisleading(n);

    cout << "The first is T(1), the second is T(n), the third is also O(n^2) but better described as T(n)." << endl;
    return 0;
}

