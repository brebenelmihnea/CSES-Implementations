#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n, a, b;
	cin >> n >> a >> b;
 
	vector<long long> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		pref[i] = pref[i - 1] + val;
	}
 
	long long ans = LLONG_MIN;
	multiset<long long> ms;
 
	for (int i = a; i <= n; i++) {
		if (i > b) {
			ms.erase(ms.find(pref[ i - b - 1]));
		}
		ms.insert(pref[i - a]);
		ans = max(ans, pref[i] - *ms.begin());
	}
 
	cout << ans;
 
 
}
