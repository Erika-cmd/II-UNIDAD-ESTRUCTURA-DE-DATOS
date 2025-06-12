#include <iostream>
#include <vector>
using namespace std;

// Función que verifica si en 'time' unidades se pueden procesar todos los trabajos
bool valid(const vector<int>& p, int k, long long time) {
    long long total = 0;
    for (int pi : p) {
        total += time / pi; // trabajos que puede procesar la máquina i en 'time'
        if (total >= k) return true; // ya es suficiente
    }
    return false;
}

long long find_min_time(const vector<int>& p, int k) {
    long long left = 0;
    long long right = (long long)k * p[0]; // límite superior (usar la máquina más lenta)

    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (valid(p, k, mid)) right = mid;  // mid es válido, buscamos un tiempo menor o igual
        else left = mid + 1;                 // mid no es válido, tiempo insuficiente
    }
    return left;
}

int main() {
    int n = 3;      // número de máquinas
    int k = 8;      // número de trabajos

    vector<int> p = {2, 3, 7}; // tiempos de proceso por trabajo de cada máquina

    long long min_time = find_min_time(p, k);

    cout << "El tiempo mínimo para procesar " << k << " trabajos es: " << min_time << endl;

    return 0;
}

