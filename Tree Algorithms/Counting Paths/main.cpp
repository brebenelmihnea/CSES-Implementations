#include <bits/stdc++.h>
 
using namespace std;
 
const int LOGMAX = 20;
const int NMAX = 2e5 + 3;
 
int n, q, timer;
int id[NMAX], depth[NMAX], pref[NMAX];
int up[NMAX][LOGMAX];
vector<vector<int>> g;
 
void dfs(int node, int parent) {
	id[node] = ++timer;
	depth[node] = depth[parent] + 1;
	up[node][0] = parent;
	for (int i = 1; i < LOGMAX; i++) {
		up[node][i] = up[up[node][i - 1]][i - 1];
	}
	for (int son : g[node]) {
		if (son == parent) { continue; }
		dfs(son, node);
	}
}
 
int query(int x, int  y) {
	if (depth[x] < depth[y]) { swap(x, y); }
	int diff = depth[x] - depth[y];
	for (int i = LOGMAX - 1; i >= 0; i--) {
		if (diff & (1 << i)) {
			x = up[x][i];
		}
	}
	if (x == y) { return x; }
	for (int i = LOGMAX - 1; i >= 0; i--) {
		if (up[x][i] != up[y][i]) {
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}
 
void dfs2(int node, int parent) {
	for (int son : g[node]) {
		if (son == parent) { continue; }
		dfs2(son, node);
		pref[node] += pref[son];
	}
}
 
int main() {
 
	cin >> n >> q;
 
	g.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
 
	dfs(1, 0);
 
	while (q--) {
		int x, y;
		cin >> x >> y;
		int lca = query(x, y);
		pref[x] += 1;
		pref[y] += 1;
		pref[lca] -= 1;
		if (lca != 1) {
			pref[up[lca][0]] -= 1;
		}
	}
 
	dfs2(1, 0);
 
	for (int i = 1; i <= n; i++) {
		cout << pref[i] << ' ';
	}
 
	return 0;
}
