#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return true;      // elemento encontrado
        else if (arr[mid] < target)
            left = mid + 1;   // buscar a la derecha
        else
            right = mid - 1;  // buscar a la izquierda
    }
    return false;  // no encontrado
}

int main() {
    int arr[] = {1, 3, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int target = 6;
    
    if (binarySearch(arr, n, target))
        cout << target << " está en el arreglo.\n";
    else
        cout << target << " no está en el arreglo.\n";

    return 0;
}


