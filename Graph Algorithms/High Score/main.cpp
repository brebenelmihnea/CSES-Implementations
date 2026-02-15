#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
void dfs_rev(int node, const vector<vector<pair<int, int>>>& graph, vector<bool>& reach) {
    reach[node] = true;
    for (auto [son, w] : graph[node]) {
        if (!reach[son]) {
            dfs_rev(son, graph, reach);
        }
    }
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    const long long INF = 1e18;
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, int>>> g(n + 1), rg(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        rg[y].push_back({x, c});
    }
 
    // Find all nodes that can reach node n
    // We only care about cycles involving these nodes.
 
    vector<bool> can_reach_n(n + 1, false);
    dfs_rev(n, rg, can_reach_n);
 
    // SPFA - Shortest Path Finding Algorithm
	
    vector<long long> dist(n + 1, -INF);
    vector<int> cnt(n + 1, 0);
    vector<bool> in_queue(n + 1, false);
    queue<int> q;
 
    // Start from node 1
    dist[1] = 0;
    q.push(1);
    in_queue[1] = true;
 
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        in_queue[node] = false;
 
        for (auto [son, w] : g[node]) {
            // If son can't reah n, any path through son is not important to the answer
            // Ignoring these nodes helps to avoid getting stuck in cycles that can't reach node n
            if (!can_reach_n[son]) { continue; }
            // Relaxation
            if (dist[node] + w > dist[son]) {
                dist[son] = dist[node] + w;
                if(!in_queue[son]) {
                    q.push(son);
                    in_queue[son] = true;
                    if(++cnt[son] > n) {
                        cout << "-1\n";
                        return 0;
                    }
                }
            }
        }
    }
 
    cout << dist[n] << '\n';
	
    return 0;
}
