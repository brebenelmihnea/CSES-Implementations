#include <bits/stdc++.h>
 
using namespace std;
 
class FenwickTree{
private:
	vector<int> t;
 
	int lsb(int val) { return val & -val; }
 
public:
 
	FenwickTree(int sz) : t(sz) {} 
 
	void update(int idx, int val) {
		for(; idx < t.size(); idx += lsb(idx)) {
			t[idx] += val;
		}
	}
 
	int query(int idx) {
		int sum = 0;
		for(; idx >= 1; idx -= lsb(idx)) {
			sum += t[idx];
		}
		return sum;
	}
 
};
 
struct event {
	int id, l, r, sign;	
};
 
int main() {
 
	int n, q;
	cin >> n >> q;
 
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}
 
	vector<int> vals;
	for(int i = 1; i < v.size(); i++) {
		vals.push_back(v[i]);
	}
 
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
 
 
	vector<vector<event>> events(n + 1);
	for(int i = 1; i <= q; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int low = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
		int high = upper_bound(vals.begin(), vals.end(), y) - vals.begin();
 
		if(low >= high) { continue; }
 
		events[b].push_back({i, low, high, 1});
		if(a > 1) { events[a - 1].push_back({i, low, high, -1}); }
	}
 
	FenwickTree ft(n + 1);
	vector<int> ans(q + 1, 0);
	for(int i = 1; i <= n; i++) {
		int val = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin() + 1;
		ft.update(val, 1);
		for(auto &e : events[i]) {
			int cnt = ft.query(e.r) - ft.query(e.l);
			ans[e.id] += e.sign * cnt;
		}
	}
 
	for(int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
 
	return 0;
}
