#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 3e5;
 
int n;
int ans[NMAX];
 
vector<int> g[NMAX];
set<int> colors[NMAX];
 
void process_colors(int node, int parent) {
	for(int son : g[node]) {
		if(son == parent) continue;
		process_colors(son, node);
		if(colors[node].size() < colors[son].size()) {
			swap(colors[node], colors[son]);
		}
		for(int elem : colors[son])
			colors[node].insert(elem);
	}
	ans[node] = colors[node].size();
}
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int c;
		scanf("%d", &c);
		colors[i].insert(c);
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	process_colors(1, 1);
	for(int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}
