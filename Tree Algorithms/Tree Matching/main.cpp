
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int n;
    cin >> n;
 
    vector<vector<int>> tree(n + 1);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
 
    int cnt = 0;
    vector<bool> taken(n + 1);  
    function<void(int, int)> dfs = [&](int node, int parent) {
        for(int son : tree[node]) {
            if(son == parent) { continue; }
            dfs(son, node);
            if(!taken[node] && !taken[son]) {
                taken[node] = taken[son] = 1;
                cnt++;
            }
        }
    };
 
    dfs(1 , 0);
 
    cout << cnt << '\n';
 
    return 0;
}
