#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9+7;
 
int main() {
	int n, x;
	scanf("%d %d",&n, &x);
	vector<int> coin;
	vector<int> dp(x+1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		coin.push_back(x);
	}
	for(int i = 0; i < n; i++) {
		for(int j = coin[i]; j <= x; j++) {
			dp[j] += dp[j - coin[i]];
			dp[j] %= MOD;
		}
	}
	printf("%d\n",dp[x]);
	return 0;
}
