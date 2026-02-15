#include <bits/stdc++.h>

using namespace std;

template<typename T> class FlowNetwork {
private:

    vector<vector<int>> g;
    vector<vector<T>> cap;

public:

    FlowNetwork(const vector<vector<int>> &network, const vector<vector<T>> &capacity) : g(network), cap(capacity) {}

    T maxflow(int source, int sink) {

        vector<int> parent(g.size(), -1);

        auto bfs = [&]() -> bool {
            queue<int> q;
            q.push(source);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int son : g[node]) {
                    T c = cap[node][son];
                    if (c <= 0 || parent[son] != -1) { continue; }
                    parent[son] = node;
                    q.push(son);
                }
            }
            return parent[sink] != -1;
        };

        T flow = 0;
        while (bfs()) {
            int node = sink;
            T curr_flow = numeric_limits<T>::max();
            while (node != source) {
                curr_flow = min(curr_flow, cap[parent[node]][node]);
                node = parent[node];
            }
            node = sink;
            flow += curr_flow;
            while (node != source) {
                cap[parent[node]][node] -= curr_flow;
                cap[node][parent[node]] += curr_flow;
                node = parent[node];
            }
            fill(parent.begin(), parent.end(), -1);
        }

        return flow;
    }

};

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<vector<long long>> capacity(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back(y);
        g[y].push_back(x);
        capacity[x][y] += c;
    }

    FlowNetwork<long long> fn(g, capacity);
    cout << fn.maxflow(1, n) << '\n';


    return 0;
}
