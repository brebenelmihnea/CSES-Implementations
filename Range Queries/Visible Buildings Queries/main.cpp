#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	const int LOGMAX = 21;
 
	int n, q;
	cin >> n >> q;
 
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
 
	stack<int> stk;
	vector<vector<int>> up(n + 2, vector<int>(21));
	for (int i = n; i >= 1; i--) {
		while (!stk.empty() && v[stk.top()] <= v[i]) {
			stk.pop();
		}
		up[i][0] = (stk.empty() ? n + 1 : stk.top());
		stk.push(i);
	}
 
	for (int j = 1; j <= LOGMAX; j++) {
		for (int i = 1; i <= n; i++) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
 
	while (q--) {
		int x, y;
		cin >> x >> y;
		int idx = x, steps = 1;
		for (int i = LOGMAX; i >= 0; i--) {
			if (up[idx][i] && up[idx][i] <= y) {
				idx = up[idx][i];
				steps += (1 << i);
			}
		}
		cout << steps << '\n';
	}
 
	return 0;
}
