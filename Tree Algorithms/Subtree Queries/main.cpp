#include <bits/stdc++.h>
#define ll long long 
 
using namespace std;
 
const int NMAX = 2e5+1;
 
int n, q, timer;
int st[NMAX], en[NMAX], num[NMAX];
vector<int> g[NMAX];
 
void dfs(int node, int parent) {
    st[node] = ++timer;
    for(auto son : g[node])
        if(son != parent)
            dfs(son, node);
    en[node] = timer;
}
 
class segtree {
private:
    long long t[3 * NMAX];
public:
    void update(int node, int l, int r, int p, int val) {
        if(l == r) {
            t[node] = val;
            return ;
        }
        int mid = (l + r) >> 1;
        if(p <= mid) update(2*node, l, mid, p, val);
        else update(2*node+1, mid+1, r, p, val);
        t[node] = t[2*node] + t[2*node+1];
    }
    ll query(int node, int l, int r, int x, int y) {
        if(r < x || l > y) return 0;
        if(x <= l && r <= y) return t[node];
        int mid = (l + r) >> 1;
        return query(2*node, l, mid, x, y) + query(2*node+1, mid+1, r, x, y);
    }
} sg;
 
int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> num[i];
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++) sg.update(1, 1, n,  st[i], num[i]);
    while(q--) {
        int type, x, y;
        cin >> type ;
        if(type == 1) {
            cin >> x >> y;
            sg.update(1, 1, n, st[x], y);
        } else {
            cin >> x; 
            cout << sg.query(1, 1, n, st[x], en[x]) << '\n';
        }
    }
 
    return 0;
}
