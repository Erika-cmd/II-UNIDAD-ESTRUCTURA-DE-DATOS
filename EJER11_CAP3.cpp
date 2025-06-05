#include <iostream>
using ll = long long;

const ll M = 1000000007;  // ejemplo de módulo para operaciones modulares

int main() {
    const int n = 10;  // tamaño del array y límite para factorial

    // Ejemplo 1: Suma cache-friendly en matriz 2D
    int s = 0;
    int x[n][n];

    // Inicializar matriz para el ejemplo
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = i * n + j;

    // Primera forma: cache-friendly (recorre filas, luego columnas)
    s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += x[i][j];
        }
    }
    std::cout << "Suma cache-friendly: " << s << "\n";

    // Segunda forma: menos cache-friendly (recorre columnas, luego filas)
    s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += x[j][i];
        }
    }
    std::cout << "Suma menos cache-friendly: " << s << "\n";

    // Ejemplo 2: cálculo de factorial modulado - código simple
    ll f = 1;
    for (int i = 1; i <= n; i++) {
        f = (f * i) % M;
    }
    std::cout << "Factorial mod simple: " << f << "\n";

    // Ejemplo 3: cálculo factorial modulado - usando paralelismo manual con dos variables
    ll f1 = 1;
    ll f2 = 1;
    for (int i = 1; i <= n; i += 2) {
        f1 = (f1 * i) % M;
        if (i + 1 <= n) {
            f2 = (f2 * (i + 1)) % M;
        }
    }
    ll f_parallel = (f1 * f2) % M;
    std::cout << "Factorial mod paralelo: " << f_parallel << "\n";

    return 0;
}

