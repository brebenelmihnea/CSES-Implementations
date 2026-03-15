#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 2e5 + 1;
 
int n, centroid;
vector<int> g[NMAX];
int sz[NMAX];
 
void dfs(int node, int parent) {
	sz[node] = 1;
	int bestSon = 0;
	for(int son : g[node]) {
		if(son == parent) continue;
		dfs(son, node);
		sz[node] += sz[son];
		bestSon = max(bestSon, sz[son]);
	}
	if(max(n - sz[node], bestSon) * 2 <= n) 
		centroid = node;
}
 
int main() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 1);
	cout << centroid << '\n';
	
	return 0;
}
