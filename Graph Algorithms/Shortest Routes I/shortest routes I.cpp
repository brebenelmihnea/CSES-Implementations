#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 1;
const long long INF = 1e18;

int n, m;
long long dist[NMAX];
vector<pair<int, int>> g[NMAX];

void dijkstra(int start) {
    priority_queue<pair<long long, int>> pq;
    pq.push({0, start});
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if(-d != dist[node]) { continue; }
        for(auto [son, w] : g[node]) {
            if(dist[node] + w < dist[son]) {
                dist[son] = dist[node] + w;
                pq.push({-dist[son], son});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }

    dijkstra(1);

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }

    return 0;
}
