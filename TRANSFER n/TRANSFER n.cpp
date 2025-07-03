#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Función para insertar elementos en la pila
void insertarEnPila(stack<string>& pila, int n) {
    string elemento;
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el elemento " << i + 1 << " para la pila: ";
        cin >> elemento;
        pila.push(elemento);
    }
}

// Función para insertar elementos en la cola
void insertarEnCola(queue<string>& cola, int n) {
    string elemento;
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el elemento " << i + 1 << " para la cola: ";
        cin >> elemento;
        cola.push(elemento);
    }
}

// Función para transferir elementos de pila a cola
void transferirPilaACola(stack<string>& pila, queue<string>& cola, int n) {
    if (n > pila.size()) {
        cout << "?? Error: Solo hay " << pila.size() << " elementos en la pila. No se puede transferir " << n << "." << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        string elemento = pila.top();
        pila.pop();
        cola.push(elemento);
    }
    cout << "? Se transfirieron " << n << " elementos de la pila a la cola.\n";
}

// Función para transferir elementos de cola a pila
void transferirColaAPila(queue<string>& cola, stack<string>& pila, int n) {
    if (n > cola.size()) {
        cout << "?? Error: Solo hay " << cola.size() << " elementos en la cola. No se puede transferir " << n << "." << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        string elemento = cola.front();
        cola.pop();
        pila.push(elemento);
    }
    cout << "? Se transfirieron " << n << " elementos de la cola a la pila.\n";
}

// Mostrar pila (de arriba hacia abajo)
void mostrarPila(stack<string> pila) {
    cout << "Pila (tope abajo): ";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;
}

// Mostrar cola (frente a final)
void mostrarCola(queue<string> cola) {
    cout << "Cola (frente a final): ";
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
}

int main() {
    stack<string> pila;
    queue<string> cola;
    int n;

    // Insertar en la pila
    cout << "¿Cuántos elementos desea ingresar en la pila? ";
    cin >> n;
    insertarEnPila(pila, n);

    // Insertar en la cola
    cout << "¿Cuántos elementos desea ingresar en la cola? ";
    cin >> n;
    insertarEnCola(cola, n);

    // Transferencia de pila a cola
    cout << "\n¿Cuántos elementos desea transferir de la pila a la cola? ";
    cin >> n;
    transferirPilaACola(pila, cola, n);

    // Transferencia de cola a pila
    cout << "\n¿Cuántos elementos desea transferir de la cola a la pila? ";
    cin >> n;
    transferirColaAPila(cola, pila, n);

    // Mostrar resultados finales
    cout << endl << "--- Estado final ---" << endl;
    mostrarPila(pila);
    mostrarCola(cola);

    return 0;
}


