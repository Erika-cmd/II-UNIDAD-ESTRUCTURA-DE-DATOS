#include <iostream>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n, num;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    deque<int> d;
    stack<int> s;
    queue<int> q;

    cout << "Ingrese " << n << " numeros:\n";
    for (int i = 0; i < n; i++) {
        cin >> num;

        // Deque: par al frente, impar al final
        if (num % 2 == 0)
            d.push_front(num);
        else
            d.push_back(num);

        // Stack y Queue
        s.push(num);
        q.push(num);
    }

    // Mostrar contenido del deque
    cout << "\nContenido del deque:\n";
    for (int x : d)
        cout << x << " ";
    cout << "\n";

    // Vaciar y mostrar el stack (LIFO)
    cout << "\nContenido del stack (LIFO):\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    // Vaciar y mostrar el queue (FIFO)
    cout << "\nContenido del queue (FIFO):\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}


