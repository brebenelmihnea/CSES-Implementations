#include <iostream>
 
using namespace std;
 
const int MAXN = 5003;
 
string a, b;
 
int dp[MAXN + 5][MAXN + 5];
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
 
 
	cin >> a >> b;
 
	int n = (int)a.size();
	int m = (int)b.size();
 
	for (int i = 1; i <= n; i++) { dp[i][0] = i; }
	for (int j = 1; j <= m; j++) { dp[0][j] = j; }
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min(dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]),
						   min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
		}
	}
 
	cout << dp[n][m];
 
	return 0;
}
