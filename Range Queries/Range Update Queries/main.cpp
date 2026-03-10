#include <bits/stdc++.h> 
#define ll long long 
 
using namespace std;
 
const int NMAX = 2e5+1;
 
int n, q;
int v[NMAX];
 
class segtree {
private:
    ll  t[3 * NMAX];
public:
    void update(int node, int l, int r, int x, int y, int num) {
        if(x <= l && r <= y) {
            t[node] += num;
            return ;
        }
        if(r < x || l > y) return ;
        int mid = (l + r) >> 1;
        update(2*node, l, mid, x, y, num);
        update(2*node+1, mid+1, r, x, y, num); 
    }
    ll query(int node, int l, int r, int p) {
        if(l == r) { return t[node]; }
        if(p < l || r < p) return 0;
        int mid = (l + r) >> 1;
        if(p <= mid) return t[node] + query(2*node, l, mid, p);
        else return t[node] + query(2*node+1, mid+1, r, p); 
    }
}sg;
 
int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int x, y, u;
            cin >> x >> y >> u;
            sg.update(1, 1, n, x, y, u);
        } else {
            int x; cin >> x;
            cout << v[x] + sg.query(1, 1, n, x) << '\n'; 
        }
    }
}
