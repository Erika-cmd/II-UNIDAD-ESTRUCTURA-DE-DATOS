#include <iostream>
using namespace std;

bool atacan(int r1, int c1, int r2, int c2) {
    return r1 == r2 || c1 == c2 || (r1 - c1) == (r2 - c2) || (r1 + c1) == (r2 + c2);
}

int q_bruteforce(int n) {
    int count = 0;
    for (int r1 = 0; r1 < n; r1++) {
        for (int c1 = 0; c1 < n; c1++) {
            for (int r2 = 0; r2 < n; r2++) {
                for (int c2 = 0; c2 < n; c2++) {
                    if (r1 == r2 && c1 == c2) continue;
                    if (!atacan(r1, c1, r2, c2)) count++;
                }
            }
        }
    }
    return count / 2;
}

int q_recursive(int n) {
    if (n <= 2) return 0;
    return q_recursive(n-1) + (2*n - 1)*(n*n - 3*(n - 1) - 1) - (n - 1)*(n - 2);
}

int q_closed_form(int n) {
    return (3*n*n*n*n - 10*n*n*n + 9*n*n - 2*n) / 6;
}

int main() {
    int n = 3;
    cout << "O(n^4) brute force: " << q_bruteforce(n) << "\n";
    cout << "O(n) recursive: " << q_recursive(n) << "\n";
    cout << "O(1) closed form: " << q_closed_form(n) << "\n";
    return 0;
}

