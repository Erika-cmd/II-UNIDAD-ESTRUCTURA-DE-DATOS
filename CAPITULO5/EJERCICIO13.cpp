#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void experimento_prioridad_vs_multiset(int n) {
    vector<int> A(n), B(n);
    for (int& x : A) x = rand();
    for (int& x : B) x = rand();

    cout << "\n=== Tamaño de entrada: " << n << " ===\n";

    // 1. Multiset
    auto start = high_resolution_clock::now();
    multiset<int> ms(A.begin(), A.end());
    for (int x : B) {
        ms.erase(ms.begin()); // Eliminar el menor
        ms.insert(x);         // Insertar nuevo elemento
    }
    auto end = high_resolution_clock::now();
    cout << "Tiempo (multiset): " << duration<double>(end - start).count() << " s\n";

    // 2. Priority Queue (min-heap con trick)
    start = high_resolution_clock::now();
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
    for (int x : B) {
        pq.pop();      // Eliminar el menor
        pq.push(x);    // Insertar nuevo
    }
    end = high_resolution_clock::now();
    cout << "Tiempo (priority_queue): " << duration<double>(end - start).count() << " s\n";
}

int main() {
    srand(time(0));
    for (int n : {1000000, 2000000, 4000000})
        experimento_prioridad_vs_multiset(n);
    return 0;
}


