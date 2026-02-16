#include <bits/stdc++.h>
 
using namespace std;
 
const int XMAX = 2e6;
const int NMAX = 103;
const int MOD = 1e9 + 7;
 
int n, x;
int dp[XMAX], coin[NMAX];
 
int main() {
	scanf("%d %d", &n, &x);
	for(int i = 1; i <= n; i++)
		scanf("%d", &coin[i]);
	dp[0] = 1;
	for(int w = 1; w <= x; w++) {
		for(int i = 1; i <= n; i++)
			if(w >= coin[i]) {
				dp[w] += dp[w - coin[i]];
				dp[w] %= MOD;
			}
	}
	printf("%d\n", dp[x]);
	
	
	return 0;
}
