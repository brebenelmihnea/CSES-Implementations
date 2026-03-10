#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int NMAX = 2e3;
 
int n, q;
int m[NMAX][NMAX];
 
int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			char c;
			scanf(" %c", &c);
			m[i][j] = m[i-1][j] + m[i][j-1] - m[i-1][j-1] + (c == '*');
		}
	}
	while(q--) {
		int a, b, x, y;
		scanf("%d %d %d %d", &a, &b, &x, &y);
		int ans = m[x][y] - m[a-1][y] - m[x][b-1] + m[a-1][b-1];
		printf("%d\n", ans);
	}
	
	return 0;
}
