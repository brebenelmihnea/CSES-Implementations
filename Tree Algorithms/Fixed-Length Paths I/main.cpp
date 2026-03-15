#include <bits/stdc++.h>
 
using namespace std;
 
class Graph {
private:
 
    int chain_length, max_depth = 0;
    long long number_chains = 0;
    vector<int> sz, cnt;
    vector<bool> seen;
    vector<vector<int>> adj;
 
 public:
 
    Graph(int V, int lg) : adj(V + 1), sz(V + 1), seen(V + 1), cnt(V + 1), chain_length(lg) {
        cnt[0] = 1;
    }
 
    void add_edges(int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    int get_subtree_size(int node, int parent) {
        sz[node] = 1;
        for (int son : adj[node]) {
            if (seen[son] || son == parent) { continue; }
            sz[node] += get_subtree_size(son, node);
        }
        return sz[node];
    }
 
    int get_centroid(int desired, int node, int parent) {
        for (int son : adj[node]) {
            if (!seen[son] && son != parent && sz[son] >= desired) {
                return get_centroid(desired, son, node);
            }
        }
        return node;
    }
 
    void solve(int node, int parent, bool filling, int depth = 1) {
        if (depth > chain_length) { return; }
        max_depth = max(max_depth, depth);
        if (filling) { cnt[depth]++; }
        else { number_chains += cnt[chain_length - depth]; }
        for (int son : adj[node]) {
            if (seen[son] || son == parent) { continue; }
            solve(son, node, filling, depth + 1);
        }
    }
 
    void centroid_decompoosition(int node = 1) {
        int centroid = get_centroid(get_subtree_size(node, -1) / 2, node, 0);
        seen[centroid] = true;
        max_depth = 0;
        for (int son : adj[centroid]) {
            if (seen[son]) { continue; }
            solve(son, centroid, false);
            solve(son, centroid, true);
        }
        fill(cnt.begin() + 1, cnt.begin() + max_depth + 1, 0);
        for (int son : adj[centroid]) {
            if (seen[son]) { continue; }
            centroid_decompoosition(son);
        }
    }
 
    long long number_of_chain() { return number_chains; }
};
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
 
    Graph g(n, k);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g.add_edges(x, y);
    }
 
    g.centroid_decompoosition();
 
    cout << g.number_of_chain() << endl;
 
    return 0;
}
