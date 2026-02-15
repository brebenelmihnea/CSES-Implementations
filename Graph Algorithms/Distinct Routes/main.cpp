#include <bits/stdc++.h>

using namespace std;

template<typename T> class FlowNetwork {
private:

    int n;
    vector<vector<int>> g;
    vector<vector<T>> capacity;

public:

    FlowNetwork(int N, const vector<vector<int>> &network, const vector<vector<int>> &cap) : n(N), g(network), capacity(cap) {}
    
    // Ford-Fulkerson Algorithm
    T max_flow(int source, int sink) {
        T flow = 0;
        vector<int> parent(g.size(), -1);
        auto can_reach_sink = [&]() -> bool {
            queue<int> q;
            q.push(source);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int son : g[node]) {
                    T c = capacity[node][son];
                    if (c <= 0 || parent[son] != -1) { continue; }
                    parent[son] = node;
                    q.push(son);
                }
            }
            return parent[sink] != -1;
        };
        while (can_reach_sink()) {
            int node = sink;
            T curr_flow = numeric_limits<T>::max();
            while (node != source) {
                curr_flow = min(curr_flow, capacity[parent[node]][node]);
                node = parent[node];
            }
            node = sink;
            flow += curr_flow;
            while (node != source) {
                capacity[parent[node]][node] -= curr_flow;
                capacity[node][parent[node]] += curr_flow;
                node = parent[node];
            }
            fill(parent.begin(), parent.end(), -1);
        }
        return flow;
    }

    void print_paths(vector<vector<bool>> original_edge) {
        int distinct_paths = max_flow(1, n);
        cout << distinct_paths << '\n';
        while (distinct_paths--) {
            vector<int> path;
            int node = 1;
            while (node != n) {
                path.push_back(node);
                for (int son : g[node]) {
                    if (original_edge[node][son] && capacity[node][son] == 0) {
                        original_edge[node][son] = false;
                        node = son;
                        break;
                    }
                }
            }
            path.push_back(node);
            cout << path.size() << '\n';
            for (int node : path) { cout << node << ' '; }
            cout << '\n';
        }
    }
};

int main() {

    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> og(n + 1, vector<bool>(n + 1, false)); // Keep track of the original edges
    vector<vector<int>> g(n + 1), capacity(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        capacity[x][y] += 1;
        og[x][y] = true;
    }

    FlowNetwork<int> fn(n, g, capacity);
    fn.print_paths(og);

    return 0;
}
