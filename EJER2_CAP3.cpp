#include <iostream>
using namespace std;

void f(int n) {
    if (n == 1) {
        cout << "f base case reached (n=1)" << endl;
        return;
    }
    cout << "f called with n = " << n << endl;
    f(n - 1);
}

void g(int n) {
    if (n == 1) {
        cout << "g base case reached (n=1)" << endl;
        return;
    }
    cout << "g called with n = " << n << endl;
    g(n - 1);
    g(n - 1);
}

int main() {
    int n = 5, m = 3;
    int a = 0, b = 0, c;

    cout << "O(1) operations:" << endl;
    a++;
    b++;
    c = a + b;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl << endl;

    cout << "O(n) loop:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << " Loop iteration i = " << i << endl;
    }
    cout << endl;

    cout << "O(n^2) nested loop:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "  i = " << i << ", j = " << j << endl;
        }
    }
    cout << endl;

    cout << "O(n) loop with 3*n iterations:" << endl;
    for (int i = 1; i <= 3 * n; i++) {
        cout << " Loop iteration i = " << i << endl;
    }
    cout << endl;

    cout << "O(n) loop with n+5 iterations:" << endl;
    for (int i = 1; i <= n + 5; i++) {
        cout << " Loop iteration i = " << i << endl;
    }
    cout << endl;

    cout << "O(n) loop incrementing by 2:" << endl;
    for (int i = 1; i <= n; i += 2) {
        cout << " Loop iteration i = " << i << endl;
    }
    cout << endl;

    cout << "O(n^2) triangular nested loop:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "  i = " << i << ", j = " << j << endl;
        }
    }
    cout << endl;

    cout << "Consecutive phases O(n), O(n^2), O(n):" << endl;
    cout << " Phase 1 (O(n)):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "  i = " << i << endl;
    }
    cout << " Phase 2 (O(n^2)):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "  i = " << i << ", j = " << j << endl;
        }
    }
    cout << " Phase 3 (O(n)):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "  i = " << i << endl;
    }
    cout << endl;

    cout << "O(n*m) nested loop:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << "  i = " << i << ", j = " << j << endl;
        }
    }
    cout << endl;

    cout << "Recursive function f (O(n)):" << endl;
    f(n);
    cout << endl;

    cout << "Recursive function g (O(2^n)):" << endl;
    g(n);

    return 0;
}
