#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 2e5+1;
 
int n, q, timer;
int v[NMAX], st[NMAX], en[NMAX];
vector<vector<int>> g(NMAX);
 
class FenwickTree {
private:
	vector<long long> t;
public:
	void update(int pos, long long diff) {
		for( ; pos < t.size(); pos += pos & - pos) t[pos] += diff;
	}
	long long query(int pos) {
		long long ans = 0;
		for( ; pos > 0; pos &= pos-1) ans += t[pos];
		return ans;
	}
	FenwickTree(int sz) {
		t.resize(sz+1);
	}
};
 
void dfs(int node, int parent) {
	st[node] = ++timer;
	for(auto son : g[node])
		if(son != parent) dfs(son, node);
	en[node] = ++timer;
}
 
int main() { 
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	FenwickTree FT(2 * n);
	for(int i = 1; i <= n; i++) {
		FT.update(st[i], v[i]);
		FT.update(en[i], -v[i]);
	}
	while(q--) {
		long long type, p, val;
		cin >> type >> p;
		if(type == 1) {
			cin >> val;
			FT.update(st[p], val - v[p]);
			FT.update(en[p], v[p] - val);
			v[p] = val;
		} else {
			cout << FT.query(st[p]) << '\n';
		}
	}
	
	return 0;
}
