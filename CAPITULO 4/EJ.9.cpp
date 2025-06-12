#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    char name;
    int duration, deadline;
};

bool cmpDuration(const Task &a, const Task &b) {
    return a.duration < b.duration;  // Ordenar por duración ascendente
}

int main() {
    vector<Task> tasks = {
        {'A', 4, 2},
        {'B', 3, 10},
        {'C', 2, 8},
        {'D', 4, 15}
    };

    // Ordenar tareas por duración
    sort(tasks.begin(), tasks.end(), cmpDuration);

    int currentTime = 0;
    int totalScore = 0;

    cout << "Orden optimo para realizar tareas:\n";
    for (auto &task : tasks) {
        currentTime += task.duration;
        int score = task.deadline - currentTime;
        totalScore += score;
        cout << "Tarea " << task.name << ": finaliza en t=" << currentTime << ", puntos=" << score << "\n";
    }
    cout << "Puntaje total maximo: " << totalScore << "\n";

    return 0;
}

