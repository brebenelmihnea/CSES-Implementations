#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        g[x].emplace_back(y, cost);
        g[y].emplace_back(x, cost);
    }

    vector<bool> seen(n + 1);
    priority_queue<pair<long long, int>> pq;
    auto process = [&](int node) {
        seen[node] = true;
        for (auto [son, w] : g[node]) {
            if (seen[son]) { continue; }
            pq.emplace(-w, son);
        }
    };

    process(1);

    int num_taken = 0;
    long long mst_cost = 0;
    while (!pq.empty() && num_taken < n) {
        int cost = -pq.top().first, node = pq.top().second;
        pq.pop();
        if (seen[node]) { continue; }
        mst_cost += cost;
        num_taken++;
        process(node);
    }

    if (num_taken == n - 1) {
        cout << mst_cost;
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
