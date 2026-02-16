#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	const int MOD = 1e9 + 7;
 
	int n, m;
	cin >> n >> m;
 
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++) { cin >> v[i]; }
 
	// dp[i][j]= number of ways to build prefix of size i 
	// such that the last element is j
 
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= m; i++) {
		if(v[1] == i || v[1] == 0) {
			dp[1][i] = 1;
		}
	}
 
	auto valid = [](int x, int m) -> bool { return 1 <= x && x <= m; };
 
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(v[i] != 0 && v[i] != j) {
				dp[i][j] = 0;
				continue;
			}
			for(int prev = j - 1; prev <= j + 1; prev++) {
				if(!valid(prev, m)) { continue; }
				dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % MOD;
			}
		}
	}
 
	int ans = 0;
	for(int i = 1; i <= m; i++) { ans = (ans + dp[n][i]) % MOD; }
 
	cout << ans;
 
	return 0;
}
