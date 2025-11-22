#include <bits/stdc++.h>
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;

    unordered_map<int, vector<int>> stopToBuses;

    // строим карту: остановка -> автобусы
    for (int i = 0; i < routes.size(); i++) {
        for (int stop : routes[i]) {
            stopToBuses[stop].push_back(i);
        }
    }

    queue<pair<int, int>> q; // {bus_id, buses_taken}
    vector<bool> visitedBus(routes.size(), false);
    unordered_set<int> visitedStop;

    // стартуем со всех автобусов, которые проходят через source
    for (int bus : stopToBuses[source]) {
        q.push({bus, 1});
        visitedBus[bus] = true;
    }
    visitedStop.insert(source);

    while (!q.empty()) {
        auto [bus, dist] = q.front();
        q.pop();

        for (int stop : routes[bus]) {
            if (stop == target) return dist;

            if (!visitedStop.count(stop)) {
                visitedStop.insert(stop);

                for (int nextBus : stopToBuses[stop]) {
                    if (!visitedBus[nextBus]) {
                        visitedBus[nextBus] = true;
                        q.push({nextBus, dist + 1});
                    }
                }
            }
        }
    }

    return -1;
}

// --- Парсер ввода формата [[1,2,7],[3,6,7]] ---
vector<vector<int>> parseRoutes(const string& s) {
    vector<vector<int>> routes;
    vector<int> current;
    int num = 0;
    bool inNumber = false;
    bool negative = false;

    for (char c : s) {
        if (c == '-') negative = true;
        else if (isdigit(c)) {
            inNumber = true;
            num = num * 10 + (c - '0');
        }
        else {
            if (inNumber) {
                if (negative) num = -num;
                current.push_back(num);
                num = 0;
                inNumber = false;
                negative = false;
            }
            if (c == ']') {
                if (!current.empty()) {
                    routes.push_back(current);
                    current.clear();
                }
            }
        }
    }

    return routes;
}

int main() {
    string input;
    getline(cin, input);  // читаем [[1,2,7],[3,6,7]]

    vector<vector<int>> routes = parseRoutes(input);

    int source, target;
    cin >> source >> target;

    cout << numBusesToDestination(routes, source, target);
}