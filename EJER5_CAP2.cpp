#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Ingresa n (n > 0): ";
    cin >> n;
    if (n <= 0) {
        cout << "n debe ser mayor que 0.\n";
        return 1;
    }
    
    vector<int> permutation;
    for (int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }
    
    do {
        for (size_t i = 0; i < permutation.size(); i++) {
            cout << permutation[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(permutation.begin(), permutation.end()));
    
    return 0;
}

