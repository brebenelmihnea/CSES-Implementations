#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 10;
const int MMAX = 1001;
const int MOD = 1e9 + 7;
 
int n, m;
int dp[MMAX][1<<NMAX];
 
void fill_column(int j, int i, int mask, int next_mask) {
	if(i == n) {
		dp[j+1][next_mask] = (dp[j+1][next_mask] + dp[j][mask]) % MOD;
		return;
	}
 
	// If the next cell is occupied by a tile
	// Otherwise put a horizontal tile or a vertical tile
 
	if(mask & (1<<i)) {
		fill_column(j, i+1, mask, next_mask);
	} else { 
		// Put the horizontal tile and update next_mask because the tile goes into the next column
		fill_column(j, i+1, mask, next_mask | (1<<i));
		if(i + 1 < n && !(mask & (1 << (i+1))) ) {
			fill_column(j, i+2, mask, next_mask);
		}
	}
}
 
int main() {
	cin >> n >> m;
 
	dp[0][0] = 1;
	for(int j = 0; j < m; j++) {
		for(int mask = 0; mask < (1<<n); mask++) {
			if(dp[j][mask] > 0) {
				fill_column(j, 0, mask, 0);
			}
		}
	}
 
	cout << dp[m][0];
 
	return 0;
}
