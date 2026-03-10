#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n, q;
	cin >> n >> q;
 
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
 
	vector<tuple<int, int, int>> queries;
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		queries.push_back(make_tuple(l, r, i));
	}
 
	sort(queries.begin(), queries.end());
 
	vector<int>  stk = {n + 1};
	vector<long long> ans(q + 1), s(n + 2), contrib(n + 1);
	for (int i = n; i >= 1; i--) {
		s[i] = s[i + 1] + v[i];
		while (!stk.empty() && v[i] >= v[stk.back()]) {
			stk.pop_back();
		}
		int p = (stk.empty() ? n + 1 : stk.back());
		contrib[i] = contrib[p] + 1LL * v[i] * (p - i);
		stk.push_back(i);
		while (!queries.empty() && get<0>(queries.back()) == i) {
			auto [l, r, idx] = queries.back();
			queries.pop_back();
			int p = *prev(upper_bound(stk.rbegin(), stk.rend(), r));
			ans[idx] = contrib[l] - contrib[p] + 1LL * v[p] * (r - p + 1);
			ans[idx] -= s[l] - s[r + 1];
		}
	}
 
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
 
	return 0;
 
}
 
