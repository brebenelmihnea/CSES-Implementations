#include <bits/stdc++.h>
#define ll long long 
 
using namespace std;
 
const int NMAX = 1003;
const int MOD  = 1e9+7;
 
char v[NMAX][NMAX];
ll dp[NMAX][NMAX];
 
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++)
			cin >> v[i][j];
	dp[0][1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(v[i][j] != '*')
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
	cout << dp[n][n] << '\n';
	
	return 0;
}
