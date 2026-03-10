#include <bits/stdc++.h>
 
using namespace std;
 
class Segtree {
private:
	vector<int> t;
 
	int op(int x, int y) { return max(x, y); }
 
public:
 
	Segtree(int sz) : t(4 * sz) {}
 
	void build(int node, int l, int r, const vector<int> &vals) {
		if(l == r) {
			t[node] = vals[l];
			return;
		}
		int mid = (l + r) / 2;
		build(2 * node, l, mid, vals);
		build(2 * node + 1, mid + 1, r, vals);
		t[node] = op(t[2 * node], t[2 * node + 1]);
	}
 
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
		if(r < x || l > y) { return 0; }
		if(x <= l && r <= y) { return t[node]; }
		int mid = (l + r) / 2;
		return op(query(2 * node, l, mid, x, y),
				  query(2 * node + 1, mid + 1, r, x, y));
	}
 
};
 
int main() {
 
	int n, q;
	cin >> n >> q;
 
	vector<int> v(n + 1), vals;
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		vals.push_back(v[i]);
	}
 
	struct query { int type, x, y; };
 
	vector<query> queries;
	for(int i = 1; i <= q; i++) {
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 1) { vals.push_back(y); }
		queries.push_back({type, x, y});
	}
 
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
 
	auto compress = [&](int val) {
		return lower_bound(vals.begin(), vals.end(), val) - vals.begin() + 1;
	};
 
	vector<int> p(n + 1), new_v(n + 1);
	vector<set<int>> pos(vals.size() + 1);
	for(int i = 1; i <= n; i++) {
		new_v[i] = compress(v[i]);
		if(!pos[new_v[i]].empty()) {
			p[i]= *pos[new_v[i]].rbegin();
		} else {
			p[i] = 0;
		}
		pos[new_v[i]].insert(i);
	}
 
	Segtree st(n + 1);
	st.build(1, 1, n, p);
 
	// Process queries
	for(auto &[type, x, y] : queries) {
		if(type == 1) {
 
			int k = x, u = compress(y);
			int old_val = new_v[k];
 
			if(old_val == u) { continue; }
 
			// Handle removal of old value
			auto it = pos[old_val].find(k);
 
			int prev_idx = 0;
			if(it != pos[old_val].begin()) { prev_idx = *prev(it); }
 
			int next_idx = 0;
			if(next(it) != pos[old_val].end()) { next_idx = *next(it); }
 
			pos[old_val].erase(it);
 
			// If there was a next occurrence, its previous is now k's previous
			if(next_idx != 0) {
				p[next_idx] = prev_idx;
				st.update(1, 1, n, next_idx, prev_idx);
			}
 
			// Handle insertion of u at k
			new_v[k] = u;
			pos[u].insert(k);
			it = pos[u].find(k);
 
			prev_idx = 0;
			if(it != pos[u].begin()) { prev_idx = *prev(it); }
 
			next_idx = 0;
			if(next(it) != pos[u].end()) { next_idx = *next(it); }
 
			// Update k's previous
			p[k] = prev_idx;
			st.update(1, 1, n, k, prev_idx);
 
			// If there is a next occurrence, its previous becomes k
			if(next_idx != 0) {
				p[next_idx] = k;
				st.update(1, 1, n, next_idx, k);
			}
 
		} else {
			if(st.query(1, 1, n, x, y) < x) { cout << "YES\n"; } 
			else { cout << "NO\n"; }
		}
	}
 
	return 0;
}
