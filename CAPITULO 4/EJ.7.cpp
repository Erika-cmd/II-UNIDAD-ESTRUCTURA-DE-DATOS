#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int time;
    int type; // +1 para llegada, -1 para salida
    Event(int t, int ty) : time(t), type(ty) {}
};

bool cmp(const Event &a, const Event &b) {
    if (a.time == b.time)
        return a.type > b.type; // Llegadas (+1) antes que salidas (-1) si hay empate
    return a.time < b.time;
}

int maxSimultaneousCustomers(vector<pair<int,int>> &intervals) {
    vector<Event> events;
    for (auto &interval : intervals) {
        events.emplace_back(interval.first, +1);   // llegada
        events.emplace_back(interval.second, -1);  // salida
    }

    sort(events.begin(), events.end(), cmp);

    int current = 0, maxCount = 0;
    for (auto &e : events) {
        current += e.type;
        if (current > maxCount) maxCount = current;
    }
    return maxCount;
}

int main() {
    vector<pair<int,int>> customers = {{1, 5}, {2, 6}, {4, 8}, {5, 7}};
    cout << "Maximo numero de clientes simultaneos: " << maxSimultaneousCustomers(customers) << "\n";
    return 0;
}

