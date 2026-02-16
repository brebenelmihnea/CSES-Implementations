#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	const int MOD = 1e9 + 7;
	const int MAXN = 1e6 + 1;
 
	vector<vector<long long>> dp(MAXN, vector<long long>(2, 0));
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < MAXN; i++) {
		dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][0]) % MOD;
	}
 
	int t;
	cin >> t;
 
	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
	}
 
	return 0;
}
