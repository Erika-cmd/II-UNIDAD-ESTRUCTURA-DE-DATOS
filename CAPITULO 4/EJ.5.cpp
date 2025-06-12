#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point &p) const {
        return (x == p.x) ? (y < p.y) : (x < p.x);
    }
};

bool comp(string a, string b) {
    return (a.size() == b.size()) ? (a < b) : (a.size() < b.size());
}

int main() {
    // Ordenar vector<int> ascendente
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    sort(v.begin(), v.end());
    for (int x : v) cout << x << " ";
    cout << "\n"; // Salida: 2 3 3 4 5 5 8

    // Ordenar vector<int> descendente
    sort(v.rbegin(), v.rend());
    for (int x : v) cout << x << " ";
    cout << "\n"; // Salida: 8 5 5 4 3 3 2

    // Ordenar arreglo
    int a[] = {4, 2, 5, 3, 5, 8, 3};
    int n = 7;
    sort(a, a + n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    // Ordenar string
    string s = "monkey";
    sort(s.begin(), s.end());
    cout << s << "\n"; // Salida: ekmnoy

    // Ordenar vector<pair<int,int>>
    vector<pair<int,int>> vp = {{1,5}, {2,3}, {1,2}};
    sort(vp.begin(), vp.end());
    for (auto &p : vp) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n"; // Salida: (1,2) (1,5) (2,3)

    // Ordenar vector<tuple<int,int,int>>
    vector<tuple<int,int,int>> vt = {{2,1,4}, {1,5,3}, {2,1,3}};
    sort(vt.begin(), vt.end());
    for (auto &t : vt)
        cout << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ") ";
    cout << "\n"; // Salida: (1,5,3) (2,1,3) (2,1,4)

    // Ordenar vector<Point>
    vector<Point> pts = {{1,2}, {2,3}, {1,1}};
    sort(pts.begin(), pts.end());
    for (auto &pt : pts) cout << "(" << pt.x << "," << pt.y << ") ";
    cout << "\n"; // Salida: (1,1) (1,2) (2,3)

    // Ordenar vector<string> con comparación personalizada
    vector<string> vs = {"apple", "pie", "banana", "kiwi"};
    sort(vs.begin(), vs.end(), comp);
    for (auto &str : vs) cout << str << " ";
    cout << "\n"; // Salida: pie kiwi apple banana

    return 0;
}

