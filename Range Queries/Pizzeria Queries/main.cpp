#include <bits/stdc++.h> 
#define ll long long 
 
using namespace std;
 
const int NMAX = 2e5+1;
const ll INF = 1e18;
 
int n, q;
int v[NMAX];
 
class segtree {
private:
    int sign;
    ll  t[3 * NMAX];
public:
    segtree(int a) { sign = a; }
    void build(int node, int l, int r) {
        if(l == r) {
            t[node] += v[l] + sign * l;
            return ;
        }
        int mid = (l + r) >> 1;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        t[node] = min(t[2*node], t[2*node+1]);
    }
    void update(int node, int l, int r, int p) {
        if(l == r) {
            t[node] = v[l] + sign * l;
            return; 
        }
        int mid = (l + r) >> 1;
        if(p <= mid) update(2*node, l, mid, p);
        else update(2*node+1, mid+1, r, p);
        t[node] = min(t[2*node], t[2*node+1]);
    }
    ll query(int node, int l, int r, int x, int y) {
        if(r < x || l > y) return INF;
        if(x <= l && r <= y) return t[node];
        int mid = (l + r) >> 1;
        return min(query(2*node, l, mid, x, y), query(2*node+1, mid+1, r, x, y) );
    }
}sgL(-1), sgR(1);
 
int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) { cin >> v[i]; }
    sgL.build(1, 1, n);
    sgR.build(1, 1, n);
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int p, x; cin >> p >> x;
            v[p] = x;
            sgL.update(1, 1, n, p);
            sgR.update(1, 1, n, p);
        } else {
            int x; cin >> x; 
            cout << min(sgL.query(1, 1, n, 1, x) + x, sgR.query(1, 1, n, x, n) - x) << '\n';
        }
    }
}
