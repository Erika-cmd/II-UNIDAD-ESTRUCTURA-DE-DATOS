#include <bits/stdc++.h>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>

using namespace std;
using namespace std::chrono;

const int N = 1e6; // Un millón de elementos

int main() {
    vector<int> data(N);
    iota(data.begin(), data.end(), 0); // data = 0, 1, 2, ..., N-1
    shuffle(data.begin(), data.end(), mt19937{random_device{}()});

    // Experimento con unordered_set
    unordered_set<int> uset;
    auto start = high_resolution_clock::now();
    for (int x : data) uset.insert(x);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "unordered_set insert: " << duration.count() << " ms\n";

    start = high_resolution_clock::now();
    for (int x : data) uset.count(x);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "unordered_set search: " << duration.count() << " ms\n";

    // Experimento con set
    set<int> tset;
    start = high_resolution_clock::now();
    for (int x : data) tset.insert(x);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "set insert: " << duration.count() << " ms\n";

    start = high_resolution_clock::now();
    for (int x : data) tset.count(x);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "set search: " << duration.count() << " ms\n";

    // Experimento con unordered_map
    unordered_map<int, int> umap;
    start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) umap[data[i]] = i;
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "unordered_map insert: " << duration.count() << " ms\n";

    start = high_resolution_clock::now();
    for (int x : data) umap[x];
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "unordered_map access: " << duration.count() << " ms\n";

    // Experimento con map
    map<int, int> tmap;
    start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) tmap[data[i]] = i;
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "map insert: " << duration.count() << " ms\n";

    start = high_resolution_clock::now();
    for (int x : data) tmap[x];
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "map access: " << duration.count() << " ms\n";

    return 0;
}


