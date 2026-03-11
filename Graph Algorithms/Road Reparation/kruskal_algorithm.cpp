#include <bits/stdc++.h>
 
using namespace std;
 
class DisjointSets {
private:
    vector<int> t, sz;
public:
    DisjointSets(int n) : t(n), sz(n, 1) {
        for(int i = 0; i < n; i++) {
            t[i] = i;
        }
    }
 
    int find(int x) {
        return (t[x] == x ? x : (t[x] = find(t[x])));
    }
 
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) { return false; }
        if(sz[x] > sz[y]) { swap(x, y); }
        sz[y] += sz[x];
        t[x] = y;
        return true;
    }
};
 
int main() {
 
    int n, m;
    cin >> n >> m;
 
    vector<array<int, 3>> edges;
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({--x, --y, w});
    }
 
    sort(edges.begin(), edges.end(), [](const array<int, 3> &a, const array<int, 3> &b) {
        return a[2] < b[2];
    });
 
    int cnt = 0;
    long long ans = 0;
    DisjointSets dsu(n);
    for(auto [x, y, w] : edges) {
        if(dsu.unite(x, y)) {
            ans += w;
            cnt++;
        }
    }
 
    if(cnt == n - 1) { cout << ans; }
    else { cout << "IMPOSSIBLE"; }
 
    return 0;
}
