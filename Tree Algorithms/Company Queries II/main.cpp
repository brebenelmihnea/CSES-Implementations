
#include <bits/stdc++.h>
 
using namespace std;
 
class Tree {
private:
 
    int log_max;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> g;
 
    void dfs(int node, int parent) {
        up[node][0] = parent;
        depth[node] = depth[parent] + 1;
        for (int i = 1; i < log_max; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        for (int son : g[node]) {
            if(son == parent) { continue; }
            dfs(son, node);
        }
    }
 
public:
    Tree(const vector<vector<int>> &tree) : g(tree), log_max(ceil(log2(tree.size()))), depth(tree.size()), up(tree.size(), vector<int>(log_max)) {
        dfs(1, 1);
    }
 
    int jump(int node, int steps) {
        if(steps > g.size() - 1) {  return -1; }
        for (int i = 0; i < log_max; i++) {
            if((1 << i) & steps) {
                node = up[node][i];
            }
        }
        return node;
    }
 
    int query(int x, int y) {
        if (depth[x] < depth[y]) { swap(x, y); }
        x = jump(x, depth[x] - depth[y]);
        if (x == y) { return x; }
        for(int i = log_max - 1; i >= 0; i--) {
            if(up[x][i] != up[y][i]) {
                x = up[x][i];
                y = up[y][i];
            }
        }
        return up[x][0];
    }
};
 
int main() {
 
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> g(n + 1);
 
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
 
    Tree t(g);
 
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << t.query(x, y) << '\n';
    }
 
    return 0;
}
