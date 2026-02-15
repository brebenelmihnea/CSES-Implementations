#include <bits/stdc++.h>

using namespace std;

class DisjointSets {
private:
    vector<int> t;
public:
    DisjointSets(int n) : t(n + 1) {
        for (int i = 1; i <= n; i++) {
            t[i] = i;
        }
    }
    int get_root(int x) {
        if (x == t[x]) { return x; }
        return t[x] = get_root(t[x]);
    }
    void unite(int x, int y) {
        x = get_root(x), y = get_root(y);
        if (x == y) { return; }
        t[x] = y;
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    DisjointSets dsu(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }

    int cnt = 0;
    vector<int> ans;
    vector<bool> seen(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int root = dsu.get_root(i);
        if (!seen[root]) {
            seen[root] = true;
            ans.push_back(root);
        }
    }

    cout << ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }

    return 0;
}
