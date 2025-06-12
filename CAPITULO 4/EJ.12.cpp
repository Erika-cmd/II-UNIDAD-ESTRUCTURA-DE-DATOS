#include <iostream>
#include <vector>
using namespace std;

// Funci�n que verifica si en 'time' unidades se pueden procesar todos los trabajos
bool valid(const vector<int>& p, int k, long long time) {
    long long total = 0;
    for (int pi : p) {
        total += time / pi; // trabajos que puede procesar la m�quina i en 'time'
        if (total >= k) return true; // ya es suficiente
    }
    return false;
}

long long find_min_time(const vector<int>& p, int k) {
    long long left = 0;
    long long right = (long long)k * p[0]; // l�mite superior (usar la m�quina m�s lenta)

    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (valid(p, k, mid)) right = mid;  // mid es v�lido, buscamos un tiempo menor o igual
        else left = mid + 1;                 // mid no es v�lido, tiempo insuficiente
    }
    return left;
}

int main() {
    int n = 3;      // n�mero de m�quinas
    int k = 8;      // n�mero de trabajos

    vector<int> p = {2, 3, 7}; // tiempos de proceso por trabajo de cada m�quina

    long long min_time = find_min_time(p, k);

    cout << "El tiempo m�nimo para procesar " << k << " trabajos es: " << min_time << endl;

    return 0;
}

