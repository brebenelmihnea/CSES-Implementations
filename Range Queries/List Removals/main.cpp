#include <bits/stdc++.h>
 
using namespace std;
 
class Segtree {
private:
    vector<int> t;
 
public:
 
    Segtree(int sz) : t(4 * sz) {
        for(int i = 1; i <= sz; i++) {
            update(1 , 1, sz, i, 1);
        }
    }
 
    int op(int x, int y) { return x + y; }
 
    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            t[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid) { update(2 * node, l, mid, idx, val); }
        else { update(2 * node + 1, mid + 1, r, idx, val); }
        t[node] = op(t[2 * node], t[2 * node + 1]);
    }
 
    int query(int node, int l, int r, int x, int y) {
        if(x <= l && r <= y) { return t[node]; }
        if(r < x || l > y) { return 0; }
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, x, y) + query(2 * node + 1, mid + 1, r, x, y);
    }
 
};
 
int main() {
 
    int n;
    cin >> n;
 
    vector<int> v(n + 1);
    vector<bool> present(n + 1, true);
 
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
 
    Segtree sg(n);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
 
        int l = 1, r = n, last = 1;
        while(l <= r) {
            int mid = (l + r) / 2, m = sg.query(1, 1, n, 1, mid);
            if(x < m) {
                r = mid - 1;
            } else if(x > m) {
                l = mid + 1;
            } else {
                if(present[mid]) { last = mid; break; }
                else { r = mid - 1; }
            }
        }
        present[last] = false;
        sg.update(1, 1, n, last, 0);
        cout << v[last] << ' ';
    }
 
    return 0;
}
