#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int start, end;
};

bool cmp(const Event &a, const Event &b) {
    return a.end < b.end;  // Ordenar por tiempo de finalización ascendente
}

int maxNonOverlappingEvents(vector<Event> &events) {
    sort(events.begin(), events.end(), cmp);

    int count = 0;
    int last_end = -1;

    for (auto &e : events) {
        if (e.start >= last_end) {
            count++;
            last_end = e.end;
        }
    }
    return count;
}

int main() {
    vector<Event> events = {
        {1, 4},
        {2, 3},
        {3, 5},
        {6, 8},
        {5, 7}
    };
    cout << "Maximo numero de eventos sin solapamiento: " << maxNonOverlappingEvents(events) << "\n";
    return 0;
}

