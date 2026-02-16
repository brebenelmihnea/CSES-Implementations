#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	const int MOD = 1e9 + 7;
 
	int n;
	cin >> n;
 
	unordered_map<int, int> freq;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		freq[v[i]]++;
	}
 
	long long ans = 1;
	for (auto [num, f] : freq) {
		ans = 1LL * ans * (f + 1) % MOD;
	}
 
	ans = (ans - 1) % MOD;
	
	cout << ans;
 
	return 0;
}
