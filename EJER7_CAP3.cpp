#include <iostream>
#include <vector>
#include <algorithm> // para max

using namespace std;

int main() {
    vector<int> array = {2, 4, -3, 5, 2}; // Ejemplo de arreglo
    int n = array.size();

    // O(n^3) solución
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            best = max(best, sum);
        }
    }
    cout << "O(n^3) max subarray sum: " << best << "\n";

    // O(n^2) solución
    best = 0;
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            best = max(best, sum);
        }
    }
    cout << "O(n^2) max subarray sum: " << best << "\n";

    // O(n) solución - Kadane's algorithm
    best = 0;
    int sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    cout << "O(n) max subarray sum: " << best << "\n";

    return 0;
}

