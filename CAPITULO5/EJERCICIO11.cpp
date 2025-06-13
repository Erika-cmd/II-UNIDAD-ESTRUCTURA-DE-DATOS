#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void run_experiment(int n) {
    vector<int> v(n);
    for (int& x : v) x = rand() % (n / 2);

    cout << "\n=== Tamaño de entrada: " << n << " ===\n";

    // set
    auto start = high_resolution_clock::now();
    set<int> s(v.begin(), v.end());
    auto end = high_resolution_clock::now();
    cout << "Tiempo (set): " << duration<double>(end - start).count() << " s\n";

    // unordered_set
    start = high_resolution_clock::now();
    unordered_set<int> us(v.begin(), v.end());
    end = high_resolution_clock::now();
    cout << "Tiempo (unordered_set): " << duration<double>(end - start).count() << " s\n";

    // sort + contar únicos
    start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    int unicos = 1;
    for (int i = 1; i < n; ++i)
        if (v[i] != v[i-1]) ++unicos;
    end = high_resolution_clock::now();
    cout << "Tiempo (sort): " << duration<double>(end - start).count() << " s\n";

    // map para frecuencia
    start = high_resolution_clock::now();
    map<int, int> m;
    for (int x : v) m[x]++;
    end = high_resolution_clock::now();
    cout << "Tiempo (map): " << duration<double>(end - start).count() << " s\n";

    // unordered_map para frecuencia
    start = high_resolution_clock::now();
    unordered_map<int, int> um;
    for (int x : v) um[x]++;
    end = high_resolution_clock::now();
    cout << "Tiempo (unordered_map): " << duration<double>(end - start).count() << " s\n";

    // arreglo si los valores son pequeños
    if (*max_element(v.begin(), v.end()) < 2000000) {
        vector<int> freq(*max_element(v.begin(), v.end()) + 1, 0);
        start = high_resolution_clock::now();
        for (int x : v) freq[x]++;
        end = high_resolution_clock::now();
        cout << "Tiempo (array): " << duration<double>(end - start).count() << " s\n";
    }
}

int main() {
    srand(time(0));
    for (int n : {1000000, 2000000, 4000000})
        run_experiment(n);
    return 0;
}


