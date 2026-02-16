#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	long long ans = 0;
	map<int, int> freq;
	for (int l = 1, r = 1; r <= n; r++) {
		freq[v[r]]++;
		while (freq[v[r]] > 1 && l < r) {
			freq[v[l++]]--;
		}
		ans += r - l + 1;
	}

	cout << ans;

	return 0;
}
