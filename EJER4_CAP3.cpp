#include <iostream>
#include <cmath>
using namespace std;

void estimateEfficiency(int n) {
    cout << "Input size: " << n << "\nExpected time complexity: ";
    if (n <= 10) cout << "O(n!)\n";
    else if (n <= 20) cout << "O(2^n)\n";
    else if (n <= 500) cout << "O(n^3)\n";
    else if (n <= 5000) cout << "O(n^2)\n";
    else if (n <= 1000000) cout << "O(n log n) or O(n)\n";
    else cout << "O(1) or O(log n)\n";
    
    // Ejemplo cálculo operaciones aproximadas para O(n^2) y O(n log n)
    if (n <= 100000) {
        long long n2 = (long long)n * n;
        double nlogn = n * log2(n);
        cout << "Approx. operations O(n^2): " << n2 << "\n";
        cout << "Approx. operations O(n log n): " << (long long)nlogn << "\n";
    }
}

int main() {
    int inputs[] = {5, 15, 400, 3000, 100000, 5000000};
    for (int n : inputs) {
        estimateEfficiency(n);
        cout << "----\n";
    }
    return 0;
}

