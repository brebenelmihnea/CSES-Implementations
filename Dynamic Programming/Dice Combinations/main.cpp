#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 1e6;
const int MOD = 1e9 + 7;
int dp[NMAX];
 
int main() {
	int n;
	scanf("%d",&n);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1 ;j <= 6 && j <= i; j++) {
			dp[i] = (dp[i] + dp[i - j]) % MOD;
		}
	}
	printf("%d\n",dp[n] );
	return 0;
}
