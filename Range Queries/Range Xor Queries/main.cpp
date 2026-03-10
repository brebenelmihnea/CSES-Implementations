#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n, q;
	cin >> n >> q;
 
	vector<int> pref(n + 1);
	for	(int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		pref[i] = pref[i - 1] ^ val;
	}
 
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << (pref[y] ^ pref[x - 1]) << '\n';
	}
 
}
