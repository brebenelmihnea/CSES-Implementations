
#include <bits/stdc++.h>
 
using namespace std;
 
class segtree {
private:
 
	struct Node {
		long long sum, pref, suff, ans;
	};
 
	vector<Node> t;
 
	void pull(int node) {
		t[node].sum = t[2*node].sum + t[2*node+1].sum;
		t[node].pref = max(t[2*node].pref, t[2*node].sum + t[2*node+1].pref);
		t[node].suff = max(t[2*node+1].suff, t[2*node+1].sum + t[2*node].suff);
		t[node].ans = max(t[2*node].suff + t[2*node+1].pref, max(t[2*node].ans, t[2*node+1].ans));
	}
 
public:
	segtree(int sz) : t(4 * sz) {}
 
	void build(int node, int left, int right, const vector<int> &vals) {
		if (left == right) {
			t[node].sum = t[node].pref = t[node].suff = t[node].ans = vals[left];
			return;
		}
		int mid = (left + right) / 2;
		build(2 * node, left, mid, vals);
		build(2 * node + 1, mid + 1, right, vals);
		pull(node);
	}
 
	void update(int node, int left, int right, int idx, int val) {
		if (left == right) {
			t[node].sum = t[node].pref = t[node].suff = t[node].ans = val;
			return;
		}
		int mid = (left + right) / 2;
		if (idx <= mid) update(2 * node, left, mid, idx, val);
		else update(2 * node + 1, mid + 1, right, idx, val);
		pull(node);
	}
 
	long long query() {
		return max(0LL, t[1].ans);
	}
};
 
int main() {
 
	int n, q;
	cin >> n >> q;
 
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
 
	segtree sg(n);
	sg.build(1, 1, n, v);
 
	while (q--) {
		int idx, val;
		cin >> idx >> val;
		sg.update(1, 1, n, idx, val);
		cout << sg.query() << '\n';
	}
 
	return 0;
}
