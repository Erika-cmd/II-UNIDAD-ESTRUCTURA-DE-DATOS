#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, x;
    vector<int> valores;

    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    cout << "Ingrese " << n << " enteros:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        valores.push_back(x);
    }

    // Cola de prioridad por defecto (máximos primero)
    priority_queue<int> maxQueue;
    for (int val : valores) {
        maxQueue.push(val);
    }

    cout << "\nElementos extraídos de maxQueue (máximos primero):\n";
    while (!maxQueue.empty()) {
        cout << maxQueue.top() << " ";
        maxQueue.pop();
    }

    // Cola de prioridad que devuelve mínimos
    priority_queue<int, vector<int>, greater<int>> minQueue;
    for (int val : valores) {
        minQueue.push(val);
    }

    cout << "\n\nElementos extraídos de minQueue (mínimos primero):\n";
    while (!minQueue.empty()) {
        cout << minQueue.top() << " ";
        minQueue.pop();
    }

    return 0;
}


