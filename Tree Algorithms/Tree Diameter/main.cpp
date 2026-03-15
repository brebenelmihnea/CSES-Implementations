#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 3e5;
 
int n, last, diameter;
vector<int>  g[NMAX];
bool viz[NMAX];
 
void bfs(int start) {
	queue<int> q;
	q.push(start);
	vector<int> viz(NMAX, 0);
	vector<int> depth(NMAX, 0);
	viz[start] = 1;
 
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(int son : g[node]) {
			if(viz[son]) continue ;
			q.push(son);
			depth[son] = depth[node] + 1;
			viz[son] = 1;
			
			diameter = depth[son];
			last = son;
		}
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
 
	bfs(1);
	bfs(last);
	printf("%d\n", diameter);
	
	return 0;
}
