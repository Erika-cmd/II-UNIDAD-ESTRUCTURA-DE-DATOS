#include <iostream>
using namespace std;

int main() {
    int arr[] = {6, 3, 8, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Algoritmo de inserción
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Mostrar resultado
    cout << "Arreglo ordenado (Inserción): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

