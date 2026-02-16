#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
	int n;
	scanf("%d",&n);
	vector<int> dp(n+1, 1e9);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		int aux = i;
		while(aux) {
			int cif = aux % 10;
			if(i-cif >= 0) dp[i] = min(dp[i], dp[i-cif] + 1);
			aux /= 10;
		}
	}
	printf("%d\n", dp[n]);
	
	return 0;
}
