
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int NMAX = 3e5;
 
int n;
ll ans[NMAX];
ll dp[NMAX];
vector<int> g[NMAX];
 
void dfs(int node, int parent, int depth) {
	ans[1] += depth;
	dp[node] = 1;
	for(int son : g[node]) {
		if(son == parent) continue ;
		dfs(son, node, depth+1);
		dp[node] += dp[son];
	}
}
 
void dfs2(int node, int parent) {
	for(int son : g[node]) {
		if(son == parent) continue;
		ans[son] = ans[node] + n - 2 * dp[son];
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
	
	dfs(1, 1, 0);
	dfs2(1, 1);
 
	for(int i = 1; i <= n; i++)
		printf("%lli ", ans[i]);
	printf("\n");
	
	return 0;
}
