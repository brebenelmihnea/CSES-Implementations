
#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 3e5;
 
int n;
int firstmax[NMAX];
int secondmax[NMAX];
int path[NMAX];
vector<int> g[NMAX];
 
void dfs(int node, int parent) {
	firstmax[node] = secondmax[node] = 0;
	for(int son : g[node]) {
		if(son == parent) continue;
		dfs(son, node);
		if(firstmax[son] + 1 > firstmax[node]) {
			secondmax[node] = firstmax[node];
			firstmax[node] = firstmax[son] + 1;
			path[node] = son;
		} else if(firstmax[son] + 1 > secondmax[node]) {
			secondmax[node] = firstmax[son] + 1;
		}
	}
}
 
void dfs2(int node, int parent) {
	for(int son : g[node]) {
		if(son == parent) continue ;
		if(path[node] == son) {
			if(firstmax[son] < secondmax[node] + 1) {
				secondmax[son] = firstmax[son];
				firstmax[son] = secondmax[node] + 1;
				path[son] = node;
			} else {
				secondmax[son] = max(secondmax[son], secondmax[node] + 1);
			}
		} else {
			secondmax[son] = firstmax[son];
			firstmax[son] = firstmax[node] + 1;
			path[son] = node;
		}
		dfs2(son, node);
	}
}
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(1, 1);
	dfs2(1, 1);
	for(int i = 1; i <= n; i++) {
		printf("%d ", firstmax[i]);
	}
	printf("\n");
	
	return 0;
}
