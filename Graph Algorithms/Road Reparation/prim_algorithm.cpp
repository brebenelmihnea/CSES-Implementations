#include <bits/stdc++.h>

using namespace std;

class Graph {
private:

    int n;
    vector<vector<pair<int, int>>> g;

public:

    Graph(const int &sz, const vector<vector<pair<int, int>>> &graph) : n(sz), g(graph) {}

    // Prim's algorithm
    void get_mst() {
        vector<bool> taken(n + 1, false);
        priority_queue<pair<int, int>> pq;
        pq.push({0, 1});

        auto process = [&](int node) -> void {
            taken[node] = true;
            for (auto [son, cost] : g[node]) {
                if (!taken[son]) {
                    pq.push({-cost, son});
                }
            }
        };

        int nodes_taken = 0;
        long long mst_cost = 0;
        while (!pq.empty()) {
            int cost = -pq.top().first, node = pq.top().second;
            pq.pop();
            if (taken[node]) { continue; } // Skip already processed nodes
            mst_cost += cost;
            process(node);
            if (++nodes_taken == n) { break; } // Optimization
        }

        if (nodes_taken < n) { cout << "IMPOSSIBLE" << '\n'; }
        else { cout << mst_cost << '\n'; }
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        g[x].push_back({y, cost});
        g[y].push_back({x, cost});
    }

    Graph graph(n, g);
    graph.get_mst();

    return 0;
}