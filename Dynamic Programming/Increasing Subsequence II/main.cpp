#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
private:

	const int MOD = 1e9 + 7;

	vector<int> t;
	int lsb(int val) {
		return val & -val;
	}

public:

	FenwickTree(int n) : t(n + 1) {}

	void update(int idx, int val) {
		for (; idx < t.size(); idx += lsb(idx)) {
			t[idx] = (t[idx] + val) % MOD;
		}
	}

	int query(int idx) {
		int answer = 0;
		for (; idx > 0; idx -= lsb(idx)) {
			answer = (answer + t[idx]) % MOD;
		}
		return answer;
	}
};

int main() {

	const int MOD = 1e9 + 7;

	int n;
	cin >> n;

	map<int, int> m;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		m[v[i]]++;
	}

	int idx = 0;
	for (auto &val : m) {
		val.second = ++idx;
	}

	for (int i = 1; i <= n; i++) {
		v[i] = m[v[i]];
	}

	int answer = 0;
	FenwickTree ft(n);
	for (int i = 1; i <= n; i++) {
		int s = 1 + ft.query(v[i] - 1);
		answer = (answer + s) % MOD;
		ft.update(v[i], s);
	}

	cout << answer << '\n';

	return 0;
}
