#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 2e5+1;
 
int n, q, node_id;
int t[3*NMAX];
int v[NMAX], depth[NMAX];
int sz[NMAX], parent[NMAX];
int id[NMAX], top_node[NMAX];
vector<int> g[NMAX];
 
 
void update(int idx, int num) {
	t[idx += n] = num;
	for(idx /= 2; idx; idx /= 2) {
		t[idx] = max(t[idx<<1], t[idx<<1|1]);
	}
}
 
int query(int l, int r) {
	int x = 0, y = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l&1) { x = max(x, t[l++]); }
		if(r&1) { y = max(y, t[--r]); }
	}
	return max(x, y);
}
 
void dfs1(int node, int par = 0) {
	sz[node] = 1;
	depth[node] = depth[par]+1;
	parent[node] = par;
 
	for(auto son : g[node]) {
		if(son == par) { continue; } 
		dfs1(son, node);
		sz[node] += sz[son];
	}
}
 
void dfs2(int node, int par, int top) {
	id[node] = node_id++;
	top_node[node] = top;
	update(id[node], v[node]);
 
	int heavy_son = 0, heavy_size = 0;
	for(auto son : g[node]) {
		if(son == par) { continue; }
		if(sz[son] > heavy_size) { 
			heavy_size = sz[son];
			heavy_son = son;
		}
	}
	if(heavy_son == 0) { return; }
	dfs2(heavy_son, node, top);
	for(auto son : g[node]) { 
		if(son == par || son == heavy_son) { continue; }
		dfs2(son,  node, son);
	}
}
 
int query_path(int x, int y) {
	int ans = 0;
	while(top_node[x] != top_node[y]) {
		if(depth[top_node[x]] < depth[top_node[y]]) { swap(x, y); }
		ans = max(ans, query(id[top_node[x]], id[x]));
		x = parent[top_node[x]];
	}
	if(depth[x] > depth[y]) { swap(x, y); }
	ans = max(ans, query(id[x], id[y]));
	return ans;
}
 
int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
 
	dfs1(1);
	dfs2(1, 1, 1);
 
	while(q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 1) {
			update(id[x], y);
		} else {
			cout << query_path(x, y) << ' ';
		}
	}
 
 
	return 0;
}
