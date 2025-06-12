#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    // Encontrar el valor máximo en el arreglo
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    // Crear array de conteo (bookkeeping)
    vector<int> count(maxVal + 1, 0);

    // Contar ocurrencias
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Reconstruir el arreglo ordenado
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]-- > 0)
            arr[index++] = i;
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    countingSort(arr, n);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

