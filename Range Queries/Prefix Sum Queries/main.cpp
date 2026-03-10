#include <bits/stdc++.h>
 
using namespace std;
 
class Segtree {
private:
 
 
	int N;
	struct Node { long long sum, pref; };
	const Node NEUTRAL = {0, 0};
 
	vector<Node> t;
 
public:
 
	Segtree(const vector<int>& vals) : N((int)vals.size() - 1), t(4 * N) {
		build(1, 1, N, vals);
	}
 
	Node merge(const Node& a, const Node& b) {
		return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
	}
 
	void build(int node, int left, int right, const vector<int>& vals) {
		if (left == right) {
			t[node].sum = vals[left];
			t[node].pref = max(0, vals[left]);
			return;
		}
		int mid = (left + right) / 2;
		build(2 * node, left, mid, vals);
		build(2 * node + 1, mid + 1, right, vals);
		t[node] = merge(t[2 * node], t[2 * node + 1]);
	}
 
	void update(int node, int left, int right, int idx, int val) {
		if (left == right) {
			t[node].sum = val;
			t[node].pref = max(0, val);
			return;
		}
		int mid = (left + right) / 2;
		if (idx <= mid) { update(2 * node, left, mid, idx, val); }
		else { update(2 * node + 1, mid + 1, right, idx, val); }
		t[node] = merge(t[2 * node], t[2 * node + 1]);
	}
 
	Node query(int node, int left, int right, int x, int y) {
		if (right < x || y < left) { return NEUTRAL; }
		if (x <= left && right <= y) { return t[node]; }
		int mid = (left + right) / 2;
		Node a = query(2 * node, left, mid, x, y);
		Node b = query(2 * node + 1, mid + 1, right, x, y);
		return merge(a, b);
	}
};
 
int main() {
 
	int n, q;
	cin >> n >> q;
 
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
 
	Segtree st(v);
 
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1) {
			st.update(1, 1, n, x, y);
		} else {
			cout << st.query(1, 1, n, x, y).pref << '\n';
		}
	}
 
	return 0;
}
 
