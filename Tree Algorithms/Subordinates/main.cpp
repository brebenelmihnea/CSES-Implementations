#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 3e5;
int n;
int sz[NMAX];
 
vector<vector<int> >v(NMAX);
 
void dfs(int nod) {
	if(v[nod].size() == 0) {
		sz[nod] = 0;
		return ;
	}
	for(auto child : v[nod]) {
		dfs(child);
		sz[nod] += sz[child];
	}
	sz[nod] += (int)v[nod].size();
}
 
int main() {
	scanf("%d",&n);
	for(int i = 2; i <= n; i++) {
		int parrent;
		scanf("%d",&parrent);
		v[parrent].push_back(i);
	}
	dfs(1);
	for(int i = 1; i <= n; i++) {
		printf("%d ",sz[i] );
	}
	printf("\n");
 
	return 0;
}
