#include <iostream>
using namespace std;

// M�todo 1: b�squeda binaria tradicional
bool binarySearch1(int array[], int n, int x) {
    int a = 0, b = n - 1;
    while (a <= b) {
        int k = (a + b) / 2;
        if (array[k] == x) return true;
        if (array[k] < x) a = k + 1;
        else b = k - 1;
    }
    return false;
}

// M�todo 2: b�squeda binaria con saltos
bool binarySearch2(int array[], int n, int x) {
    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k + b < n && array[k + b] <= x) {
            k += b;
        }
    }
    return (array[k] == x);
}

int main() {
    int n, x;
    cout << "Ingrese tama�o del arreglo ordenado: ";
    cin >> n;
    int* array = new int[n];
    
    cout << "Ingrese " << n << " elementos ordenados: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    cout << "Ingrese el valor a buscar: ";
    cin >> x;
    
    bool found1 = binarySearch1(array, n, x);
    bool found2 = binarySearch2(array, n, x);
    
    cout << "M�todo 1: " << (found1 ? "Encontrado" : "No encontrado") << endl;
    cout << "M�todo 2: " << (found2 ? "Encontrado" : "No encontrado") << endl;
    
    delete[] array;
    return 0;
}

