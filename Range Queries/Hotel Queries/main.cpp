#include <bits/stdc++.h>
 
using namespace std;
 
class Segtree {
private:
	vector<int> t;
 
public:
 
	Segtree(int sz) : t(4 * sz) {}
 
	int op(int x, int y) { return max(x, y); }
 
	void build(int node, int l, int r, const vector<int> &nums) {
		if(l == r) {
			t[node] = nums[l];
			return;
		}
		int mid = (l + r) / 2;
		build(2 * node, l, mid, nums);
		build(2 * node + 1, mid + 1, r, nums);
		t[node] = op(t[2 * node], t[2 * node + 1]);
	}
 
	int find(int node, int l, int r, int val) {
		if(l == r && t[node] >=val) { return l; }
		int mid = (l + r) / 2;
		if(t[2 * node] >= val) { return find(2 * node, l, mid, val); }
		else if(t[2 * node + 1] >= val) { return find(2 * node + 1, mid + 1, r, val); }
		return 0;
	}
 
	void update(int node, int l, int r, int idx, int val) {
		if(l == r) {
			t[node] -= val;
			return;
		}
		int mid = (l + r) / 2;
		if(idx <= mid) { update(2 * node, l, mid, idx, val); }
		else { update(2 * node + 1, mid + 1, r, idx, val); }
		t[node] = op(t[2 * node], t[2 * node + 1]);
	}
};
 
int main() {
 
	int n, m;
	cin >> n >> m;
 
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}
 
	Segtree sg(n);
	sg.build(1, 1, n, v);
 
	while(m--) {
		int x;
		cin >> x;
		
		int idx = sg.find(1, 1, n, x);
		cout << idx << ' ';
		if(idx) { sg.update(1, 1, n, idx, x); } 
 
	}
 
	return 0;
}
