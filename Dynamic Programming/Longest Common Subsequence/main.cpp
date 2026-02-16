#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n, m;
	cin >> n >> m;
 
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
 
	vector<int> b(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
 
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
 
	int i = n, j = m;
	vector<int> arr;
 	while (i && j) {
		if (a[i] == b[j]) {
			arr.push_back(a[i]);
			i--, j--;
		} else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		} else {
			i--;
		}
	}
 
	cout << arr.size() << '\n';
	for (int i = arr.size() - 1; i >= 0; i--) {
		cout << arr[i] << ' ';
	}
 
	return 0;
}
