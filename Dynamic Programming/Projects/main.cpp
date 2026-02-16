#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n), p(n);
	map<int,int> m; // Compress the data
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d",&a[i], &b[i], &p[i]);
		b[i]++;
		m[a[i]];
		m[b[i]];
	}
	int poz = 0;
	for(auto &i : m) {
		i.second = poz++;
	}
	vector<vector<pair<int,int>>> v(poz);
	for(int i = 0; i < n; i++) {
		v[m[b[i]]].push_back( {m[a[i]], p[i]} );
	}
	vector<long long> dp(poz, 0);
	for(int i = 0; i < poz; i++) {
		if(i > 0) dp[i] = dp[i-1];
		for(auto j : v[i]) {
			dp[i] = max(dp[i], dp[j.first] + j.second);
		}
	}
	printf("%lli\n",dp[poz-1]);
	
	return 0;
}
