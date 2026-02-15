#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        g[x].push_back({y, cost});
    }

    vector<priority_queue<long long>> dist(n + 1);
    priority_queue<pair<long long, int>> pq;

    pq.push({0, 1});
    dist[1].push(0);

    while (!pq.empty()) {
        long long d = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node].size() == k && d > dist[node].top()) { continue; }

        for (auto [son, w] : g[node]) {
            long long new_d = d + w;
            if (dist[son].size() < k) {
                dist[son].push(new_d);
                pq.push({-new_d, son});
            } else if(new_d < dist[son].top()) {
                dist[son].pop();
                dist[son].push(new_d);
                pq.push({-new_d, son});
            }
        }
    }

    vector<long long> ans;
    while (!dist[n].empty()) {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
