#include <iostream>
#include <vector>
#include <chrono>

int main() {
    int n;
    std::cout << "Ingresa el tamaño del input n: ";
    std::cin >> n;

    std::vector<int> datos(n, 1);
    long long suma = 0;

    auto inicio = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) suma += datos[i];
    auto fin = std::chrono::high_resolution_clock::now();

    std::chrono::microseconds duracion = 
        std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);

    std::cout << "Tiempo para recorrer arreglo de tamaño n = " << n << ": ";
    std::cout << duracion.count() << " microsegundos\n";

    return 0;
}
