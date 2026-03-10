#include <bits/stdc++.h>
 
using namespace std;
 
class Segtree {
private:
 
	struct Node {
		long long sum, pref, suf, ans;
	};
 
 
	int N;
	const int INF = 1e18;
	vector<int> arr;
	vector<Node> t;
 
	Node combine(const Node& a, const Node& b) {
		Node c;
		c.sum = a.sum + b.sum,
		c.pref = max(a.pref, a.sum + b.pref),
		c.suf = max(b.suf, a.suf + b.sum),
		c.ans = max(max(a.ans, b.ans), a.suf + b.pref);
		return c;
	}
 
	void build(int node, int l, int r) {
		if (l == r) {
			t[node] = {arr[l], arr[l], arr[l], arr[l]};
			return;
		}
		int mid = (l + r) / 2;
		build(2 * node, l, mid);
		build(2 * node + 1, mid + 1, r);
		t[node] = combine(t[2 * node], t[2 * node + 1]);
	}
public:
 
	Segtree(const vector<int>& v) : arr(v), t(4 * v.size()), N(v.size() - 1){
		build(1, 1, N);
	}
 
	Node query(int node, int l, int r, int x, int y) {
		if (r < x || l > y) { return {-INF, - INF, -INF, -INF}; }
		if (x <= l && r <= y) {
			return t[node];
		}
		int mid = (l + r) / 2;
		return combine(query(2 * node, l, mid, x, y),
						query(2 * node + 1, mid + 1, r , x, y));
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
		int x, y;
		cin >> x >> y;
		cout << max(st.query(1, 1, n, x, y).ans, 0LL) << '\n';
	}
 
	return 0;
}
