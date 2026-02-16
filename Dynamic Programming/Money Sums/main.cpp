#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXVAL = 1e5;
 
bool dp[MAXVAL];
 
int main() {
	int n;
	scanf("%d",&n);
	vector<int> coin;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		coin.push_back(x);
	}
	dp[0] = 1;
	vector<int> sol;
	for(int i = 0; i < coin.size(); i++) {
		for(int j = MAXVAL; j >= coin[i]; j--) {
			if(!dp[j] && dp[j-coin[i]]) sol.push_back(j);
			dp[j] = dp[j] | dp[j-coin[i]];
		}
	}
	sort(sol.begin(),sol.end());
	printf("%d\n",(int)sol.size());
	for(int i = 0; i < sol.size(); i++)
		printf("%d ", sol[i]);
	puts("");
	
	return 0;
}
