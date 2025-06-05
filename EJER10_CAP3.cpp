#include <iostream>

// Funci�n Collatz optimizada
int collatz(int n) {
    if ((n & 1) == 0)  // verifica si n es par
        return n >> 1;  // divide entre 2 usando desplazamiento
    else
        return 3 * n + 1;
}

// Funci�n test que suma del 1 a n y muestra el resultado
void test(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    std::cout << "Suma de 1 a " << n << " es " << s << "\n";
}

// Funci�n que suma el n�mero de bits 1 en cada n�mero del 1 a n
int sumaBits(int n) {
    int c = 0;
    for (int i = 1; i <= n; i++) {
        c += __builtin_popcount(i);
    }
    return c;
}

int main() {
    int n = 10;

    std::cout << "Collatz(" << n << ") = " << collatz(n) << "\n";

    test(n);

    std::cout << "Suma de bits en n�meros de 1 a " << n << " = " << sumaBits(n) << "\n";

    return 0;
}

