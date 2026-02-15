#include <bits/stdc++.h>

using namespace std;

int main() {

    const int MOD = 1e9 + 7;
    const long long INF = 1e18;

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
    }

    vector<bool> seen(n + 1);
    vector<array<long long, 4>> ans(n + 1, {INF, 0, 0, 0});
    auto dijkstra = [&](int start) -> void {
        priority_queue<pair<long long, int>> pq;
        pq.push({0, start});
        ans[start][0] = 0;
        ans[start][1] = 1;
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if (seen[node]) { continue; }
            seen[node] = true;

            for (auto [son, cost] : g[node]) {
                long long d = ans[node][0] + cost;
                if (d == ans[son][0]) {
                    ans[son][1] = (ans[son][1] + ans[node][1]) % MOD;
                    ans[son][2] = min(ans[son][2], ans[node][2] + 1);
                    ans[son][3] = max(ans[son][3], ans[node][3] + 1);
                } else if (d < ans[son][0]) {
                    ans[son][0] = d;
                    ans[son][1] = ans[node][1];
                    ans[son][2] = ans[node][2] + 1;
                    ans[son][3] = ans[node][3] + 1;
                    pq.push({-d, son});
                }
            }
        }
    };

    dijkstra(1);

    cout << ans[n][0] << ' ' << ans[n][1] << ' ' << ans[n][2] << ' ' << ans[n][3];

    return 0;
}
