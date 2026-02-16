#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	stack<pair<int, int>> st;
	st.push({0, 0});
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		while (!st.empty() && st.top().second >= val) {
			st.pop();
		}
		cout << st.top().first << " ";
		st.push({i, val});
	}
}
