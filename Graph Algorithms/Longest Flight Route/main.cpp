#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 1e5 + 3;
 
int n, m;
bool seen[NMAX];
int dist[NMAX], from[NMAX];
 
vector<int> order;
vector<vector<int>> g, rg;
 
void dfs(int node) {
    seen[node] = true;
    for(int son : g[node]) {
        if(seen[son]) { continue; }
        dfs(son);
    }
    order.push_back(node);
}
 
int main() {
 
    cin >> n >> m;
 
    g.resize(n + 1);
    rg.resize(n + 1);
 
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }
 
    dfs(1);
 
    reverse(order.begin(), order.end());
 
    for(int i = 2; i <= n; i++) {
        dist[i] = INT_MIN;
    }
 
    for(auto node : order) {
        for(auto prev : rg[node]) {
            if(dist[prev] + 1 > dist[node]) {
                dist[node] = dist[prev] + 1;
                from[node] = prev;
            }
        }
    }
 
    if(dist[n] == INT_MIN) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        vector<int> path;
        int node = n;
        while(node != 1) {
            path.push_back(node);
            node = from[node];
        }
        path.push_back(1);
        cout << (int)path.size() << '\n';
        for(int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << ' ';
        }
    }
 
    return 0;
}
