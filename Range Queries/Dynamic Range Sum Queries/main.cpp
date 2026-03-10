#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int NMAX = 2e5+1;
 
int n, m;
int v[NMAX];
 
class segtree {
private:
	ll t[3 * NMAX];
public:
	void build(int node, int st, int dr) {
		if(st == dr) {
			t[node] = v[st];
			return ;
		}
		int mid = (st + dr) / 2;
		build(2*node, st, mid);
		build(2*node+1, mid+1, dr);
		t[node] = t[2*node] + t[2*node+1];
	}
	void update(int node, int st, int dr, int poz, int val) {
		if(st == dr) {
			t[node] = val;
			return ;
		}
		int mid = (st + dr) / 2;
		if(poz <= mid) update(2*node, st, mid, poz, val);
		else update(2*node+1, mid+1, dr, poz, val);
		t[node] = t[2*node] + t[2*node+1];
	}
	ll query(int node, int st, int dr, int x, int y) {
		if(dr < x || st > y) 
			return 0;
		if(x <= st && dr <= y)
			return t[node];
		int mid = (st + dr) / 2;
		ll l = query(2*node, st, mid, x, y);
		ll r = query(2*node+1, mid+1, dr, x, y);
		return l + r;
		
	}
}sg;
 
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	sg.build(1, 1, n);
	while(m--) {
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);
		if(op == 1) {
			sg.update(1, 1, n, x, y);
		} else {
			printf("%lli\n", sg.query(1, 1, n, x, y) );
		} 
	}
	
	return 0;
}
