
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int NMAX = 3e5;
const int LOGMAX = 18;
 
int n, q;
int v[NMAX][LOGMAX];
 
// Binary Lifting
 
int jump(int x, int d) {
	for(int i = 0; i <= LOGMAX; i++)
		if((d>>i) & 1)
			x = v[x][i];
	return x ? x : -1;
}
 
int main() {
	scanf("%d %d", &n, &q);
	for(int i = 2; i <= n; i++) {
		scanf("%d", &v[i][0]);
	}
 
	for(int j = 1; j < LOGMAX; j++) {
		for(int i = 1; i <= n; i++) {
			v[i][j] = v[v[i][j-1]][j-1];
		}
	}
	while(q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", jump(x, y));
	}
	
	return 0;
}
