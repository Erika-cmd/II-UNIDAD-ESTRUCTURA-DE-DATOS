#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// Definición de indexed_set
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    indexed_set;

int main() {
    indexed_set s;
    
    // Insertamos elementos
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);

    // Mostrar los elementos del conjunto ordenado
    cout << "Elementos del conjunto ordenado:\n";
    for (auto x : s) {
        cout << x << " ";
    }
    cout << "\n";

    // find_by_order(k): Devuelve el k-ésimo elemento (0-indexado)
    cout << "Elemento en la posición 0: " << *s.find_by_order(0) << "\n"; // 2
    cout << "Elemento en la posición 2: " << *s.find_by_order(2) << "\n"; // 7

    // order_of_key(x): Devuelve cuántos elementos son menores que x
    cout << "Elementos menores que 7: " << s.order_of_key(7) << "\n"; // 2
    cout << "Elementos menores que 8: " << s.order_of_key(8) << "\n"; // 3
    cout << "Elementos menores que 10: " << s.order_of_key(10) << "\n"; // 4

    return 0;
}


