#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2e5;

int t[NMAX], sz[NMAX], max_component, components;

int get_root(int node) {
    if(t[node] == node) { return node; }
    return get_root(t[node]);
}

void unite(int x, int y) {
    x = get_root(x);
    y = get_root(y);
    if(x == y) { return; }
    if(sz[x] < sz[y]) { swap(x, y); }
    sz[x] += sz[y];
    t[y] = x;
    max_component = max(max_component, sz[x]);
    components--;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        t[i] = i;
        sz[i] = 1;
    }
    components = n;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
        cout << components << ' ' << max_component << '\n';
    }

    return 0;
}
