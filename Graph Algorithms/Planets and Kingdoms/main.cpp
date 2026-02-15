#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1), rg(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    vector<int> order;
    vector<bool> seen(n + 1, false);
    function<void(int)> dfs = [&](int node) -> void {
        seen[node] = true;
        for (int son : g[node]) {
            if (seen[son]) { continue; }
            dfs(son);
        }
        order.push_back(node);
    };

    int cnt = 0;
    vector<int> id(n + 1, 0);
    function<void(int)> dfs2 = [&](int node) -> void {
        seen[node] = true;
        for (int son : rg[node]) {
            if (seen[son]) { continue; }
            dfs2(son);
        }
        id[node] = cnt;
    };

    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            dfs(i);
        }
    }

    fill(seen.begin(), seen.end(), false);
    reverse(order.begin(), order.end());

    for (int node : order) {
        if (seen[node]) { continue; }
        cnt++;
        dfs2(node);
    }

    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        cout << id[i] << ' ';
    }

    return 0;
}
