#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 8, 2, 9, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Mostrar arreglo original
    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Bubble Sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Mostrar arreglo ordenado
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

