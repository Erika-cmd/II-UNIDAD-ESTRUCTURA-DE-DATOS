#include <iostream>
#include <algorithm>
using namespace std;

bool allUnique(int array[], int n) {
    sort(array, array + n);  // Ordenar en O(n log n)
    for (int i = 0; i < n - 1; i++) {
        if (array[i] == array[i + 1]) return false;  // Elementos repetidos juntos
    }
    return true;
}

int main() {
    int array[] = {3, 1, 4, 2, 5};
    int n = sizeof(array) / sizeof(array[0]);

    if (allUnique(array, n))
        cout << "Todos los elementos son únicos\n";
    else
        cout << "Hay elementos repetidos\n";

    return 0;
}

