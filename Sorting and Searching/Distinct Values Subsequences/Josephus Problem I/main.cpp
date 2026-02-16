#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n;
	cin >> n;
 
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
 
	bool flag = false;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (flag) {
			cout << x << ' ';
		} else {
			q.push(x);
		}
		flag = !flag;
	}
 
	return 0;
}
