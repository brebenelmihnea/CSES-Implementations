#include <bits/stdc++.h>

using namespace std;

int cycle_start = -1, cycle_end = -1;

vector<int> state, parent;
vector<vector<int>> g;

bool dfs(int node) {
    state[node] = 1;
    for (int son : g[node]) {
        if (state[son] == 1) {
            cycle_end = node;
            cycle_start = son;
            return true;
        }
        if (state[son] == 0) {
            parent[son] = node;
            if (dfs(son)) { return true; }
        }
    }
    state[node] = 2;
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    parent.resize(n + 1);
    state.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        if (state[i] == 0 && dfs(i)) {
            break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int node = cycle_end; node != cycle_start; node = parent[node]) {
            cycle.push_back(node);
        }

        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << '\n';
        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] << ' ';
        }
    }

    return 0;
}
