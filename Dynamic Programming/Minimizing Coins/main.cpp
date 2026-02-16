#include <bits/stdc++.h>
 
using namespace std;
 
const int NoSolution = 1e9;
 
int main() {
	int n, x;
	scanf("%d %d",&n, &x);
	vector<int> coin;
	vector<int> dp(x+1, NoSolution);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		coin.push_back(x);
	}
	for(int i = 0; i < n; i++) {
		for(int j = coin[i]; j <= x; j++) {
			dp[j] = min(dp[j], dp[j-coin[i]] + 1);
		}
	}
	if(dp[x] == NoSolution ) puts("-1");
	else printf("%d\n",dp[x]);
	return 0;
}
